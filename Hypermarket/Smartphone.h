#pragma once

#include "MobilePhone.h"
#include <vector>
#include <string>

class Smartphone :
    public MobilePhone
{
public:
    Smartphone();


    enum OS
    {
        Android,
        iOS,
        WindowsPhone,
        Unknown
    };

private:

    OS OperationSystem;
    std::vector<std::string>  m_installedPrograms;
};

