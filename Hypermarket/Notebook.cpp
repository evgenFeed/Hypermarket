#include "Notebook.h"

Notebook::Notebook(std::string brand, std::string productName, double price, double maxDiscount, double screenDiagonal, double weight, unsigned int numOfCPUCores, double amountOfRAM):
	Product(brand, productName, price, maxDiscount),
	m_screenDiagonal(screenDiagonal),
	m_numOfCPUCores(numOfCPUCores),
	m_amountOfRAM(amountOfRAM),
	m_weight(weight)
{

}
