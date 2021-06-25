#include "Customer.h"

Customer::Customer(const std::string& fullName, double totalCostBought, double balance) :
	BaseCustomer(fullName, totalCostBought, balance)
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
