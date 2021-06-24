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

//Product* changeProduct(Product* prod)
//{
//
//}

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
						cin >> brand;
						cout << "Name of product: ";
						cin >> productName;
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
						char withContractEnter;
						bool withContract;
						int osEnter;
						Smartphone::OS operationSystem;
						cout << "Enter fields of Smartphone" << endl;
						cout << "Brand: ";
						cin >> brand;
						cout << "Name of product: ";
						cin >> productName;
						cout << "Price: ";
						cin >> price;
						cout << "Max discount of product: ";
						cin >> maxDiscount;
						cout << "Max number of SIM cards: ";
						cin >> maxNumOfSim;
						cout << "with contract or not (1 - true, 0 - false): ";
						cin >> withContractEnter;
						withContract = (withContractEnter == '1') ? true : false;
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
					cout << "Hypermarket product list is empty!" << endl;
					system("cls");
					break;
				case 3: // Edit Product
				{
					hypermarket.printProducts();
					cout << "Which product you wanna edit?";
					int posProduct = 0;
					cin >> posProduct;
					prod = hypermarket.getProduct(posProduct);
					hypermarket.removeProduct(posProduct);
					system("cls");
					cout << setprecision(2) << prod->Info();
					cout << endl;
					system("cls");
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