#include "Product.h"

Product::Product(std::string brand, std::string productName, double price, double maxDiscount) : 
	m_brand(brand),
	m_productName(productName),
	m_price(price),
	m_maxDiscount(maxDiscount)
{

}

double Product::getMaxDiscount()
{
	return m_maxDiscount;
}

double Product::getPrice()
{
	return m_price;
}