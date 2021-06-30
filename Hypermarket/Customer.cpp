#include "Customer.h"

Customer::Customer(const std::string& fullName, double totalCostBought, double balance, int purchases) :
	BaseCustomer(fullName, totalCostBought, balance, purchases)
{
	BaseCustomer::checkInput();
}

double Customer::getFinalPriceForCustomer(Product* prod)
{
	return prod->getPrice();
}

double Customer::personalDiscount()
{
	return 0.0;
}

bool Customer::isRegular()
{
	return false;
}
