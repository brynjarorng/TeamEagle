#include "Toppings.h"

Toppings::Toppings(string  name, int price)
{
	this -> price = price;
	this -> name = name;
	namegame();
}

ostream& operator << (ostream& outs, const Toppings& topping)
{
	outs << topping.cname << " " << topping.price << endl;

	return outs;
}

friend istream& operator >> (istream& ins, Toppings& topping)
{
	ins >> topping.name >> topping.price;
	return ins;
}

void Toppings::namegame()
{
t	strcpy(name, cname);
}
