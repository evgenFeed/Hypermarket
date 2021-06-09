#include "Customer.h"

Customer::Customer(const std::string& fullName, double totalCostBought, double balance):
	m_fullName(fullName),
	m_totalCostBought(totalCostBought),
	m_balance(balance),
	m_shoppingList{}
{
}

Customer::~Customer()
{
	for (auto prod : m_shoppingList)
	{
		delete prod;
	}	
}

void Customer::addProductToShopingList(Product* prod)
{
	m_shoppingList.push_back(prod);
}

void Customer::buyProducts()
{
	double price = 0;
	for (auto& prod : m_shoppingList)
	{
		price += getFinalPriceForCustomer(prod);
	}
	if (m_balance >= price)
	{
		m_balance -= price;
	}
}
