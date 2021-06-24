#pragma once
#include "Product.h"
class MobilePhone :
    public Product
{
public:
    MobilePhone(std::string brand, std::string productName, double price, double maxDiscount,
                unsigned char maxNumOfSim, bool withContract);
    virtual ~MobilePhone() {}

    unsigned char getMaxNumberOfSim() const { return m_maxNumOfSim; }
    bool getWithContract() const { return m_withContract; }

    void setMaxNumOfSim(unsigned char val) {
        if (val >= 0)
        {
            m_maxNumOfSim = val;
        }
        else
        {
            throw std::invalid_argument("Wrong input!");
        }
    }
    void setWithContract(bool val)
    {
        m_withContract = val;
    }

protected:
    void checkInput() override;

private:
    unsigned char   m_maxNumOfSim;
    bool            m_withContract;
};

