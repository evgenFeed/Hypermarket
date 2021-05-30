#pragma once

#include "Customer.h"

class RegularCustomer :
    public Customer
{
public:
    RegularCustomer(double, std::string, double totalCostBought = 0);
    virtual double	personalDiscount() override;
    virtual void    buyProduct(Product*) override;
private:
    std::string m_fullName;
    double      m_totalCostBought;
};

