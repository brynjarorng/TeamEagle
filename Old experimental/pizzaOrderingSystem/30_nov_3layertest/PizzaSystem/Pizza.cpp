#include "Pizza.h"

Pizza::Pizza()
{
	pizza_size = 0;
	name[0] = '\0';
	toppings[0] = '\0';
	toppingcount = 0;
}

ostream& operator << (ostream& outs,  Pizza& pizza)
{
	outs << pizza.name << " " << pizza.price;

	for (int i = 0; i < toppingcount; i++) {
        outs << " " << pizza.topping[i];
	}

	outs << endl;

	return outs;
}

void Pizza::set_name(string name)
{
    strcpy(name, this->name);
}

void Pizza::set_price(double price)
{
    this->price = price;
}

void Pizza::add_topping(Toppings topping)
{
    this->topping[toppingcount] = topping;
    toppingcount++;
}

void Pizza::get_toppingcount()
{
    return toppingcount;
}

Toppings Pizza::get_toppings()
{
    return topping;
}
