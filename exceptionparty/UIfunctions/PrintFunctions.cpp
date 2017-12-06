#include "PizzaHandler.h"
#include "ToppingsHandler.h"
#include "OrderHandler.h"

void print_menu_pizzas() {

    PizzaHandler handler;
    PizzaRepo repo;

    vector<Pizza> pizza_vector = handler.get_menu_list();

    for(int i = 0; i < pizza_vector.size(); i++) {
        cout << pizza_vector.at(i);
    }
}

