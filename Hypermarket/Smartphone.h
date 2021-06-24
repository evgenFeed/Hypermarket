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
    std::string Info() const override;

    OS getOS() const { return OperationSystem; }
    std::vector<std::string> getInstalledPrograms() const { return m_installedPrograms; }

    void installPrograms(std::string program)
    {
        m_installedPrograms.push_back(program);
    }
    void setInstalledPrograms(std::vector<std::string> programs) { m_installedPrograms = programs; }
    void setOS(OS os) { OperationSystem = os; }

protected:
    void checkInput() override;
private:
    static std::string wichOS(OS os); 
    OS OperationSystem;
    std::vector<std::string>  m_installedPrograms;  
};

