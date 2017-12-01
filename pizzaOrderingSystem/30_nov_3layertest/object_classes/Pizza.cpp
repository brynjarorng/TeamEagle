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
        outs << " " << pizza.toppings;
	}

	outs << endl;

	return outs;
}

istream& operator >> (istream& ins, Pizza& pizza)
{
	ins >> pizza.name >> pizza.price;


	string topping = "";

    for(int i = 0; i < MAX_TOPPINGS; i++) {
        cin >> topping;

        if(topping == "q"){
            break;
        }

        pizza.toppingcount++;
        cin >> topping >> 0;
    }
    // Temp solution, takes only topping name with default price 0.

	return ins;
}

