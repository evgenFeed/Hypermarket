#include <iostream>
#include <memory>
#include <iomanip>
#include "Hypermarket.h"
#include "Product.h"
#include "Notebook.h"
#include "Smartphone.h"
#include "RegularCustomer.h"

using namespace std;

int main()
{
    int n;
    Hypermarket hypermarket;
    BaseCustomer* customer = nullptr;
    Product* prod = nullptr;
    string brand, productName;
    double price, maxDiscount;
    while (true)
    {
        cout << "Choose role:" << endl;
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
                cout << "3. Edit product" << endl; // editProduct ???
                cout << "4. Remove customer" << endl;
                cout << "5. Print products" << endl;
                cout << "0. Exit to menu" << endl;
                cin >> n2;
                system("cls");
                switch (n2)
                {
                case 1: // Add Product
                {
                    int n3;
                    cout << "Which product do you want to add?" << endl;
                    cout << "1. Notebook" << endl;
                    cout << "2. Smartphone" << endl;
                    cout << "3. Mobile Phone" << endl;
                    cin >> n3;
                    system("cls");
                    switch (n3)
                    {
                    case 1: // Add Product - Notebook
                    {
                        double screenDiagonal, weight;
                        unsigned int numOfCPUCores, amountOfRAM;
                        cout << "Enter fields of Notebook" << endl;
                        cout << "Brand: ";
                        cin.ignore();
                        getline(cin, brand);
                        cout << "Name of product: ";
                        getline(cin, productName);
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
                    }
                    case 2: // Add Product - Smartphone
                    {
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
                        cout << "Pre installed programs: (n to continue)" << endl;
                        vector<string> installedPrograms;
                        string program = "";
                        cin.ignore();
                        while (program != "n")
                        {
                            getline(cin, program);
                            if (program != "n")
                            {
                                installedPrograms.push_back(program);
                            }
                        }
                        prod = new Smartphone(brand, productName, price, maxDiscount, maxNumOfSim, withContract, operationSystem, installedPrograms);
                        hypermarket.addProduct(prod);
                        system("cls");
                        break;
                    }
                    case 3: // Add Mobile Phone
                    {
                        unsigned char maxNumOfSim;
                        bool withContract;
                        cout << "Enter fields of Mobile Phone" << endl;
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
                        prod = new MobilePhone(brand, productName, price, maxDiscount, maxNumOfSim, withContract);
                        hypermarket.addProduct(prod);
                        system("cls");
                        break;
                    }
                    default: // Add Product default
                        break;
                    }
                    break;
                }
                case 2: // Remove product
                    if (hypermarket.isEmptyProducts() != true)
                    {
                        hypermarket.printProducts();
                        int pos;
                        cout << "Choose product you want to remove:" << endl;
                        cin >> pos;

                        hypermarket.removeProduct(pos);
                        system("cls");
                    }
                    else
                    {
                        cout << "Hypermarket product list is empty!" << endl;
                    }
                    break;
                case 3: // Edit Product
                {
                    if (hypermarket.isEmptyProducts() != true)
                    {
                        hypermarket.printProducts();
                        cout << endl
                             << "Enter position which product you wanna edit or 0 to cancel." << endl;
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
                            hypermarket.addProduct(hypermarket.editProduct(prod));
                            system("cls");
                        }
                    }
                    else
                    {
                        cout << "Hypermarket product list is empty!" << endl;
                    }
                    break;
                }
                case 4: // Remove Customer
                {
                    if (hypermarket.isEmptyCustomers() != true)
                    {
                        hypermarket.printCustomers();
                        cout << "Which customer you wanna remove?" << endl;
                        int posCustomer = 0;
                        cin >> posCustomer;
                        if (posCustomer <= 0 || posCustomer > hypermarket.getCustomersAmount())
                        {
                            throw invalid_argument("Wrong number!");
                        }
                        else
                        {
                            hypermarket.removeCustomer(posCustomer);
                        }
                        system("cls");
                    }
                    else
                    {
                        cout << "Hypermarket customer list is empty!" << endl;
                    }
                    break;
                }
                case 5:
                    if (hypermarket.isEmptyProducts() != true)
                    {
                        hypermarket.printProducts();
                    }
                    else
                    {
                        cout << "Hypermarket product list is empty!" << endl;
                    }
                    break;
                case 0:
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
                    cout << customer->Info();
                }
                else
                {
                    cout << "Enter how much money you have: ";
                    cin >> money;
                    customer = new Customer(fullName, 0, money);
                    hypermarket.addCustomer(customer);
                }
                if (hypermarket.isEmptyProducts() != true)
                {
                    cout << "List of products in hypermarket: " << endl;
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
                    cout << "Your cart: " << endl;
                    if (customer->getAmountOfProdsAtShopingList() == 0)
                    {
                        cout << "is empty!" << endl;
                        ;
                    }
                    else
                    {
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
                            if (customer->getPurchases() >= 1 && !customer->isRegular())
                            {
                                BaseCustomer* new_customer = new RegularCustomer(customer->getName(), customer->getTotalCostBought(), customer->getBalance(), customer->getPurchases());
                                new_customer->setShopingList(customer->getShopingList());
                                hypermarket.removeCustomer(customer);
                                customer = new_customer;
                                hypermarket.addCustomer(customer);
                            }
                            customer->buyProducts();
                            customer->clearShopingList();
                        }
                    }
                }
                else
                {
                    cout << "There are no products in the hypermarket yet" << endl;
                }
                break;
            }
            case 0: // Exit
                exitCase1 = true;
                break;

            default:
                break;
            }
            if (exitCase1)
            {
                break;
            }
        }
        catch (const exception& e)
        {
            cerr << e.what() << endl;
            customer->clearShopingList();
        }
    }
    
    return 0;
}