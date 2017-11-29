#include "toppings.h"
Toppings::Toppings()
{
	
}
/*Toppings::Toppings(char cname[], int price)
{
	this -> cname = 'k';
	this -> name = name;
	//namegame();
}
*/
ostream& operator << (ostream& outs, const Toppings& topping)
{
	outs << topping.cname << " " << topping.price << endl;

	return outs;
}

istream& operator >> (istream& ins, Toppings& topping)
{
	ins >> topping.cname >> topping.price;
	return ins;
}
/*
void Toppings::namegame()
{
	for (int i = 0; i < name.size(); i++) {
		cname[i] = name[i];
	}
	//strcpy(name, cname);
}
*/
