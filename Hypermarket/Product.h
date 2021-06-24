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

	virtual double	getMaxDiscount() const;
	virtual double	getPrice() const;

	bool operator< (const Product& rV) { return this->m_type < rV.m_type; }

	virtual std::string Info() const;

	enum Type
	{
		Smartphone,
		Notebook,
		Unknown
	};


protected:
	Type	m_type;
	virtual void checkInput();
private:
	std::string		m_brand;
	std::string		m_productName;
	double			m_price;
	double			m_maxDiscount;
};

