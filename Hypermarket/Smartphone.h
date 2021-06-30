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

    Smartphone(std::string brand, std::string productName, double price, double maxDiscount,
                unsigned char maxNumOfSim, bool withContract, OS operationSystem, std::vector<std::string>& programs);
    virtual ~Smartphone() {}

    std::string Info() const override;

    std::vector<std::string> getInstalledPrograms() const { return m_installedPrograms; }

    void    installProgram(std::string program) { m_installedPrograms.push_back(program); }
    void    setInstalledPrograms(std::vector<std::string> programs) { m_installedPrograms = programs; }
    void    setOS(OS os) { OperationSystem = os; }
    OS      getOS() const { return OperationSystem; }

    static std::string wichOS(OS os);

protected:
    void checkInput() override;
private:
    OS OperationSystem;
    std::vector<std::string>  m_installedPrograms;  
};

