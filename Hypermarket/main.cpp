#include <iostream>
#include <memory>
#include <iomanip>
#include "Hypermarket.h"
#include "Product.h"
#include "Notebook.h"
#include "Smartphone.h"


using namespace std;

void test()
{
	try
	{
		Hypermarket hypermarket;
		for (int i = 0; i < 10; i++)
		{
			hypermarket.addProduct(new Smartphone("Apple", "IPhone", 900, 1, 2, false, Smartphone::iOS));
		}
		hypermarket.addProduct(new Notebook("Apple", "MacBook Pro", 1900, 1, 15, 1, 8, 8096));
		hypermarket.addProduct(new Notebook("Microsoft", "SurfaceBook", 1000, 1, 15, 1, 8, 8096));
		Product* prod = new Notebook("Microsoft", "SurfaceBook", 1000, 1, 15, 1, 8, 8096);
		
		prod = new Notebook("Apple", "MacBook Pro", 1900, 1, 15, 1, 8, 8096);
		//hypermarket.addProduct(prod);
		//prod = make_shared<Notebook>("Apple", "macBook", 1900, 1, 15, 1, 8, 16384);
		//hypermarket.addProduct(make_shared<Notebook>(new Notebook("Apple", "macBook", 1900, 1, 15, 1, 8, 16384)));
		//hypermarket.printProductsSHRPTR();

	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
}

Smartphone* editSmartphone(Smartphone* smart)
{
	string brand, productName;
	double price, maxDiscount;
	unsigned char maxNumOfSim;
	int osEnter;
	Smartphone::OS operationSystem;
	char agreement;
	cout << smart->getBrand() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin.ignore();
		getline(cin, brand);
		smart->setBrand(brand);
	}
	cout << smart->getProductName() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin.ignore();
		getline(cin, productName);
		smart->setProductName(productName);
	}
	cout << smart->getMaxDiscount() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin >> maxDiscount;
		smart->setMaxDiscount(maxDiscount);
	}
	cout << smart->getMaxNumberOfSim() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin >> maxNumOfSim;
		smart->setMaxNumOfSim(maxNumOfSim);
	}
	cout << smart->getPrice() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin >> price;
		smart->setPrice(price);
	}
	cout << smart->getOS() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Operation system: (1. Android. 2. iOS. 3. WindowsPhone. 4. Another) " << endl;
		cout << "Enter new value: ";
		cin >> osEnter;
		operationSystem = (osEnter <= 4 && osEnter >= 1) ? static_cast<Smartphone::OS>(osEnter) : Smartphone::OS::Unknown;
		smart->setOS(operationSystem);
	}
	return smart;
}

Notebook* editNotebook(Notebook* note)
{
	string brand, productName;
	double price, maxDiscount;
	double screenDiagonal, weight;
	unsigned int numOfCPUCores, amountOfRAM;
	char agreement;
	cout << note->getBrand() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin.ignore();
		getline(cin, brand);
		note->setBrand(brand);
	}
	cout << note->getProductName() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin.ignore();
		getline(cin, productName);
		note->setProductName(productName);
	}
	cout << note->getMaxDiscount() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin >> maxDiscount;
		note->setMaxDiscount(maxDiscount);
	}
	cout << note->getPrice() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin >> price;
		note->setPrice(price);
	}
	cout << note->getScreenDiagonal() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin >> screenDiagonal;
		note->setScreenDiagonal(screenDiagonal);
	}
	cout << note->getWeight() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin >> weight;
		note->setWeight(weight);
	}
	cout << note->getNumOfCPUCores() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin >> numOfCPUCores;
		note->setNumOfCPUCores(numOfCPUCores);
	}
	cout << note->getAmountOfRAM() << " edit? (y/n) ";
	cin >> agreement;
	if (agreement == 'Y' || agreement == 'y')
	{
		cout << "Enter new value: ";
		cin >> amountOfRAM;
		note->setAmountOfRAM(amountOfRAM);
	}
	return note;
}

Product* editProduct(Product* prod)
{
	Product* product = nullptr;
	Smartphone* smartphone = nullptr;
	Notebook* notebook = nullptr;
	cout << prod->Info();
	switch (prod->getType())
	{
	case Product::Type::Smartphone:
		smartphone = dynamic_cast<Smartphone*>(prod);
		break;
	case Product::Type::Notebook:
		notebook = dynamic_cast<Notebook*>(prod);
		break;
	default:
		throw invalid_argument("Unknown type product");
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
	return product;
}

int main()
{
	int n;
	Hypermarket hypermarket;
	BaseCustomer* customer = nullptr;
	Product* prod = nullptr;
	string brand, productName;
	double price, maxDiscount;
	bool testb = true;
	while (testb)
	{
		cout << "Choose:" << endl;
		cout << "1. Administrator" << endl;
		cout << "2. Customer" << endl;
		cout << "0. Exit" << endl;
		cin >> n;
		system("cls");
		try
		{
			bool exitCase1 = false;
			switch (n)
			{
			case 1: //Admin
				int n2;
				cout << "Hello Administrator!" << endl;
				cout << "You can add or remove some products or customers or edit product" << endl;
				cout << "What do you want to do?" << endl;
				cout << "1. Add product" << endl;
				cout << "2. Remove product" << endl; 
				cout << "3. Edit product" << endl;   // editProduct ???		
				cout << "4. Remove customer" << endl;
				cout << "5. Print products" << endl;
				cout << "0. Exit to menu" << endl;
				cin >> n2;
				system("cls");
				switch (n2)
				{
				case 1: // Add Product
					int n3;
					cout << "Which product do you want to add?" << endl;
					cout << "1. Notebook" << endl;
					cout << "2. Smartphone" << endl;
					cin >> n3;
					system("cls");
					switch (n3)
					{
					case 1: // Add Product - Notebook
						double screenDiagonal, weight;
						unsigned int numOfCPUCores, amountOfRAM;
						cout << "Enter fields of Notebook" << endl;
						cout << "Brand: ";
						cin.ignore();
						getline(cin,brand);
						cout << "Name of product: ";
						getline(cin,productName);
						cout << "Price: ";
						cin >> price;
						cout << "Max discount of product: ";
						cin >> maxDiscount;
						cout << "Screen Diagonal: ";
						cin >> screenDiagonal;
						cout << "Weight: ";
						cin >> weight;
						cout << "Amount of CPU Cores: ";
						cin >> numOfCPUCores;
						cout << "Amount of RAM (in MB): ";
						cin >> amountOfRAM;
						prod = new Notebook(brand, productName, price, maxDiscount, screenDiagonal, weight, numOfCPUCores, amountOfRAM);
						hypermarket.addProduct(prod);
						system("cls");
						break;
					case 2: // Add Product - Smartphone
						unsigned char maxNumOfSim;
						bool withContract;
						int osEnter;
						Smartphone::OS operationSystem;
						cout << "Enter fields of Smartphone" << endl;
						cout << "Brand: ";
						cin.ignore();
						getline(cin, brand);
						cout << "Name of product: ";
						getline(cin, productName);
						cout << "Price: ";
						cin >> price;
						cout << "Max discount of product: ";
						cin >> maxDiscount;
						cout << "Max number of SIM cards: ";
						cin >> maxNumOfSim;
						cout << "with contract or not (1 - true, 0 - false): ";
						cin >> withContract;
						cout << "Operation system: (1. Android. 2. iOS. 3. WindowsPhone. 4. Another)" << endl;
						cin >> osEnter;
						operationSystem = (osEnter <= 4 && osEnter >= 1) ? static_cast<Smartphone::OS>(osEnter) : Smartphone::OS::Unknown;
						prod = new Smartphone(brand, productName, price, maxDiscount, maxNumOfSim, withContract, operationSystem);
						hypermarket.addProduct(prod);
						system("cls");
						break;

					default: // Add Product default
						break;

					}
					break;
				case 2: // Remove product
					if (hypermarket.isEmptyProducts() != true)
					{
						hypermarket.printProducts();
						int pos;
						cout << "Choose product you want to remove:" << endl;
						cin >> pos;
						hypermarket.removeProduct(pos);
					}
					else
					{
						cout << "Hypermarket product list is empty!" << endl;
					}
					system("cls");
					break;
				case 3: // Edit Product
				{
					if (hypermarket.isEmptyProducts() != true)
					{
						hypermarket.printProducts();
						cout << endl << "Enter which product you wanna edit or 0 to cancel." << endl;
						int posProduct = 0;
						cin >> posProduct;
						if (posProduct < 0 || posProduct > hypermarket.getProductsAmount())
						{
							throw invalid_argument("Wrong number");
						}
						else if (posProduct == 0)
						{
							break;
						}
						else
						{
							prod = hypermarket.getProduct(posProduct);
							hypermarket.removeProduct(posProduct);
							system("cls");
							hypermarket.addProduct(editProduct(prod));
							system("cls");
						}
					}
					break;
				}
				case 4: // Remove Customer
				{
					hypermarket.printCustomers();
					cout << "Which customer you wanna remove?" << endl;
					int posCustomer = 0;
					cin >> posCustomer;
					if (posCustomer <= 0 || posCustomer > hypermarket.getCustomersAmount())
					{
						throw invalid_argument("Wrong pos!");
					}
					else
					{
						hypermarket.removeCustomer(posCustomer);
					}
					system("cls");
					break;
				}
				case 5:
					hypermarket.printProducts();
					break;
				case 0:
					exitCase1 = true;
					break;
				default: //
					break;
				}
				break;
			case 2: // Customer 
			{
				double money = 0;
				string fullName = "";
				cout << "Hello, enter your name: ";
				cin.ignore();
				getline(cin, fullName);
				cout << "Welcome to hypermarket, " << fullName << " !" << endl;
				customer = hypermarket.getCustomer(fullName);
				if (customer != nullptr)
				{
					cout <<  customer->Info();
				}
				else
				{
					cout << "Enter how much money you have: ";
					cin >> money;
					customer = new Customer(fullName, 0, money);
					hypermarket.addCustomer(customer);
				}
				hypermarket.printProducts();
				bool cart = true;
				while (cart)
				{
					cout << "Wanna add something to cart? (Y/N)" << endl;
					char agreement;
					int posProduct = 0;
					cin >> agreement;
					if (agreement == 'Y' || agreement == 'y')
					{
						cout << "Enter product number what you wanna add:";
						cin >> posProduct;
						customer->addProductToShopingList(hypermarket.getProduct(posProduct));
					}
					else
					{
						cart = false;
					}
				}
				cout << "Your cart:" << endl;
				customer->printShopingList();
				cart = true;
				while (cart)
				{
					cout << "Wanna remove something from cart? (Y/N)" << endl;
					char agreement;
					int posProduct = 0;
					cin >> agreement;
					if (agreement == 'Y' || agreement == 'y')
					{
						cout << "Enter product number what you wanna remove: ";
						cin >> posProduct;
						if (posProduct <= 0 || posProduct > customer->getAmountOfProdsAtShopingList())
						{
							throw invalid_argument("Wrong number");
						}
						else
						{
							customer->removeProductFromShopingList(posProduct);
						}
					}
					else
					{
						cart = false;
					}
				}
				customer->buyProducts();
				break;
			}
			case 0: // Exit
				exitCase1 = true;
				break;
				
			default:
				break;
			}
			if(exitCase1)
			{
				break;
			}

		}
		catch (const exception& e)
		{
			cerr << e.what() << endl;
		}
	}
	delete customer, prod;
	
	//test();

	return 0;
}