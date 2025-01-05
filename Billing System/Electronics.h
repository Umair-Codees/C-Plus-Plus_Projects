#pragma once
#include "Item.h"
template<class T, class U, class V>
class Electronics :public Item<T, U, V>
{
public:
	Electronics() :Item<T, U, V>(0, 0, 0) {}
	Electronics(T n, U p, V q) :Item<T, U, V>(n, p, q) {}
	void display()const { Item<T, U, V>::display(); }
};