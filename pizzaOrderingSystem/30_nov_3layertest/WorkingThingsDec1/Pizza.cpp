#include "Pizza.h"

Pizza::Pizza() {
	//pizza_size = 0;
	name[0] = '\0';
	toppingcount = 0;
	name_count = 0;
	price = 0.0;
}

ostream& operator << (ostream& outs,  Pizza& pizza) {
	outs << pizza.name << " " << pizza.price;

	for (int i = 0; i < pizza.toppingcount; i++) {
	  outs << " " << pizza.topping[i].get_name();
	}

	outs << endl;

	return outs;
}

istream& operator >> (istream& ins, Pizza& pizza) {

	ins >> pizza.name >> pizza.price;
	Toppings topping("Sveppir", 23);
	pizza.add_topping(topping);
	//pizza.add_topping();
	return ins;
}

void Pizza::set_name(string name)
{
	int size_of_string = name.length();
	if (size_of_string <= MAX_NAME_SIZE) {
		name_count = (size_of_string);
	}
	else {
		name_count = (MAX_NAME_SIZE);
	}
	strncpy(this ->name, name.c_str(), MAX_NAME_SIZE);
	
	append_null();

}
void Pizza::append_null() {
	name[name_count] = '\0';
}
void Pizza::set_price(double price) {
    this->price = price;
}

void Pizza::add_topping(Toppings topping) {
    this->topping[toppingcount] = topping;
    toppingcount++;
}

int Pizza::get_toppingcount() {
    return this->toppingcount;
}

Toppings* Pizza::get_toppings() {
	
	return this ->topping;
}
