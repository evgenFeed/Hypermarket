#include "Notebook.h"

Notebook::Notebook(const std::string& brand, const std::string& productName, double price, double maxDiscount,
				double screenDiagonal, double weight, unsigned int numOfCPUCores, unsigned int amountOfRAM):
	Product(brand, productName, price, maxDiscount),
	m_screenDiagonal(screenDiagonal),
	m_numOfCPUCores(numOfCPUCores),
	m_amountOfRAM(amountOfRAM),
	m_weight(weight)
{
	m_type = Product::Type::Notebook;
	checkInput();
}

std::string Notebook::Info() const
{
	return Product::Info() + "\nscreen diagonal: " + std::to_string(m_screenDiagonal)
		+ "\nnumber of CPU cores: " + std::to_string(m_numOfCPUCores)
		+ "\namount of RAM: " + std::to_string(m_amountOfRAM)
		+ "\nweight: " + std::to_string(m_weight) + '\n';
}

void Notebook::checkInput()
{
	Product::checkInput();
	if (m_weight <= 0)
	{
		throw std::invalid_argument("Weight can't be less than or equal to 0");
	}
	if (m_screenDiagonal <= 0)
	{
		throw std::invalid_argument("Screen diagonal can't be less than or equal to 0");
	}
	if (m_numOfCPUCores < 1)
	{
		throw std::invalid_argument("Number of CPU cores must be greater than or equal to 1");
	}
	if (m_amountOfRAM < 1)
	{
		throw std::invalid_argument("Amount of RAM must be greater than 0");
	}
}


