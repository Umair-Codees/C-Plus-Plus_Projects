#pragma once
#include <iostream>
#include <string>
#include "Item.h"
#include "Groceries.h"
#include "Clothing.h"
#include "Electronics.h"
using namespace std;
template<class T, class U, class V>
class BillingSystem
{
	static const int maxSize = 10;
	int size = 3;
	Item<T, U, V>* arr[maxSize];
public:
	BillingSystem();
	void AddItem(Item<T, U, V>* obj);
	bool DeleteItem(int i);
	void display()const;
	~BillingSystem();
};