#pragma once
#include "Item.h"
template<class T, class U, class V>
class Groceries :public Item<T, U, V>
{
public:
	Groceries() :Item<T, U, V>(0, 0, 0) {}
	Groceries(T n, U p, V q) :Item<T, U, V>(n, p, q) {}
	void display()const { Item<T, U, V>::display(); }
};