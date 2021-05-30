#include "RegularCustomer.h"


RegularCustomer::RegularCustomer(std::string fullName, double totalCostBought, double balance):
	Customer(fullName, totalCostBought, balance)
{
}

double RegularCustomer::personalDiscount()
{
	return (m_totalCostBought / 1000 <= 15) ? m_totalCostBought / 1000 : 15;
}

double RegularCustomer::getFinalPriceForCustomer(Product* prod)
{
	return prod->getPrice() - ((prod->getPrice() * personalDiscount()) / 100);
}
