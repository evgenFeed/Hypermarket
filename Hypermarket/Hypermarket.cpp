#include "Hypermarket.h"



Hypermarket::~Hypermarket()
{

}

void Hypermarket::addProduct(Product* prod)
{
	m_availableProds.push_back(prod);
}

void Hypermarket::removeProduct(int pos)
{
	delete m_availableProds[pos];
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

bool Hypermarket::isEmptyCustomers() const
{
	return m_customers.empty();
}

bool Hypermarket::isEmptyProducts() const
{
	return m_availableProds.empty();
}

void Hypermarket::printProducts() const
{
	int i = 1;
	for (const auto& prod : m_availableProds)
	{
		std::cout << i++ << '\n' << std::setprecision(2) << std::fixed << prod->Info() << std::endl;
	}
}

void Hypermarket::printCustomers() const
{
	int i = 1;
	for (const auto& cust : m_customers)
	{
		std::cout << i++ << ' ' << std::setprecision(2) << cust->Info() << std::endl;
	}
}

Product* Hypermarket::getProduct(int pos) const
{
	return m_availableProds[pos-1];
}

BaseCustomer* Hypermarket::getCustomer(const std::string& fullName) const
{
	if (isCustomerExist(fullName))
	{
		return *std::find_if(m_customers.begin(), m_customers.end(), [fullName](BaseCustomer* val) { return (val->getName() == fullName); });
	}
	else
		return nullptr;
}
