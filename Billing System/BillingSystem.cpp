#include <iostream>
#include <string>
#include "BillingSystem.h"
using namespace std;
template class BillingSystem<string, double, int>;
template class Item<string, double, int>;
template<class T, class U, class V>
BillingSystem<T, U, V>::BillingSystem()
{
	arr[0] = new Groceries<T, U, V>{ "Chocolate",100,5 };
	arr[1] = new Clothing<T, U, V>{ "Polo T-Shirt",3300,2 };
	arr[2] = new Electronics<T, U, V>{ "Dell Laptop",900000,1 };
}
template<class T, class U, class V>
void BillingSystem<T, U, V>::AddItem(Item<T, U, V>* obj)
{
	if (size < maxSize)
	{
		cout << "\n\t\tItem Add Successfully!\n";
		arr[size] = obj;
		size++;
	}
	else
	{
		cout << "Billing System Full. Cannot add more items.\n";
	}
}
template<class T, class U, class V>
bool BillingSystem<T, U, V>::DeleteItem(int i)
{
	if (i >= 0 && i < size)
	{
		cout << "..........................................\n";
		cout << "Item Name\tQuantity\tPrice\n";
		cout << "..........................................\n";
		arr[i]->display();
		cout << "\n..........................................\n";

		delete arr[i];
		
		for (int j = i; j < size - 1; j++)
		{
			arr[j] = arr[j + 1];
		}

		arr[size - 1] = nullptr;
		size--;

		return true;
	}
	else
	{
		return false;
	}
}
template<class T, class U, class V>
void BillingSystem<T, U, V>::display()const
{
	for (int i = 0; i < size; i++)
	{
		arr[i]->display();
	}
}
template<class T, class U, class V>
BillingSystem<T, U, V>::~BillingSystem()
{
	for (int i = 0; i < size; ++i)
	{
		delete arr[i];
	}
}