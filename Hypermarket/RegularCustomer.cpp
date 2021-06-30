#include "RegularCustomer.h"


RegularCustomer::RegularCustomer(const std::string& fullName, double totalCostBought, double balance, int purchases):
	BaseCustomer(fullName, totalCostBought, balance, purchases)
{
}

double RegularCustomer::personalDiscount()
{
	return (m_totalCostBought / 1000 <= 15) ? m_totalCostBought / 1000 : 15;
}

double RegularCustomer::getFinalPriceForCustomer(Product* prod)
{
	double discount = 0;
	if (personalDiscount() <= prod->getMaxDiscount())
	{
		discount = personalDiscount();
	}
	else if (personalDiscount() > prod->getMaxDiscount())
	{
		discount = prod->getMaxDiscount();
	}
	return prod->getPrice() - ((prod->getPrice() * discount) / 100);
}

bool RegularCustomer::isRegular()
{
	return true;
}
