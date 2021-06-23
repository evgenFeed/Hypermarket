#pragma once

#include <vector>
#include "Product.h"

class BaseCustomer
{
public:
	BaseCustomer(const std::string& m_fullName, double m_totalCostBought, double m_balance);
	virtual ~BaseCustomer();
	
	virtual std::string	Info();
	std::string			getName() const { return m_fullName; }
protected:

	virtual double		personalDiscount() = 0;
	virtual	double		getFinalPriceForCustomer(Product* prod) = 0;

	virtual void		addProductToShopingList(Product* prod);
	virtual void		buyProducts();

	double				m_totalCostBought;
private:

	std::vector<Product*>	m_shoppingList;
	std::string				m_fullName;
	double					m_balance;
};
