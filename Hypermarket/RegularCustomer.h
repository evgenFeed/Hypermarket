#pragma once

#include "BaseCustomer.h"

class RegularCustomer :
    public BaseCustomer
{
public:
    RegularCustomer(const std::string& fullName, double totalCostBought = 0, double balance = 0, int purchases = 0);

    ~RegularCustomer() {};

    virtual double	personalDiscount() override;
    virtual	double	getFinalPriceForCustomer(Product* prod) override;
    virtual bool isRegular() override;
};

