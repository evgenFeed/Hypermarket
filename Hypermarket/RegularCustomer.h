#pragma once

#include "Customer.h"

class RegularCustomer :
    public Customer
{
public:
    RegularCustomer(std::string fullName, double totalCostBought = 0, double balance = 0);
    virtual double	personalDiscount() override;
    virtual	double	getFinalPriceForCustomer(Product* prod) override;
};

