#include "Customer.h"

Customer::Customer(double balance) :
	m_balance(balance),
	m_shoppingList{}
{

}

Customer::~Customer()
{
	m_shoppingList.~vector();
}

double Customer::personalDiscount()
{
	return 0.0;
}

void Customer::buyProduct(Product* prod)
{
	if (m_balance >= prod->getPrice())
	{
		m_balance -= prod->getPrice();
		m_shoppingList.push_back(prod);
	}
	else
		throw std::exception("Not enough money");
}
