#include "Hypermarket.h"



Hypermarket::~Hypermarket()
{
	for(auto prod : m_availableProds)
	{
		delete prod;
	}

	for (auto cust : m_customers)
	{
		delete cust;
	}
}

void Hypermarket::addProduct(Product* prod)
{
	m_availableProds.push_back(prod);
}

void Hypermarket::removeProduct(int pos)
{
	m_availableProds.erase(m_availableProds.begin() + pos);
}

void Hypermarket::addCustomer(BaseCustomer* customer)
{
	m_customers.push_back(customer);
}

void Hypermarket::removeCustomer(int pos)
{
	m_customers.erase(m_customers.begin() + pos);
}

bool Hypermarket::isEmptyCustomers()
{
	return m_customers.empty();
}

bool Hypermarket::isEmptyProducts()
{
	return m_availableProds.empty();
}

void Hypermarket::printProducts()
{
	int i = 1;
	for (const auto& prod : m_availableProds)
	{
		std::cout << i++ << ' ' << prod->Info() << std::endl;
	}
}

void Hypermarket::printCustomers()
{
	int i = 1;
	for (const auto& cust : m_customers)
	{
		std::cout << i++ << ' ' << cust->Info() << std::endl;
	}
}
