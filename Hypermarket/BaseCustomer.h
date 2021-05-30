#pragma once
#include "Customer.h"
class BaseCustomer :
    public Customer
{
public:
    BaseCustomer(std::string m_fullName, double m_totalCostBought, double m_balance);
    
    double	getFinalPriceForCustomer(Product* prod) override;
    double	personalDiscount() override;
};

