#pragma once
#include "Product.h"
class MobilePhone :
    public Product
{
public:
    MobilePhone(std::string, std::string, double, double, unsigned char, bool);
    virtual ~MobilePhone() {}
private:
    unsigned char   m_maxNumOfSim;
    bool            m_withContract;
};

