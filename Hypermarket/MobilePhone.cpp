#include "MobilePhone.h"

MobilePhone::MobilePhone(std::string brand, std::string productName, double price, double maxDiscount, unsigned char maxNumOfSim, bool withContract):
	Product(brand, productName, price, maxDiscount),
	m_maxNumOfSim(maxNumOfSim),
	m_withContract(withContract)
{
	checkInput();
}

void MobilePhone::checkInput()
{
	Product::checkInput();
	if (m_maxNumOfSim < 0)
	{
		throw std::invalid_argument("Amount of sim must be greater than or equal to 0");
	}
}
