#include "Product.h"

Product::Product(std::string brand, std::string productName, double price, double maxDiscount) : 
	m_brand(brand),
	m_productName(productName),
	m_price(price),
	m_maxDiscount(maxDiscount)
{
	checkInput();
}

double Product::getMaxDiscount()
{
	return m_maxDiscount;
}

double Product::getPrice()
{
	return m_price;
}

std::string Product::Info()
{
	return "Product: \nbrand: " + m_brand + "\nproduct name: "
			+ m_productName + "\nprice: " 
			+ std::to_string(m_price) + "\nmax discount: " 
			+ std::to_string(m_maxDiscount);
}

void Product::checkInput()
{
	if (m_price < 0)
	{
		throw std::invalid_argument("Price can't be less than 0");
	}
	if (m_maxDiscount < 0)
	{
		throw std::invalid_argument("Discount can't be less than 0");
	}
}
