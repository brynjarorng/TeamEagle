#include "PizzaHandler.h"

PizzaHandler::PizzaHandler() {
    pizzas = pizza_repo.read();
}

PizzaHandler::~PizzaHandler() {
}

bool PizzaHandler::set_name(string name, Pizza& pizzaa) {
    if(!validate_name(name)) {
        pizzaa.set_name(name);
        return true;
    }
    return false;
}

void PizzaHandler::add_topping(string topping_name, Pizza& pizza) {
    if (toppingshandler.validate(topping_name)) {
        pizza.add_topping(toppingshandler.get_topping(topping_name));
    }
    throw InvalidName();
}


void PizzaHandler::create_new_menu_pizza(Pizza& pizza) throw(InvalidName, InvalidPrice) {
    if(!validate_name(pizza.get_name())) {
        throw InvalidName();
    }
    if(!validate_price(pizza.get_price())) {
        throw InvalidPrice();
    }

    pizza_repo.write(pizza);
    pizzas.push_back(pizza);
}

void PizzaHandler::reset_pizza(Pizza& pizza) {
    Pizza new_pizza;
    pizza = new_pizza;
}

double PizzaHandler::calc_price(Pizza& pizza) {
    double price;

    Toppings* topp = pizza.get_toppings();

    for(int i = 0; i < pizza.get_toppingcount(); i++) {
        price += topp[i].get_price();
    }

    return price;
}

void PizzaHandler::create_special_pizza(Pizza& pizza) {
    double price = 0;
    Toppings* top = pizza.get_toppings();
    int toppingscount = pizza.get_toppingcount();

    for(int i = 0; i < toppingscount; i++) {
        price += top[i].get_price();
    }

    pizza.set_price(price);
    pizza.set_name("Special order");
}

bool PizzaHandler::validate_name(string pizza_name) {
    string name;

    for(unsigned int i = 0; i < pizzas.size(); i++) {
        name = pizzas.at(i).get_name();
        if(name == pizza_name) {
            return false;
        }
    }
    return true;
}

bool PizzaHandler::validate_price(double price) {
    if(price < 0) {
        return false;
    }

    return true;
}


/*
bool PizzaHandler::validate_new_pizza(Pizza& pizza) throw(InvalidName, InvalidPrice){
    string list_name;
    string name = pizza.get_name();
    pizza_list = pizzarepo.read();

    pizza_list_count = pizzarepo.get_list_count();
    for(int i = 0; i < pizza_list_count; i++) {
        list_name = pizza_list[i].get_name();
        if(name == list_name) {
            throw InvalidName();
            return false;
        }
    }


}
*/
Pizza PizzaHandler::get_menu_pizza(string pizza_name) {
    string name;

    for(unsigned int i = 0; i < pizzas.size(); i++) {
        name = pizzas.at(i).get_name();
        if(name == pizza_name) {
            return pizzas.at(i);
        }
    }
    throw InvalidName();
}

Pizza PizzaHandler::get_menu_pizza(int index) {

    return pizzas.at(index);

}


/*
void PizzaHandler::print_pizzas() {
    pizza_list = pizzarepo.read();

    pizza_list_count = pizzarepo.get_list_count();

    for (int i = 0; i < pizza_list_count; i++) {
        cout << pizza_list[i] << endl;
    }
}
*/

 bool PizzaHandler::max_toppings(const Pizza& pizza) {
    if (pizza.get_toppingcount() < pizza.get_max_toppings()) {
        return false;
    }
    else {
        return true;
    }
 }

vector<Pizza> PizzaHandler::PizzaHandler::get_pizza_list(){
    return pizzas;
 }
