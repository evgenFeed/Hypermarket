#pragma once
#include "Product.h"
class MobilePhone :
    public Product
{
    MobilePhone();

private:
    unsigned char   m_maxNumOfSim;
    bool            m_withContract;
};

