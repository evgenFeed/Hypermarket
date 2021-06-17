#pragma once


#include <iostream>
#include <set>
#include <vector>
#include <memory>
#include "Product.h"
#include "Customer.h"

class Hypermarket
{
public:
	Hypermarket() = default;  // Говорим компилятору сгенерировать конструктор по умолчанию
	~Hypermarket() = default; 

	void addProduct(std::shared_ptr<Product> prod);
	void removeProduct(int pos);

	void addCustomer(std::shared_ptr<BaseCustomer> customer);
	void removeCustomer(int pos);

	bool isEmptyCustomers();
	bool isEmptyProducts();

	void printProducts();
	void printCustomers();


private:

	std::vector<std::shared_ptr<BaseCustomer>> m_customers;
	std::vector<std::shared_ptr<Product>> m_availableProds;
};

