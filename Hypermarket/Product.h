#pragma once

#include <string>
#include <stdexcept>




class Product
{
public:
	Product(std::string, std::string, double, double);
	virtual ~Product() {}

	virtual double	getMaxDiscount();
	virtual double	getPrice();

	bool operator< (const Product& rV) { return this->m_type > rV.m_type; }

	enum Type
	{
		Smartphone,
		Notebook,
		Unknown
	};

protected:
	Type m_type;

private:

	std::string		m_brand;
	std::string		m_productName;
	double			m_price;
	double			m_maxDiscount;
};

