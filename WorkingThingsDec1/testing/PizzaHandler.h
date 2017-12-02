#ifndef PIZZAHANDLER_H_INCLUDED
#define PIZZAHANDLER_H_INCLUDED
#include "ToppingsHandler.h"
#include "PizzaRepo.h"

class PizzaHandler
{
public:
    PizzaHandler();
    //Copy constructor
    ~PizzaHandler();
    void create_menu_pizza();
    //Creates pizza and sends it to the menu pizza repository.
    Pizza create_pizza();
    //Creates a special order pizza and returns it to caller.
    void print_pizzas();
    //Fetches list of pizzas from the repo and prints it to the screen.
    void operator = (Pizza* copy);
    //Overloading the = operator for dynamic array handling.
    void add_toppings();
    //Gets user input of a topping name, and checks if it exists,
    //if it does it'll be added to the pizza.
    //Loops until maximum topping number is reached or until user inputs "q".
private:

    Pizza pizza;
    PizzaRepo pizzarepo;
    ToppingsHandler toppingshandler;
	Toppings* toppings;
    Pizza* pizza_list;
    int pizza_list_count;

};

#endif // PIZZAHANDLER_H_INCLUDED
