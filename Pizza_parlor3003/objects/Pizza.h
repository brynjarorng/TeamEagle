#ifndef PIZZA_H
#define PIZZA_H
#include "PizzaStatus.h" //{pending, baking, ready}.
#include "PizzaBottom.h"
#include "Toppings.h"
#include <string.h>

using namespace std;

class Pizza
{
public:
    Pizza();
	//Initializes name to the empty string, toppingcount = 0, name_count = 0
	//and price = 0.0. and PizzaStatus to pending.
    friend istream& operator >> (istream& ins, Pizza& pizza);
	//Instream is the name of pizza, price of pizza and a selection of toppings, respectively.
    friend ostream& operator <<(ostream& outs, Pizza& pizza);
	//THIS OUTSTREAM IS ONLY FOR TESTING;
    void set_name(string name);
	//Sets this-name equal to name (also, name is converted to a char array of a fixed size
	//so that if input is larger than this fixed size, the array will only contain the first
	//n characters of name of the string type).
    void set_price(double price);
	//Sets this->price equal to price
	void set_price(string price);
	//Sets this->price equal to price
    void add_topping(Toppings topping);
	//The refrence topping is added to this instance of Pizza.
    int get_toppingcount() const;
	//Returns the number of toppings of this pizza.
    Toppings* get_toppings();
	//Returns an array of the toppings this pizza contains.
	string get_toppings_print(Pizza& pizza);
	//Returns a printable list of all of the toppings
	int get_max_toppings() const;
	//Return value is the maximum allowed topping on pizza.
	void set_status(PizzaStatus status);
	//Sets the pizza to pending, baking or ready.
	double get_price();
	//Returns the price of this instance of pizza.
	string get_name();
	//Returns the name of this instance of pizza
	string get_status();
	//Returns the status of pizza as string.
	PizzaBottom get_bottom();
	void set_bottom(PizzaBottom& bottom);

private:

	double price;
	PizzaBottom bottom;

	static const int MAX_NAME_SIZE = 50;
	char name[MAX_NAME_SIZE];
	int name_count;

	static const int MAX_TOPPINGS = 80;
	Toppings topping[MAX_TOPPINGS];
    int toppingcount;
    PizzaStatus status;
	//Current status of the pizza is used by the order handling system.
	//Choose from pending, baking or ready.
	void append_null();
	//Appends '\0' to name[name_count - 1];

};

#endif // PIZZA_H
