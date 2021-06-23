#pragma once


#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include "Product.h"
#include "Customer.h"

class Hypermarket
{
public:
	Hypermarket() = default; 
	~Hypermarket() = default; 

	void addProduct(Product* prod);
	void removeProduct(int pos);

	void addCustomer(BaseCustomer* customer);
	void removeCustomer(int pos);

	bool isEmptyCustomers() const;
	bool isEmptyProducts() const;

	void printProducts() const;
	void printCustomers() const;

	BaseCustomer* getCustomer(const std::string& fullName)
	{
		if (isCustomerExist(fullName))
		{
			return *std::find_if(m_customers.begin(), m_customers.end(), [fullName](BaseCustomer* val) { return (val->getName() == fullName); });
		}

		else
			return nullptr;
	}

private:
	//ѕровер€ет наличие покупател€ по имени
	bool isCustomerExist(const std::string& fullName) const
	{ 
		return std::count_if(m_customers.begin(), m_customers.end(), [fullName](BaseCustomer* customer) {
			return customer->getName() == fullName;
		});
	}
	std::vector<BaseCustomer*>	m_customers;
	std::vector<Product*>		m_availableProds;
};

