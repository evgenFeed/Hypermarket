#pragma once
#include "Product.h"
class MobilePhone :
    public Product
{
public:
    MobilePhone(std::string brand, std::string productName, double price, double maxDiscount,
                unsigned char maxNumOfSim, bool withContract);
    virtual ~MobilePhone() {}
protected:
    void checkInput() override;

private:
    unsigned char   m_maxNumOfSim;
    bool            m_withContract;
};

