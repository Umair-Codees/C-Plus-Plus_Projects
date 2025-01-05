#ifndef ITEM_H
#define ITEM_H
#pragma once
#include <string>
template<class T, class U, class V>
class Item
{
	T name;
	U price;
	V quantity;
public:
	//Default Constructor
	Item();
	//Parameterized Constructor
	Item(T n, U p, V q);
	//Setter
	void setName(T n);
	void setPrice(U p);
	void setQuantity(V q);
	//Getter
	T getName()const;
	U getPrice()const;
	V getQuantity()const;
	//Display
	virtual void display()const;
};
#endif