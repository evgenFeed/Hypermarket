#include "BaseCustomer.h"

BaseCustomer::BaseCustomer(const std::string& fullName, double totalCostBought, double balance, int purchases):
	m_fullName(fullName),
	m_totalCostBought(totalCostBought),
	m_balance(balance),
	m_shoppingList{},
	m_purchases(purchases)
{
	checkInput();
}

BaseCustomer::~BaseCustomer()
{

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
		m_totalCostBought += price;
		m_purchases++;
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


void BaseCustomer::checkInput()
{
	if (m_balance < 0)
	{
		throw std::invalid_argument("Wrong value!");
	}
}

std::string BaseCustomer::Info()
{
	std::stringstream ss;
	ss << "Customer: \n" << "Name: " << m_fullName << "\n balance: " << std::setprecision(2)  << std::fixed << m_balance
		<< "\n total cost bought: " << m_totalCostBought
		<< "\n purchases: " << m_purchases
		<< "\n personal discount: " << this->personalDiscount() << "\n";
	return ss.str();
}

const char* BaseCustomer::LowBalanceException::what() const noexcept
{
	return "Low balance!";
}
