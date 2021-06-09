#pragma once

#include <set>
#include <vector>
#include "Product.h"
#include "Customer.h"

class Hypermarket
{
public:
	Hypermarket() = default;  // Говорим компилятору сгенерировать конструктор по умолчанию
	~Hypermarket();

	void addProduct(Product* prod);
	void removeProduct(int pos);

	void addCustomer(Customer* customer);
	void removeCustomer(int pos);

	bool isEmptyCustomers();
	bool isEmptyProducts();

private:

	std::vector<Customer*> m_customers;
	std::vector<Product*> m_availableProds;
};

