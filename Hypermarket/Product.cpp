#include "Product.h"

Product::Product(std::string brand, std::string productName, double price, double maxDiscount) : 
	m_brand(brand),
	m_productName(productName),
	m_price(price),
	m_maxDiscount(maxDiscount)
{
	checkInput();
}

double Product::getMaxDiscount() const
{
	return m_maxDiscount;
}

double Product::getPrice() const
{
	return m_price;
}

std::string Product::Info() const
{
	std::stringstream ss;

	ss << "Product: \nbrand: " << m_brand + "\nproduct name: "
			+ m_productName + "\nprice: " 
			<< std::setprecision(2) << std::fixed << m_price << "\nmax discount: " 
			<< m_maxDiscount;
	return ss.str();
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
