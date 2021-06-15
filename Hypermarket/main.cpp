#include <iostream>
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
		Product* prod = new Smartphone("Apple", "IPhone", -900, 1, 2, false, Smartphone::iOS);
		hypermarket.addProduct(prod);
		prod = new Notebook("Apple", "macBook", 1900, 1, 15, 1, 8, 16384);
		hypermarket.addProduct(prod);
		hypermarket.printProducts();
		delete prod;
	}
	catch (exception& e)
	{
		cerr << e.what() << endl;
	}
}

int main()
{
	int n;
	Hypermarket hypermarket;
	BaseCustomer* customer = nullptr;
	Product* prod = nullptr;
	string brand, productName;
	double price, maxDiscount;
	bool testb = false;
	while (true)
	{
		cout << "Choose role:" << endl;
		cout << "1. Administrator" << endl;
		cout << "2. Customer" << endl;
		cout << "0. Exit" << endl;
		cin >> n;
		try
		{
			bool exitCase1 = false;
			switch (n)
			{
			case 1: //Admin
				int n2;
				cout << "Hello Administrator!" << endl;
				cout << "You can add or remove some products or customers" << endl;
				cout << "What do you want to do?" << endl;
				cout << "1. Add product" << endl;
				cout << "2. Remove product" << endl;
				cout << "3. Add customer" << endl;
				cout << "4. Remove customer" << endl;
				cout << "0. Exit to menu" << endl;
				cin >> n2;
				switch (n2)
				{
				case 1: // Add Product
					int n3;
					cout << "Which product do you want to add?" << endl;
					cout << "1. Notebook" << endl;
					cout << "2. Smartphone" << endl;
					cin >> n3;
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
						cout << "Operation system: (1. Android. 2. iOS. 3. WindowsPhone. 4. Another)";
						cin >> osEnter;
						operationSystem = (osEnter <= 4 && osEnter >= 1) ? static_cast<Smartphone::OS>(osEnter) : Smartphone::OS::Unknown;
						prod = new Smartphone(brand, productName, price, maxDiscount, maxNumOfSim, withContract, operationSystem);
						hypermarket.addProduct(prod);
						break;
					default: // Add Product default

						break;

					}
					break;
				case 2: // Remove product
					if (hypermarket.isEmptyProducts() != true)
					{
						cout << "Choose product you want to remove:" << endl;
					}
					cout << "Hypermarket product list is empty!" << endl;
					break;
				case 3: // Add Customer
					break;
				case 4: // Remove Customer
					break;
				case 0:
					exitCase1 = true;
					break;
				default: //
					break;
				}
				break;
			case 2: // Customer
				break;
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
	delete prod, customer;
	test();

	return 0;
}