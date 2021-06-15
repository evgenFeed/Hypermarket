#pragma once

#include "MobilePhone.h"
#include <vector>
#include <string>


class Smartphone :
    public MobilePhone
{
public:
    enum OS
    {
        Android = 1,
        iOS,
        WindowsPhone,
        Unknown
    };

    Smartphone(std::string brand, std::string productName, double price, double maxDiscount, unsigned char maxNumOfSim, bool withContract, OS operationSystem);
    virtual ~Smartphone() {}
    std::string Info() override;
protected:
    void checkInput() override;
private:
    std::string wichOS(OS os);
    OS OperationSystem;
    std::vector<std::string>  m_installedPrograms;
};

