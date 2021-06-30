#pragma once
#include "Product.h"
class Notebook :
    public Product
{
public:
    Notebook(const std::string& brand, const std::string& productName, double price, double maxDiscount,
            double screenDiagonal, double weight, unsigned int numOfCPUCores, unsigned int amountOfRAM);
    ~Notebook(){}

    std::string Info() const override;
    double          getScreenDiagonal() const { return m_screenDiagonal; }
    double          getWeight() const { return m_weight; }
    unsigned int    getNumOfCPUCores() const { return m_numOfCPUCores; }
    unsigned int    getAmountOfRAM() const { return m_amountOfRAM; }

    void setScreenDiagonal(double screenDiagonal);
    void setWeight(double weight);
    void setNumOfCPUCores(unsigned int numOfCPUCores);
    void setAmountOfRAM(unsigned int amountOfRAM);

protected:
    void checkInput() override;
private:
    double m_screenDiagonal;
    double m_weight;
    unsigned int m_numOfCPUCores;
    unsigned int m_amountOfRAM;
};

