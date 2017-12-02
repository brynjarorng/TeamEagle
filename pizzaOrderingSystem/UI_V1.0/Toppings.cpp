#include "Toppings.h"

Toppings::Toppings() {

	name[0] = '\0';
	price = 0.0;
}

void Toppings::convert_string_cstring(string in) {
	int i = 0;
	while(i < NAME_SIZE && i < in.length())
	{
		name[i] = in[i];
		i++;
	}
	append_null(i + 1);
}

Toppings::Toppings(string name, double price) {
   	this -> price = price;
	convert_string_cstring(name);
}

string Toppings::get_name() {
	return this->name;
}

double Toppings::get_price() {
	return this->price;
}

ostream& operator << (ostream& outs, const Toppings& topping) {
	outs << topping.name  << " " << topping.price << endl;

	return outs;
}

istream& operator >> (istream& ins, Toppings& topping) {
	cout << "Topping name: ";
	ins >> topping.name;
	cout << "Topping price: ";
	ins >> topping.price;
	return ins;
}

void Toppings::append_null(int index) {
	this -> name[index - 1] = '\0';
}
