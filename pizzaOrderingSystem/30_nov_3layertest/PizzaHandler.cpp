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

    repo.write(pizza);
}

void PizzaHandler::print_pizzas()
{
    pizza_list = repo.read();

    pizza_list_count = repo.get_list_count();

    for (int i = 0; i < toppings_list_size; i++) {
        cout << topping_list[i] << endl;
    }
}

void PizzaHandler::operator = (Pizzas* copy)
{
    delete[] pizza_list;
    pizza_list = copy;
}
