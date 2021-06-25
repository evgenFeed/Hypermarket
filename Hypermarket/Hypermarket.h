#pragma once


#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "Product.h"
#include "Customer.h"
#include "Smartphone.h"
#include "Notebook.h"
#include "MobilePhone.h"
#include "RegularCustomer.h"


class Hypermarket
{
public:
	Hypermarket() = default; 
	~Hypermarket(); 

	void addProduct(Product* prod);
	void removeProduct(int pos);

	void addCustomer(BaseCustomer* customer);
	void removeCustomer(int pos);
	void removeCustomer(BaseCustomer* customer);

	bool isEmptyCustomers() const;
	bool isEmptyProducts() const;

	void printProducts() const;
	void printCustomers() const;
	
	Product*		getProduct(int pos) const;
	BaseCustomer*	getCustomer(const std::string& fullName) const;
	BaseCustomer*	getCustomer(BaseCustomer* customer) const;
	Product*		editProduct(Product* prod);
	
	int getCustomersAmount() const { return m_customers.size(); }
	int getProductsAmount() const { return m_availableProds.size(); }
private:
	MobilePhone* editMobilePhone(MobilePhone* phone);
	Smartphone* editSmartphone(Smartphone* smart);
	Notebook* editNotebook(Notebook* note);

	// ѕровер€ет наличие покупател€ по имени
	bool isCustomerExist(const std::string& fullName) const;
	
	std::vector<BaseCustomer*>	m_customers;
	std::vector<Product*>		m_availableProds;
};

