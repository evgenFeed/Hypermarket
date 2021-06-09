#include <iostream>
#include "Hypermarket.h"
#include "Product.h"

using namespace std;

int main()
{
	int n;
	cout << "Choose role:" << endl;
	cout << "1. Administrator" << endl;
	cout << "2. Customer" << endl;
	cin >> n;
	Hypermarket hypermarket;
	Customer* customer;
	Product* prod;
	switch (n)
	{
	case 1:
		int n2;
		cout << "Hello Administrator!" << endl; 
		cout << "You can add or remove some products or customers" << endl;
		cout << "What do you want to do?" << endl;
		cout << "1. Add product" << endl;
		cout << "2. Remove product" << endl;
		cout << "3. Add customer" << endl;
		cout << "4. Remove customer" << endl;
		cin >> n2;
		switch (n2)
		{
		case 1:
			cout << "Which product do you want to add?" << endl;
			cout << "1. Notebook" << endl;
			cout << "2. Smartphone" << endl;
			break;
		case 2:
			if (hypermarket.isEmptyProducts() != true)
			{
				
			}
			cout << "" << endl;
			break;
		case 3:
			break;
		case 4:
			break;
		default:
			break;
		}
		break;
	case 2:
		break;
	default:

		break;
	}


	return 0;
}