#pragma once
#include "BaseCustomer.h"
#include "RegularCustomer.h"
class Customer :
    public BaseCustomer
{
public:
    Customer(const std::string& fullName, double totalCostBought = 0, double balance = 0, int purchases = 0);
    ~Customer() {};

    double	getFinalPriceForCustomer(Product* prod) override;
    double	personalDiscount() override;
    virtual bool isRegular() override;
};
