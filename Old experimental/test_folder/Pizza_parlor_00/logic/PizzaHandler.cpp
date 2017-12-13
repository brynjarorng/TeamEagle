#include "PizzaHandler.h"

PizzaHandler::PizzaHandler() {
    pizza_list = new Pizza[0];
}

PizzaHandler::~PizzaHandler() {
    delete[] pizza_list;
}
PizzaHandler::PizzaHandler (const PizzaHandler& copy) {
    this ->pizza_list_count = copy.pizza_list_count;
    delete this->pizza_list;
    pizza_list = new Pizza [pizza_list_count];
    for (int i = 0; i < pizza_list_count; i++) {
        pizza_list[i] = copy.pizza_list[i];
    }
}

bool PizzaHandler::set_name(string name, Pizza& pizzaa) {
    if(!validate_name(name)) {
        pizzaa.set_name(name);
        return true;
    }
    return false;
}

bool PizzaHandler::add_topping(string topping_name, Pizza& pizza) {
        if (toppingshandler.validate(topping_name)) {
            pizza.add_topping(toppingshandler.get_topping(topping_name));

            return true;
        }
        return false;
    }


void PizzaHandler::create_new_menu_pizza(Pizza& pizza) {
    if(validate_new_pizza(pizza)) {
        pizzarepo.write(pizza);
    }
}

void PizzaHandler::reset_pizza(Pizza& pizza) {
    Pizza new_pizza;
    pizza = new_pizza;
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

    if(pizza.get_price() < 0) {
        throw InvalidPrice();
        return false;
    }

    return true;
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

Pizza PizzaHandler::get_menu_pizza(int index) {

    Pizza remove_later;
    pizza_list_count = pizzarepo.get_list_count();
    pizza_list = pizzarepo.read();

    if(index >= 0 && index < pizza_list_count) {
        return pizza_list[index];
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

PizzaHandler& PizzaHandler::operator = (const PizzaHandler& right_side) {
    if (this-> pizza_list_count != right_side.pizza_list_count) {
        delete [] this ->pizza_list;
        pizza_list = new Pizza[right_side.pizza_list_count];
    }
    this ->pizza_list_count = right_side.pizza_list_count;
    for (int i = 0; i < right_side.pizza_list_count; i++) {
        this ->pizza_list[i] = right_side.pizza_list[i];
    }
    return *this;
}
 bool PizzaHandler::max_toppings(const Pizza& pizza) {
    if (pizza.get_toppingcount() < pizza.get_max_toppings()) {
        return false;
    }
    else {
        return true;
    }
 }
