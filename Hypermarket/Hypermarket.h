#pragma once


#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Product.h"
#include "Customer.h"

class Hypermarket
{
public:
	Hypermarket() = default; 
	~Hypermarket(); 

	void addProduct(Product* prod);
	void removeProduct(int pos);

	void addCustomer(BaseCustomer* customer);
	void removeCustomer(int pos);

	bool isEmptyCustomers() const;
	bool isEmptyProducts() const;

	void printProducts() const;
	void printCustomers() const;
	
	Product*		getProduct(int pos) const;
	BaseCustomer*	getCustomer(const std::string& fullName) const;
	
	int getCustomersAmount() const { return m_customers.size(); }
	int getProductsAmount() const { return m_availableProds.size(); }
private:
	// ѕровер€ет наличие покупател€ по имени
	bool isCustomerExist(const std::string& fullName) const
	{ 
		return std::count_if(m_customers.begin(), m_customers.end(), [fullName](BaseCustomer* customer) {
			return customer->getName() == fullName;
		});
	}
	std::vector<BaseCustomer*>	m_customers;
	std::vector<Product*>		m_availableProds;
};

