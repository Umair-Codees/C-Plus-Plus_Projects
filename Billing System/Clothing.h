#pragma once
#include "Item.h"
template<class T, class U, class V>
class Clothing :public Item<T, U, V>
{
public:
	Clothing() :Item<T, U, V>(0, 0, 0) {}
	Clothing(T n, U p, V q) :Item<T, U, V>(n, p, q) {}
	void display()const { Item<T, U, V>::display(); }
};