#include "Product.h"

Product::Product(std::string brand, std::string productName, double price, float maxDiscount) : 
	m_brand(brand),
	m_productName(productName),
	m_price(price),
	m_maxDiscount(maxDiscount)
{

}

double Product::getMaxDiscount() const
{
	return m_maxDiscount;
}

void Product::setMaxDiscount(float discount)
{
	m_maxDiscount = discount;
}