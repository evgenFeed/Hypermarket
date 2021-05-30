#include "Smartphone.h"

Smartphone::Smartphone(std::string brand, std::string productName, double price, double maxDiscount, unsigned char maxNumOfSim, bool withContract, OS operationSystem):
	MobilePhone(brand, productName, price, maxDiscount, maxNumOfSim, withContract),
	m_installedPrograms{}
{

}

double Smartphone::getMaxDiscount()
{
	return Product::getMaxDiscount();
}

double Smartphone::getPrice()
{
	return Product::getPrice();
}
