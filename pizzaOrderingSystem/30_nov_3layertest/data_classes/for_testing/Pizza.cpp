#include "Pizza.h"

Pizza::Pizza(){
	pizza_size = 12;
}
ostream& operator <<(ostream& outs,  Pizza& pizza)
{
	string name_temp;
	outs << "Name:" << pizza.name << endl
		 << "Size: "<< pizza.pizza_size << endl;
	outs << "Toppings:" << endl;
	for (unsigned int i = 0; i < pizza.dummy_index; i++) {
		name_temp = pizza.toppings[i].get_name();
		outs << name_temp << " ";
	}
	outs << endl;
	return outs;
}
Pizza::Pizza(int size, double price,  string name){
    this -> price = price;
    this -> pizza_size = size;
   
    this -> name = name;
}
void Pizza::make_pizza()
{
	int index = 0;
	char index_of_topping = '\0';
	cout << "Enter name of pizza: ";
	cin >> this ->name;
	
	cout << "Select size: ";
	cin >> this -> pizza_size;

	Toppings temp;
	print_dummy_list();
	cin >> index_of_topping;
	while (index_of_topping != 'q') {
		int index = static_cast<int>(index_of_topping) - static_cast<int>('0');
		index--;
		if (index <= dummy_list.size()) {
			temp = dummy_list[index];
			toppings.push_back(temp);
		}
		else
		{
			cout << "Pizza not on list" << endl;
		}
		cin >> index_of_topping;
	}
}
istream& operator >> (istream& ins, Pizza& pizza)
{
	ins >> pizza.cname >> pizza.price;
	return ins;
}
void Pizza::set_price(){
    this -> price = price;
}
void Pizza::set_topping(){
	//Here will be a function so the current
	//toppings list will be printed to the screen.
   
}
void Pizza::print_dummy_list()
{
	Toppings pepp("Pepperoni", 150), svepp("Mushrooms", 200), cheese("cheese", 100);
		
	dummy_list.push_back(pepp);
	dummy_list.push_back(svepp);
	dummy_list.push_back(cheese);
	dummy_index = 3;
	cout << "Select from the following toppings,\n"
		 << "press (q) " << "when finished." << endl;
	for (unsigned int i = 0; i < dummy_index; i++) {

		cout << "(" <<(i + 1) << ")" << " for " << dummy_list[i].get_name() << endl;
	}

	
	cout << "Enter your choice: " << endl;
}

