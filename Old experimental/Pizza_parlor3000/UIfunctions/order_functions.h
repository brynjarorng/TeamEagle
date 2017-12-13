#ifndef ORDER_FUNCTIONS_H
#define ORDER_FUNCTIONS_H



#include <stdlib.h>
#include "OrderHandler.h"
#include "Pizza.h"
#include <iomanip>


#include "PizzaSize.h"
#include "PizzaSizeHandler.h"



enum Order_Status{delivered, all, not_delivered};

void print_lines (int line_count);
//Print line_count length of dashed line followed by an endl.
bool new_order();
//Precondition: The user is ready to enter a new order.
//Postcondition: The user gets a menu where he can create a new order.
//The return value is true if the function should be called again.
PizzaType menu_or_special();
//Precondition: The user is ready to choose if he wishes to add
//menu pizza or special pizza to order.
//Postcondition: If the user has entered the correct input, then the return
//value is the type of pizza selected. Otherwise the user cans choose to retry
//or exit.
void toppings_to_special(Pizza& pizza);
//Precondition: the reference instance of Pizza has been created and the use
//is ready to enter toppings from the keyboard.
//Postcondition: The user is prompt to input toppings, and if the toppings
//are on list they are added to this instance of pizza. The user can enter 'q'
//to indicate that he does not wish to enter more toppings.
//Returns true if the the pizza with the toppings added should be added to the order
//false otherwise.
bool yes();
//Input is a character, the function prompts the user to input a selection of (y) or (n)
//if the selection is neither, the user is asked again until either answer is recevied.
//if the input is 'y' then the return value is true, else the return value is false.
void add_pizzas(Order& order);
//Prompts the user to select the type of pizza (menu or special) and allows
//the user to repeat the action provided the maximum order count has not been reached.
void add_menu_pizza(Order& order);
//Adds pizza selected by the user on the menu.
//The return value is TRUE if the pizza was added to the menu,
//FALSE otherwise.
void add_special_pizza(Order& order);
//Pizza with selected toppings is added to the order.
void print_pizzas_toppings(Pizza pizza);
//Precondition: Pizza contains toppings to print.
//Postcondition: Toppings of pizza have been printed to the screen.
void print_pizza(Pizza pizza);
//Prints the name of the pizza followed by its topping and lastly the price.
void print_order(Order order);
//Prints the reference instance of order to the screen.
void mark_delivered();
//Lets the user mark an order delivered.
void print_orders(Order_Status status);
//status should be delivered for printing only delivered pizzas, not_delivered
//for printing all pizzas but those delivered and all for printing all pizzas.
void print_topping_list();
//Print the list of all available toppings
void print_menu_pizza_list();
//Print the list of all available pizzas


#endif // ORDER_FUNCTIONS_H
