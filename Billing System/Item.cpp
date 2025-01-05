#include <iostream>
#include <string>
#include "Item.h"
using namespace std;
template class Item<string, double, int>;
//Default Constructor
template<class T, class U, class V>
Item<T, U, V>::Item()
{
	name = T();
	price = U();
	quantity = V();
}
//Parameterized Constructor
template<class T, class U, class V>
Item<T, U, V>::Item(T n, U p, V q)
{
	name = n;
	price = p;
	quantity = q;
}
//Setter
template<class T, class U, class V>
void Item<T, U, V>::setName(T n)
{
	name = n;
}
template<class T, class U, class V>
void Item<T, U, V>::setPrice(U p)
{
	price = p;
}
template<class T, class U, class V>
void Item<T, U, V>::setQuantity(V q)
{
	quantity = q;
}
//Getter
template<class T, class U, class V>
T Item<T, U, V>::getName()const
{
	return name;
}
template<class T, class U, class V>
U Item<T, U, V>::getPrice()const
{
	return price;
}
template<class T, class U, class V>
V Item<T, U, V>::getQuantity()const
{
	return quantity;
}
//Display
template<class T, class U, class V>
void Item<T, U, V>::display()const
{
	cout << name << "\t   " << quantity << "\t\t" << price << endl;
}
template class Item<std::string, double, int>;