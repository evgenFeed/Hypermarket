#pragma once

#include "MobilePhone.h"
#include <vector>
#include <string>

enum OS
{
    Android,
    iOS,
    WindowsPhone,
    Unknown
};

class Smartphone :
    public MobilePhone
{
public:
    Smartphone(std::string brand, std::string productName, double price, double maxDiscount, unsigned char maxNumOfSim, bool withContract, OS operationSystem);
    virtual ~Smartphone() {}
private:

    OS OperationSystem;
    std::vector<std::string>  m_installedPrograms;
};

