#include "Customer.h"

Customer::Customer(double balance) :
	m_balance(balance),
	m_shoppingList{}
{

}

double Customer::personalDiscount()
{
	return 0.0;
}

void Customer::buyProduct(Product* prod)
{
	if (personalDiscount() > prod->getMaxDiscount())
	{
		
	}
}
