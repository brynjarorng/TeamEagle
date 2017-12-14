#ifndef BAKER_FUNCTIONS_H_INCLUDED
#define BAKER_FUNCTIONS_H_INCLUDED

#include "OrderHandler.h"
#include "Pizza.h"
#include "print_functions.h"

void print_pizza_baking_list(OrderHandler& orderhandler);
void print_pizzas_in_order(Order& order);

void print_lines (int line_count);

void print_pizza_list();

void print_pizzas_toppings(Pizza& pizza);
void print_pizzas_in_order(Order& order);
bool change_status(OrderHandler& orderhandler);


#endif // BAKERFUNCTIONS_H_INCLUDED
