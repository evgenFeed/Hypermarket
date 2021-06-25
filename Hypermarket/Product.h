#pragma once

#include <string>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

class Product
{
public:
	Product(std::string brand, std::string productName, double price, double maxDiscount);
	virtual ~Product() {}

	virtual double		getMaxDiscount() const { return m_maxDiscount; }
	virtual double		getPrice() const { return m_price; }
	virtual std::string getBrand() const { return m_brand; }
	virtual std::string getProductName() const { return m_productName; }

	void setBrand(std::string brand) { m_brand = brand; }
	void setProductName(std::string productName) { m_productName = productName; }
	void setPrice(double price) { m_price = price; }
	void setMaxDiscount(double discount) { m_maxDiscount = discount; }

	bool operator< (const Product& rV) { return this->m_type < rV.m_type; }

	virtual std::string Info() const;
	
	enum Type
	{
		Smartphone,
		Notebook,
		MobilePhone,
		Unknown
	};

	Type getType() const { return m_type; }

protected:
	Type	m_type;
	virtual void checkInput();
private:
	std::string		m_brand;
	std::string		m_productName;
	double			m_price;
	double			m_maxDiscount;
};

