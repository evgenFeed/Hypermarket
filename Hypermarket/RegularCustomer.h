#pragma once
#include "Customer.h"
class RegularCustomer :
    public Customer
{
public:
    RegularCustomer();
    double	personalDiscount() override;
private:
    std::string m_fullName;
    double      m_totalCost;
};

