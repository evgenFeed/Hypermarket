#pragma once
#include "Product.h"
class Notebook :
    public Product
{
    double m_screenDiagonal;
    double m_weight;
    unsigned int m_numOfCPUCores;
    double m_amountOfRAM;
};

