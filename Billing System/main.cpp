#include <iostream>
#include <string>
#include "Item.h"
#include "Groceries.h"
#include "Electronics.h"
#include "Clothing.h"
#include "BillingSystem.h"
using namespace std;

void menu(BillingSystem<string, double, int>obj);
void MenuAddItem(BillingSystem<string, double, int>obj);

int main()
{
	BillingSystem<string, double, int>b;
	
	menu(b);
	
	return 0;
}

void menu(BillingSystem<string, double, int>obj)
{
	int count = 0;
	char choice, more;

	system("cls");
	cout << "\n\t\t.......Wellcome To Billing System.......\n\n";
	cout << "\t\tA -> Add Item\n";
	cout << "\t\tD -> Delete Item\n";
	cout << "\t\tS -> Show All Items\n";
	cout << "\t\tE -> Exit\n";

	while (true)
	{
		cout << "\n\t\tEnter Your Choice..) ";
		cin >> choice;

		if (choice == 'a' || choice == 'A')
		{
			MenuAddItem(obj);
		}
		else if (choice == 'd' || choice == 'D')
		{
			int num;
			while (true)
			{
				system("cls");

				//Display All Items
				cout << "\n\t....... Menu .......\n\n";
				cout << "..........................................\n";
				cout << "Item Name\tQuantity\tPrice\n";
				cout << "..........................................\n";
				obj.display();
				cout << "..........................................\n";
				cout << "\n\tEnter Item No. For Deleting. ..)";
				cin >> num;

				if (obj.DeleteItem(num) == 1)
				{
					cout << "\nItem Delete Successfully!\n";

					while (true)
					{
						cout << "\n\t\tDo You Want Delete More Item[Y/N]..)";
						cin >> more;

						if (more == 'y' || more == 'Y')
						{
							menu(obj);
							break;
						}
						else if (more == 'n' || more == 'N')
						{
							menu(obj);
							break;
						}
						else
						{
							cout << "\n\t\tInvalid Input!\n";
						}
					}
					break;
				}
				else
				{
					cout << "\n\t....Item Not Found!!.....\n";
					break;
				}
			}
			break;
		}
		else if (choice == 's' || choice == 'S')
		{
			system("cls");
			cout << "\n\t....... Menu .......\n\n";
			cout << "..........................................\n";
			cout << "Item Name\tQuantity\tPrice\n";
			cout << "..........................................\n";
			obj.display();
			cout << "..........................................\n";
			break;
		}
		else if (choice == 'e' || choice == 'E')
		{
			system("cls");

			cout << "\n\t\tExiting....\n";

			break;
		}
		else if (count == 5)
		{
			menu(obj);
		}
		else
		{
			cout << "\n\t\tInvalid Input!\n";
			count++;
		}
	}
}
void MenuAddItem(BillingSystem<string, double, int>obj)
{
	int count = 0;
	string name;
	int quantity = 0;
	double price = 0.0;
	char type, more;
	
	system("cls");

	cout << "\n\t\t.....Add Item In Billing System.....\n\n";
	cout << "\t\tG -> Groceries Item\n";
	cout << "\t\tC -> Clothing Item\n";
	cout << "\t\tE -> Electronics Items\n";
	cout << "\t\tB -> Back\n";

	while (true)
	{
		cout << "\n\t\tEnter Item Type..) ";
		cin >> type;

		if (type == 'g' || type == 'G')
		{
			system("cls");

			cout << "\n\t\t.......Add Groceries.......\n\n";
			cin.ignore();
			cout << "\n\t\tEnter Grocery Name..) ";
			getline(cin, name);

			cout << "\t\tEnter Grocery Quantity..) ";
			cin >> quantity;

			cout << "\t\tEnter Grocery Price..) ";
			cin >> price;

			Groceries<string, double, int>* newItem = new Groceries<string, double, int>(name, price, quantity);
			obj.AddItem(newItem);

			while (true)
			{
				cout << "\n\t\tDo You Want Add More Item[Y/N]..)";
				cin >> more;

				if (more == 'y' || more == 'Y')
				{
					MenuAddItem(obj);
				}
				else if (more == 'n' || more == 'N')
				{
					system("cls");
					cout << "\n\t\t....Exiting!!....\n";
					menu(obj);
				}
				else
				{
					cout << "\n\t\tInvalid Input!\n";
				}
				break;
			}

			break;
		}
		else if (type == 'c' || type == 'C')
		{
			system("cls");

			cout << "\n\t\t.......Add Clothing Item.......\n\n";
			cin.ignore();
			cout << "\t\tEnter Clothing Name..) ";
			getline(cin, name);

			cout << "\t\tEnter Clothing Quantity..) ";
			cin >> quantity;

			cout << "\t\tEnter Clothing Price..) ";
			cin >> price;

			Clothing<string, double, int>* newItem = new Clothing<string, double, int>(name, price, quantity);
			obj.AddItem(newItem);

			while (true)
			{
				cout << "\n\t\tDo You Want Add More Item[Y/N]..)";
				cin >> more;

				if (more == 'y' || more == 'Y')
				{
					MenuAddItem(obj);
				}
				else if (more == 'n' || more == 'N')
				{
					system("cls");
					cout << "\n\t\tExiting!!\n";
					menu(obj);
					break;
				}
				else
				{
					cout << "\n\t\tInvalid Input!\n";
				}
			}

			break;
		}
		else if (type == 'e' || type == 'E')
		{
			system("cls");

			cout << "\n\t\t.......Add Electronics Item.......\n\n";
			cin.ignore();
			cout << "\t\tEnter Electronics Name..) ";
			getline(cin, name);

			cout << "\t\tEnter Electronics Quantity..) ";
			cin >> quantity;

			cout << "\t\tEnter Electronics Price..) ";
			cin >> price;

			Electronics<string, double, int>* newItem = new Electronics<string, double, int>(name, price, quantity);
			obj.AddItem(newItem);

			while (true)
			{
				cout << "\n\t\tDo You Want Add More Item[Y/N]..)";
				cin >> more;

				if (more == 'y' || more == 'Y')
				{
					MenuAddItem(obj);
				}
				else if (more == 'n' || more == 'N')
				{
					system("cls");
					cout << "\n\t\tExiting!!\n";
					menu(obj);
					break;
				}
				else
				{
					cout << "\n\t\tInvalid Input!\n";
				}
			}

			break;
		}
		else if (type == 'b'|| type == 'B')
		{
			menu(obj);
			break;
		}
		else if (count == 5)
		{
			MenuAddItem(obj);
		}
		else
		{
			cout << "\n\t\tInvalid Input!\n";
			count++;
		}
	}
}