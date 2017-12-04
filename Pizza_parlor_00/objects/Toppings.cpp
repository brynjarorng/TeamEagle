#include "Toppings.h"

Toppings::Toppings(){

	name[0] = '\0';
	price = 0.0;
}
void Toppings::convert_string_cstring(string in) {
	unsigned int i = 0;
	while( i < NAME_SIZE && i < in.length())
	{
		this ->name[i] = in[i];
		i++;
	}
	append_null(i + 1);
}
Toppings::Toppings(string name, double price)
{
   	this -> price = price;
	convert_string_cstring(name);
}
string Toppings::get_name()
{
	return this->name;
}
double Toppings::get_price()
{
	return this->price;
}

void Toppings::set_name(string name) {
    convert_string_cstring(name);
}

void Toppings::set_price(double price) {
    this ->price = price;
}

ostream& operator << (ostream& outs, const Toppings& topping)
{
	outs << topping.name  << " " << topping.price << endl;

	return outs;
}

istream& operator >> (istream& ins, Toppings& topping)
{
	cout << "Topping name: ";
	ins >> topping.name;
	cout << "Topping price: ";
	ins >> topping.price;
	return ins;
}
void Toppings::append_null(int index)
{
	this -> name[index - 1] = '\0';
}


/*string Toppings::namegame()
{
	string return_string;
	int i = 0;
	while(name[i] != '\0')
	{
		return_string[i] = name[i];
		i++;
	}
	return return_string;
	}*/

