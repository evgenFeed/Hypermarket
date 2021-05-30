#include "Customer.h"

Customer::Customer(double balance) :
	m_balance(balance),
	m_shoppingList{}
{

}

void Customer::addProduct(Product* prod)
{
	m_shoppingList.push_back(prod);
}

Customer::Customer(std::string fullName, double totalCostBought, double balance):
	m_fullName(fullName),
	m_totalCostBought(totalCostBought),
	m_balance(balance),
	m_shoppingList{}
{
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
