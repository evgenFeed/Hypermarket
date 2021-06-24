#pragma once

#include <vector>
#include "Product.h"

class BaseCustomer
{
public:
	BaseCustomer(const std::string& fullName, double totalCostBought, double balance);
	virtual ~BaseCustomer();
	
	virtual std::string	Info();
	std::string			getName() const { return m_fullName; }
	void				addProductToShopingList(Product* prod);
	void				removeProductFromShopingList(int pos);
	void				buyProducts();
	void				printShopingList() const;
	int					getAmountOfProdsAtShopingList() const { return m_shoppingList.size(); }
protected:

	virtual double		personalDiscount() = 0;
	virtual	double		getFinalPriceForCustomer(Product* prod) = 0;

	double				m_totalCostBought;
private:
	
	class LowBalanceException : std::exception
	{
		const char*		what() const noexcept override;
	};


	std::vector<Product*>	m_shoppingList;
	std::string				m_fullName;
	double					m_balance;
};
