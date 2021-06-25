#pragma once
#include "BaseCustomer.h"
class Customer :
    public BaseCustomer
{
public:
    Customer(const std::string& m_fullName, double m_totalCostBought, double m_balance);
    ~Customer() {};


    double	getFinalPriceForCustomer(Product* prod) override;
    double	personalDiscount() override;
};

