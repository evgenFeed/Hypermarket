#pragma once

#include <set>
#include <vector>
#include "Product.h"
#include "Customer.h"

class Hypermarket
{
public:
	Hypermarket();
	~Hypermarket() { delete m_customer; };


private:
	Customer* m_customer;
	std::multiset<Product*> m_availableProds;
};

