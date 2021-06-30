#pragma once

#include <vector>
#include "Product.h"

class BaseCustomer
{
public:
	BaseCustomer(const std::string& fullName, double totalCostBought, double balance, int purchases = 0);
	virtual ~BaseCustomer();
	
	virtual std::string	Info();
	std::string			getName() const { return m_fullName; }
	double				getBalance() const { return m_balance; }
	int					getAmountOfProdsAtShopingList() const { return m_shoppingList.size(); }
	double				getTotalCostBought() const { return m_totalCostBought; }
	int					getPurchases() const { return m_purchases; }
	std::vector<Product*> getShopingList() const { return m_shoppingList; }
	void				setShopingList(const std::vector<Product*>& shoppingList) { m_shoppingList = shoppingList; }
	void				addProductToShopingList(Product* prod);
	void				removeProductFromShopingList(int pos);
	void				buyProducts();
	void				printShopingList() const;
	void				clearShopingList() { m_shoppingList.clear(); }	

	virtual bool		isRegular() = 0;
protected:

	virtual double		personalDiscount() = 0;
	virtual	double		getFinalPriceForCustomer(Product* prod) = 0;
	double				m_totalCostBought;
	virtual void		checkInput();
private:
	class LowBalanceException : public std::exception
	{
		const char*		what() const noexcept override;
	};

	int						m_purchases;
	std::vector<Product*>	m_shoppingList;
	std::string				m_fullName;
	double					m_balance;
};
