#include "MobilePhone.h"

MobilePhone::MobilePhone(std::string brand, std::string productName, double price, double maxDiscount, unsigned int maxNumOfSim, bool withContract):
	Product(brand, productName, price, maxDiscount),
	m_maxNumOfSim(maxNumOfSim),
	m_withContract(withContract)
{
	m_type = Product::Type::MobilePhone;
	checkInput();
}

std::string MobilePhone::Info() const
{
	std::string result = Product::Info() + " \nmax number of sim: " + std::to_string(m_maxNumOfSim)
		+ "\nwith contract: " + std::to_string(m_withContract);
	result += '\n';
	return result;
}

void MobilePhone::checkInput()
{
	Product::checkInput();
	if (m_maxNumOfSim < 0)
	{
		throw std::invalid_argument("Amount of sim must be greater than or equal to 0");
	}
}

void MobilePhone::setMaxNumOfSim(unsigned char val)
{
	if (val >= 0)
	{
		m_maxNumOfSim = val;
	}
	else
	{
		throw std::invalid_argument("Wrong input!");
	}
}