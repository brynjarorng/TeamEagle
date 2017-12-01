#include "PizzaHandler.h"

PizzaHandler::PizzaHandler()
{
    pizza_list = new Pizza[0];
}

PizzaHandler::~PizzaHandler()
{
    delete[] pizza_list;
}

void PizzaHandler::create_pizza()
{
    Pizza pizza;
    cin >> pizza;

    pizzarepo.write(pizza);
}

void PizzaHandler::print_pizzas()
{
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
