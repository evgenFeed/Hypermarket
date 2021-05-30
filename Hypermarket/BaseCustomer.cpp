#include "BaseCustomer.h"

BaseCustomer::BaseCustomer(std::string fullName, double totalCostBought, double balance) :
	Customer(fullName, totalCostBought, balance)
{

}

double BaseCustomer::getFinalPriceForCustomer(Product* prod)
{
	return prod->getPrice();
}

double BaseCustomer::personalDiscount()
{
	return 0.0;
}
