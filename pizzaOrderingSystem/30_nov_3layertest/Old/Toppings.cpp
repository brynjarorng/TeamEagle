#include "Toppings.h"

Toppings::Toppings(){

	cname[0] = '\0';
	price = 0.0;
}
void Toppings::convert_string_cstring(string in)
{
	int i = 0;
	while(i < CNAME_SIZE && i < in.length())
	{
		cname[i] = in[i];
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
	return cname;
}

ostream& operator << (ostream& outs, const Toppings& topping)
{
	outs << topping.cname << " " << topping.price << endl;

	return outs;
}

istream& operator >> (istream& ins, Toppings& topping)
{
	ins >> topping.cname;
	ins >> topping.price;
	return ins;
}
void Toppings::append_null(int index)
{
	cname[index - 1] = '\0';
}
/*string Toppings::namegame()
{
	string return_string;
	int i = 0;
	while(cname[i] != '\0')
	{
		return_string[i] = cname[i];
		i++;
	}
	return return_string;
	}*/
