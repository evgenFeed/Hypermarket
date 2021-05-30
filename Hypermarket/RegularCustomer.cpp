#include "RegularCustomer.h"

RegularCustomer::RegularCustomer(double balance, std::string fullName, double totalCostBought): 
	Customer(balance),
	m_fullName(fullName),
	m_totalCostBought(totalCostBought)
{
}

double RegularCustomer::personalDiscount()
{
	return (m_totalCostBought / 1000 <= 15) ? m_totalCostBought / 1000 : 15;
}

void RegularCustomer::buyProduct(Product* prod)
{
	double discount = personalDiscount();
	if (personalDiscount() > prod->getMaxDiscount())
	{
		discount = prod->getMaxDiscount();
	}
	m_totalCostBought += (prod->getPrice() - ((prod->getPrice() / 100) * discount));
	Customer::buyProduct(prod);

}
