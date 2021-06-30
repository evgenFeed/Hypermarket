#include "Hypermarket.h"

Hypermarket::~Hypermarket()
{
	for (auto prod : m_availableProds)
	{
		delete prod;
	}
	for (auto customer : m_customers)
	{
		delete customer;
	}
}

void Hypermarket::addProduct(Product* prod)
{
	m_availableProds.push_back(prod);
}

void Hypermarket::removeProduct(int pos)
{
	if (pos > m_availableProds.size() || pos <= 0)
	{
		throw std::invalid_argument("Wrong number!");
	}
	else
	{
		m_availableProds.erase(m_availableProds.begin() + pos - 1);
	}
}

void Hypermarket::addCustomer(BaseCustomer* customer)
{
	m_customers.push_back(customer);
}

void Hypermarket::removeCustomer(int pos)
{
	if (pos > m_customers.size() || pos <= 0)
	{
		throw std::invalid_argument("Wrong number!");
	}
	else
	{
		m_customers.erase(m_customers.begin() + pos - 1);
	}
}

void Hypermarket::removeCustomer(BaseCustomer* customer)
{
	auto it = std::find(m_customers.begin(), m_customers.end(), customer);
	if (it != m_customers.end())
	{
		m_customers.erase(it);
	}
}

bool Hypermarket::isEmptyCustomers() const
{
	return m_customers.empty();
}

bool Hypermarket::isEmptyProducts() const
{
	return m_availableProds.empty();
}

void Hypermarket::printProducts() const
{
	int i = 1;
	for (const auto& prod : m_availableProds)
	{
		std::cout << i++ << " " << std::setprecision(2) << std::fixed << prod->Info() << std::endl;
	}
}

void Hypermarket::printCustomers() const
{
	int i = 1;
	for (const auto& cust : m_customers)
	{
		std::cout << i++ << ' ' << std::setprecision(2) << cust->Info() << std::endl;
	}
}

Product* Hypermarket::getProduct(int pos) const
{
	return m_availableProds[pos-1];
}

BaseCustomer* Hypermarket::getCustomer(const std::string& fullName) const
{
	auto it = std::find_if(m_customers.begin(), m_customers.end(), [fullName](BaseCustomer* val) { return (val->getName() == fullName); });
	if (it != m_customers.end())
	{
		return *it;
	}
	else
		return nullptr;
}

BaseCustomer* Hypermarket::getCustomer(BaseCustomer* customer) const
{
	auto it = std::find_if(m_customers.begin(), m_customers.end(), [customer](BaseCustomer* val) { return (val->getName() == customer->getName()); });
	if (it != m_customers.end())
	{
		return *it;
	}
	else
	{
		return nullptr;
	}
}

Product* Hypermarket::editProduct(Product* prod)
{
	Product* product = nullptr;
	Smartphone* smartphone = nullptr;
	Notebook* notebook = nullptr;
	MobilePhone* mobilephone = nullptr;
	std::cout << prod->Info();
	switch (prod->getType())
	{
	case Product::Type::Smartphone:
		smartphone = dynamic_cast<Smartphone*>(prod);
		break;
	case Product::Type::Notebook:
		notebook = dynamic_cast<Notebook*>(prod);
		break;
	case Product::Type::MobilePhone:
		mobilephone = dynamic_cast<MobilePhone*>(prod);
		break;
	default:
		throw std::invalid_argument("Unknown type product");
		break;
	}
	if (smartphone != nullptr)
	{
		smartphone = editSmartphone(smartphone);
		product = smartphone;
	}
	else if (notebook != nullptr)
	{
		notebook = editNotebook(notebook);
		product = notebook;
	}
	else if (mobilephone != nullptr)
	{
		mobilephone = editMobilePhone(mobilephone);
		product = mobilephone;
	}
	return product;
}

MobilePhone* Hypermarket::editMobilePhone(MobilePhone* phone)
{
	std::string brand, productName;
	double price, maxDiscount;
	unsigned char maxNumOfSim;
	int osEnter;
	Smartphone::OS operationSystem;
	char agreement;
	std::cout << "brand: " << phone->getBrand() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin.ignore();
		std::getline(std::cin, brand);
		phone->setBrand(brand);
	}
	std::cout << "product name: " << phone->getProductName() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin.ignore();
		getline(std::cin, productName);
		phone->setProductName(productName);
	}
	std::cout << "price: " << phone->getPrice() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin >> price;
		phone->setPrice(price);
	}
	std::cout << "max discount: " << phone->getMaxDiscount() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin >> maxDiscount;
		phone->setMaxDiscount(maxDiscount);
	}
	std::cout << "max number of sim:" << phone->getMaxNumberOfSim() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin >> maxNumOfSim;
		phone->setMaxNumOfSim(maxNumOfSim);
	}
	return phone;
}

Smartphone* Hypermarket::editSmartphone(Smartphone* smart)
{
	std::string brand, productName;
	double price, maxDiscount;
	unsigned char maxNumOfSim;
	int osEnter;
	Smartphone::OS operationSystem;
	char agreement;
	std::cout << "brand: " << smart->getBrand() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin.ignore();
		getline(std::cin, brand);
		smart->setBrand(brand);
	}
	std::cout << "product name: " << smart->getProductName() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin.ignore();
		getline(std::cin, productName);
		smart->setProductName(productName);
	}
	std::cout << "price: " << smart->getPrice() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin >> price;
		smart->setPrice(price);
	}
	std::cout << "max discount: " << smart->getMaxDiscount() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin >> maxDiscount;
		smart->setMaxDiscount(maxDiscount);
	}
	std::cout << "operation system: " << Smartphone::wichOS(smart->getOS()) << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Operation system: (1. Android. 2. iOS. 3. WindowsPhone. 4. Another) " << std::endl;
		std::cout << "Enter new value: ";
		std::cin >> osEnter;
		operationSystem = (osEnter <= 4 && osEnter >= 1) ? static_cast<Smartphone::OS>(osEnter) : Smartphone::OS::Unknown;
		smart->setOS(operationSystem);
	}
	std::cout << "max number of sim:" << smart->getMaxNumberOfSim() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin >> maxNumOfSim;
		smart->setMaxNumOfSim(maxNumOfSim);
	}
	return smart;
}

Notebook* Hypermarket::editNotebook(Notebook* note)
{
	std::string brand, productName;
	double price, maxDiscount;
	double screenDiagonal, weight;
	unsigned int numOfCPUCores, amountOfRAM;
	char agreement;
	std::cout << "brand: " << note->getBrand() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin.ignore();
		std::getline(std::cin, brand);
		note->setBrand(brand);
	}
	std::cout << "product name: " << note->getProductName() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin.ignore();
		std::getline(std::cin, productName);
		note->setProductName(productName);
	}
	std::cout << "price: " << note->getPrice() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin >> price;
		note->setPrice(price);
	}
	std::cout << "max discount: " << note->getMaxDiscount() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin >> maxDiscount;
		note->setMaxDiscount(maxDiscount);
	}
	std::cout << "screen diagonal: " << note->getScreenDiagonal() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin >> screenDiagonal;
		note->setScreenDiagonal(screenDiagonal);
	}
	std::cout << "number of CPU cores: " << note->getNumOfCPUCores() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin >> numOfCPUCores;
		note->setNumOfCPUCores(numOfCPUCores);
	}
	std::cout << "amount of RAM: " << note->getAmountOfRAM() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin >> amountOfRAM;
		note->setAmountOfRAM(amountOfRAM);
	}
	std::cout << "weight: " << note->getWeight() << " edit? (y/n) ";
	std::cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		std::cout << "Enter new value: ";
		std::cin >> weight;
		note->setWeight(weight);
	}
	return note;
}

bool Hypermarket::isCustomerExist(const std::string& fullName) const
{
	if (std::find_if(m_customers.begin(), m_customers.end(), [fullName](BaseCustomer* customer) {
		return customer->getName() == fullName;
	}) != m_customers.end()) return true;
	else
		return false;
}
