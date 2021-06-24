#include "BaseCustomer.h"

BaseCustomer::BaseCustomer(const std::string& fullName, double totalCostBought, double balance):
	m_fullName(fullName),
	m_totalCostBought(totalCostBought),
	m_balance(balance),
	m_shoppingList{}
{
}

BaseCustomer::~BaseCustomer()
{
	for (auto prod : m_shoppingList)
	{
		delete prod;
	}	
}

void BaseCustomer::addProductToShopingList(Product* prod)
{
	m_shoppingList.push_back(prod);
}

void BaseCustomer::removeProductFromShopingList(int pos)
{
	m_shoppingList.erase(m_shoppingList.begin() + pos-1);
}

void BaseCustomer::buyProducts()
{
	double price = 0;
	for (auto& prod : m_shoppingList)
	{
		price += getFinalPriceForCustomer(prod);
	}
	if (m_balance >= price)
	{
		m_balance -= price;
		m_shoppingList.clear();
	}
	else
	{
		throw LowBalanceException();
	}
}

void BaseCustomer::printShopingList() const
{
	int i = 1;
	for (const auto& prod : m_shoppingList)
	{
		std::cout << i++ << " " << prod->Info();
	}
}

std::string BaseCustomer::Info()
{
	return "Customer: " + m_fullName + " balance: " + std::to_string(m_balance)
						+ "\n total cost bought: " + std::to_string(m_totalCostBought)
						+ "\n personal discount: " + std::to_string(personalDiscount()) + "\n";
}

const char* BaseCustomer::LowBalanceException::what() const noexcept
{
	return "Low balance";
}
