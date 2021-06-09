#pragma once

#include <vector>
#include "Product.h"

class Customer
{
public:
	Customer(const std::string& m_fullName, double m_totalCostBought, double m_balance);
	virtual ~Customer();
	
protected:

	virtual double	personalDiscount() = 0;
	virtual void	addProductToShopingList(Product* prod);
	virtual	double	getFinalPriceForCustomer(Product* prod) = 0;
	virtual void	buyProducts();

	std::vector<Product*>	m_shoppingList;
	std::string				m_fullName;
	double					m_totalCostBought;
	double					m_balance;
};
