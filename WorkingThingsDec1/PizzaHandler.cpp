#include "PizzaHandler.h"

PizzaHandler::PizzaHandler() {
    pizza_list = new Pizza[0];
	toppings = new Toppings[0];
}

PizzaHandler::~PizzaHandler() {
    delete[] pizza_list;
}

void PizzaHandler::create_menu_pizza() {

	Pizza pizza;

    string name;
    cin >> name;
    pizza.set_name(name);

    double price;
    cin >> price;
    pizza.set_price(price);
	
    string toppingname;
	//Temporary solution:10 is set as count limit and
	//q is set for quit.
    for(int i = 0; i < 10 ; i++) {
   		cin >> toppingname;
		if (toppingname == "q") {
			break;
		}
        if (toppingshandler.validate(toppingname)) {
            pizza.add_topping(toppingshandler.get_topping(toppingname));
        }
        else {
            cout << "Topping does not exist in database, please try again."
				 << endl;
        }
    }
	
    pizzarepo.write(pizza);
}

Pizza PizzaHandler::create_pizza()
{
    string toppingname;
    for(int i = 0; i < 10; i++) {
        cin >> toppingname;

		if ( toppingname == "q") {
			break;
		}
		
        if(toppingshandler.validate(toppingname)){

		   pizza.add_topping(toppingshandler.get_topping(toppingname));
			
        }
        else {
            cout << "Topping does not exist in database";
        }
    }
    this ->toppings = pizza.get_toppings();
    double price = 0;

    for(int i = 0; i < pizza.get_toppingcount(); i++) {
        price += toppings[i].get_price();
		}

    pizza.set_price(price);
    pizza.set_name("Special order");

	return pizza;
}

void PizzaHandler::print_pizzas() {
    pizza_list = pizzarepo.read();

    pizza_list_count = pizzarepo.get_list_count();

    for (int i = 0; i < pizza_list_count; i++) {
        cout << pizza_list[i] << endl;
    }
}

void PizzaHandler::operator = (Pizza* copy)
{
    delete[] pizza_list;
    pizza_list = copy;
}


