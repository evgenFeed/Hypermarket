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
    Smartphone(std::string, std::string, double, double, unsigned char, bool, OS);
    virtual ~Smartphone() {}
    virtual double	getMaxDiscount() override;
    virtual double	getPrice() override;
private:

    OS OperationSystem;
    std::vector<std::string>  m_installedPrograms;
};

