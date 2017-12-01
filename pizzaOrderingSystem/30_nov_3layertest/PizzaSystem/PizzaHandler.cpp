#include "PizzaHandler.h"

PizzaHandler::PizzaHandler()
{
    pizza_list = new Pizza[0];
    toppings = new Toppings[0];
}

PizzaHandler::~PizzaHandler()
{
    delete[] pizza_list;
    delete[] toppings;
}

void PizzaHandler::create_menu_pizza()
{
    Pizza pizza;

    string name;
    cin >> name;
    pizza.set_name(name);

    double price;
    cin >> price;
    pizza.set_price(price);

    string toppingname;
    for(int i = 0; i < get_toppingcount(); i++) {
        cin >> toppingname;
        Toppings topping;
        if(topping.validate()){
            pizza.add_topping(topping.get_topping(toppingname));
        }
        else {
            cout << "Topping does not exist in database";
        }
    }

    pizzarepo.write(pizza);

}

Pizza PizzaHandler::create_pizza()
{
    Pizza pizza;

    string toppingname;
    for(int i = 0; i < get_toppingcount(); i++) {
        cin >> toppingname;
        Toppings topping;
        if(topping.validate()){
            pizza.add_topping(topping.get_topping(toppingname));
        }
        else {
            cout << "Topping does not exist in database";
        }
    }

    toppings = pizza.get_toppings();
    double price = 0;

    for(int i = 0; i < pizza.get_toppingcount(); i++) {
        price += toppings[i].get_price();
    }

    pizza.set_price(price);
    pizza.set_name("Special order");

}

void PizzaHandler::print_pizzas()
{
    pizza_list = repo.read();

    pizza_list_count = repo.get_list_count();

    for (int i = 0; i < toppings_list_size; i++) {
        cout << topping_list[i] << endl;
    }
}

void PizzaHandler::operator = (Pizza* copy)
{
    delete[] pizza_list;
    pizza_list = copy;
}

void PizzaHandler::operator = (Toppings* copy)
{
    delete[] toppings;
    toppings = copy;
}
