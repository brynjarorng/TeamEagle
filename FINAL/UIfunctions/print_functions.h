#ifndef PRINT_FUNCTIONS_H
#define PRINT_FUNCTIONS_H
#include "PizzaStatus.h"
#include "Print.h"
#include <iostream>

using namespace std;


enum Order_Status{delivered, all, not_delivered, paid};

void clear();

void pause_screen();

void print_pizzas_toppings(Pizza& pizza);
//Precondition: Pizza contains toppings to print.
//Postcondition: Toppings of pizza have been printed to the screen.
void print_pizza(Pizza& pizza);
//Prints the name of the pizza followed by its topping and lastly the price.
void print_order(Order& order);
//Prints the reference instance of order to the screen.
void print_current_orders();

void print_orders(Order_Status status, OrderHandler& orderhandler);
//status should be delivered for printing only delivered pizzas, not_delivered
//for printing all pizzas but those delivered and all for printing all pizzas.
void print_topping_list();
//Print the list of all available toppings
void print_menu_pizza_list();
//Print the list of all available pizzas
void print_size_with_numbers(PizzaBottomHandler& bottomhandler);
//Print a list of all pizza sizes wit numbers in front
void print_sizes(PizzaBottomHandler& bottomhandler);
//Print a list of all pizza sizes
void print_sizes_numbers(PizzaBottomHandler& bottomhandler);
//Print a list of all pizza sizes with numbers
void print_navigation (Print& print, print_item type, char in, bool loop);
//Navigate through the print list, n for next screen, p for previous.
//Depending on the print_type more options are available, namely lexiographical print order
//and price print order. It is possible to input a char.Set loop to true
//if you wish to loop the navigation.
void print_order_list(int& refresh, string next, OrderHandler& orderhandler, bool skipdelivered, bool skippaid);
//For selection bottom size.
void print_lines (int line_count);
//Print line_count length of dashed line followed by an endl.
void print_pizza_baking_list(OrderHandler& orderhandler);
//Prints pizzas for baker, skips orders that are ready.
void print_pizzas_in_order(Order& order);
//Prints the pizzas in the order
void print_lines (int line_count);
//Prints lines
void print_pizza_list();
//Prints list of pizzas
void print_pizzas_toppings(Pizza& pizza);
//Print the toppings of a pizza
void print_pizzas_in_order_for_baker(Order& order);
//Print the pizzas in an order for baker, that is only pizza name, its toppings and status
void print_toppings_with_number(ToppingsHandler& toppingshandler);
//Print toppings in numerical list
void print_menu_pizza_list_with_numbers(PizzaHandler& pizzahandler);
//Print menu pizzas with numerical list
void print_locations(LocationHandler& lochandler, bool numbered);
//Print list of locations, if second parameter is true, then a numerical list, else just the locations.
void print_archived_orders(OrderHandler& orderhandler);
//Prints the archived orders.


#endif // PRINT_FUNCTIONS_H
