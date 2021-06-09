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

void Hypermarket::addCustomer(Customer* customer)
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