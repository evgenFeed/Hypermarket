#pragma once
#include "Product.h"
class Notebook :
    public Product
{
public:
    Notebook(const std::string& brand, const std::string& productName, double price, double maxDiscount,
            double screenDiagonal, double weight, unsigned int numOfCPUCores, unsigned int amountOfRAM);
    ~Notebook(){}

    std::string Info() override;

protected:
    void checkInput() override;
private:
    
    double m_screenDiagonal;
    double m_weight;
    unsigned int m_numOfCPUCores;
    unsigned int m_amountOfRAM;
};

