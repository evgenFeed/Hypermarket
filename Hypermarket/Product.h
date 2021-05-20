#pragma once

#include <string>

class Product
{
public:
	Product() {}
	Product(std::string, std::string, double, float) {}
	double getMaxDiscount() const;
	void setMaxDiscount(float discount);
private:


private:
	std::string		m_brand;
	std::string		m_productName;
	double			m_price;
	double			m_maxDiscount;
};

