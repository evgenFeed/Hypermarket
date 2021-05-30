#include "Smartphone.h"

Smartphone::Smartphone(std::string brand, std::string productName, double price, double maxDiscount, unsigned char maxNumOfSim, bool withContract, OS operationSystem):
	MobilePhone(brand, productName, price, maxDiscount, maxNumOfSim, withContract),
	OperationSystem(operationSystem),
	m_installedPrograms{}
{
	m_type = Product::Type::Smartphone;
}