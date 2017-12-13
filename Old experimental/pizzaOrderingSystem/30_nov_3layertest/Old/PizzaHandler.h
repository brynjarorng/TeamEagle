#ifndef PIZZAHANDLER_H_INCLUDED
#define PIZZAHANDLER_H_INCLUDED
#include "Pizza.h"

class PizzaHandler
{
public:
    PizzaHandler();
    ~PizzaHandler();
    void create_pizza();
    //Creates pizza and sends it to the pizza repository.
    void print_pizzas();
	//
    void operator = (Pizzas* copy);
private:
    PizzaRepo repo;
    Pizza* pizza_list;
    int pizza_list_count;
};



#endif // PIZZAHANDLER_H_INCLUDED
