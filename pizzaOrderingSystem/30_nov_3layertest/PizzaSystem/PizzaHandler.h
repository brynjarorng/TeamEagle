#ifndef PIZZAHANDLER_H_INCLUDED
#define PIZZAHANDLER_H_INCLUDED
#include "Pizza.h"

class PizzaHandler
{
public:
    PizzaHandler();
    ~PizzaHandler();
    void create_menu_pizza();
    //Creates pizza and sends it to the menu pizza repository.
    Pizza create_pizza();
    //Creates a special order pizza and returns it to caller.
    void print_pizzas();
    //
    void operator = (Toppings* copy);
    void operator = (Pizza* copy);
private:
    PizzaRepo pizzarepo;
    Pizza* pizza_list;
    int pizza_list_count;
    ToppingsHandler toppingshandler;
};



#endif // PIZZAHANDLER_H_INCLUDED
