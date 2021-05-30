#pragma once
#include "Product.h"
class Notebook :
    public Product
{
public:
    Notebook(std::string brand, std::string productName, double price, double maxDiscount, double screenDiagonal, double weight, unsigned int numOfCPUCores, double amountOfRAM);
    ~Notebook(){}

private:
    double m_screenDiagonal;
    double m_weight;
    unsigned int m_numOfCPUCores;
    double m_amountOfRAM;
};

