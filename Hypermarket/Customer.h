#pragma once
#include <vector>
#include "Product.h"
class Customer
{
public:
	Customer(double balance = 0);
protected:
	virtual double	personalDiscount();
	virtual void	buyProduct(Product*);
private:
	std::vector<Product*>	m_shoppingList;
	double					m_balance;
};

