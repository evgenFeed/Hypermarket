#include "MobilePhone.h"

MobilePhone::MobilePhone(std::string brand, std::string productName, double price, double maxDiscount, unsigned char maxNumOfSim, bool withContract):
	Product(brand, productName, price, maxDiscount),
	m_maxNumOfSim(maxNumOfSim),
	m_withContract(withContract)
{

}