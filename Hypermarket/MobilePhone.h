#pragma once
#include "Product.h"
class MobilePhone :
    public Product
{
public:
    MobilePhone(std::string brand, std::string productName, double price, double maxDiscount,
                unsigned int maxNumOfSim, bool withContract);
    virtual ~MobilePhone() {}
    virtual std::string Info() const override;
    unsigned int getMaxNumberOfSim() const { return m_maxNumOfSim; }
    bool getWithContract() const { return m_withContract; }

    void setMaxNumOfSim(unsigned char val);
    void setWithContract(bool val) { m_withContract = val; }

protected:
    void checkInput() override;

private:
    unsigned int    m_maxNumOfSim;
    bool            m_withContract;
};

