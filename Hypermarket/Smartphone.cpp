#include "Smartphone.h"

Smartphone::Smartphone(std::string brand, std::string productName, double price, double maxDiscount,
						unsigned char maxNumOfSim, bool withContract, OS operationSystem):
	MobilePhone(brand, productName, price, maxDiscount, maxNumOfSim, withContract),
	OperationSystem(operationSystem),
	m_installedPrograms{}
{
	m_type = Product::Type::Smartphone;
	checkInput();
}

std::string Smartphone::Info() const
{
	std::string result = Product::Info() + "\noperation system: " + wichOS(OperationSystem)
			+ "\ninstalledPrograms: ";
	for (const auto& prog : m_installedPrograms)
	{
		result += prog + ' ';
	}
	result += '\n';
	return result;
}

void Smartphone::checkInput()
{
	MobilePhone::checkInput();
}

std::string Smartphone::wichOS(OS os)
{
	switch (os)
	{
	case Smartphone::Android:
		return "Android";
		break;
	case Smartphone::iOS:
		return "iOS";
		break;
	case Smartphone::WindowsPhone:
		return "WindowsPhone";
		break;
	default:
		return "Unknown";
		break;
	}
}

