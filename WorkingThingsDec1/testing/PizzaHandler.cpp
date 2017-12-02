#include "PizzaHandler.h"

PizzaHandler::PizzaHandler() {
    pizza_list = new Pizza[0];
	toppings = new Toppings[0];
}

PizzaHandler::~PizzaHandler() {
    delete[] pizza_list;
}

void PizzaHandler::add_toppings() {
    string toppingname;

    for(int i = 0; i < pizza.get_max_toppings(); i++) {
    cin >> toppingname;

        if (toppingname == "q") {
            break;
        }
        if (toppingshandler.validate(toppingname)) {
            pizza.add_topping(toppingshandler.get_topping(toppingname));
        }
        else {
            cout << "Topping does not exist in database, please try again." << endl;
        }
    }
}

void PizzaHandler::create_menu_pizza() {

    string name;

    cin >> name;
    pizza.set_name(name);

    double price;
    cin >> price;
    pizza.set_price(price);

    add_toppings();

    pizzarepo.write(pizza);
}

Pizza PizzaHandler::create_pizza() {
    add_toppings();

    this ->toppings = pizza.get_toppings();
    double price = 0;

    for(int i = 0; i < pizza.get_toppingcount(); i++) {
        price += toppings[i].get_price();
    }

    pizza.set_price(price);
    pizza.set_name("Special order");

	return pizza;
}

bool PizzaHandler::validate_pizza(string pizza_name) {
    string name;

    pizza_list = pizzarepo.read();
    pizza_list_count = pizzarepo.get_list_count();
    for(int i = 0; i < pizza_list_count; i++) {
        name = pizza_list[i].get_name();
        if(name == pizza_name) {
            return true;
        }
    }
    return false;
}

Pizza PizzaHandler::get_menu_pizza(string pizza_name) {

    Pizza remove_later;

    string name;

    pizza_list = pizzarepo.read();
    pizza_list_count = pizzarepo.get_list_count();
    for(int i = 0; i < pizza_list_count; i++) {
        name = pizza_list[i].get_name();
        if(name == pizza_name) {
            return pizza_list[i];
        }
    }
    remove_later.set_name("ERRROR! NOT A PIZZA!");
    return remove_later;
}


void PizzaHandler::print_pizzas() {
    pizza_list = pizzarepo.read();

    pizza_list_count = pizzarepo.get_list_count();

    for (int i = 0; i < pizza_list_count; i++) {
        cout << pizza_list[i] << endl;
    }
}

void PizzaHandler::operator = (Pizza* copy) {
    delete[] pizza_list;
    pizza_list = copy;
}
