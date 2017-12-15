#ifndef ORDER_FUNCTIONS_H
#define ORDER_FUNCTIONS_H

#include "print_functions.h"
#include <stdlib.h>
#include "OrderHandler.h"
#include "Pizza.h"
#include <iomanip>
#include "InvalidCharException.h"
#include "InvalidAlphaStringException.h"
#include "PizzaBottom.h"
#include "PizzaBottomHandler.h"
#include "get_menu_pizza.h"

void see_order_and_mark(OrderHandler& orderhandler);
//Lets the user mark an order delivered.
void mark_paid_or_delivered(OrderHandler& orderhandler);
//Lets the user mark an order paid.
void see_your_order(OrderHandler& orderhandler);
bool new_order(OrderHandler& orderhandler, PizzaHandler& pizzahandler, ToppingsHandler& toppingshandler, PizzaBottomHandler& bottomhandler);
//Precondition: The user is ready to enter a new order.
//Postcondition: The user gets a menu where he can create a new order.
//The return value is true if the function should be called again.
PizzaType menu_or_special(char& run);
//Precondition: The user is ready to choose if he wishes to add
//menu pizza or special pizza to order.
//Postcondition: If the user has entered the correct input, then the return
//value is the type of pizza selected. Otherwise the user cans choose to retry
//or exit.
vector<Toppings> toppings_to_special(ToppingsHandler& toppingshandler);
//Precondition: the reference instance of Pizza has been created and the use
//is ready to enter toppings from the keyboard.
//Postcondition: The user is prompt to input toppings, and if the toppings
//are on list they are added to this instance of pizza. The user can enter 'q'
//to indicate that he does not wish to enter more toppings.
//Returns true if the the pizza with the toppings added should be added to the order
//false otherwise.
bool add_pizzas(Order& order, OrderHandler& orderhandler, PizzaHandler& pizzahandler, ToppingsHandler& toppingshandler, PizzaBottomHandler& bottomhandler);
//Prompts the user to select the type of pizza (menu or special) and allows
//the user to repeat the action provided the maximum order count has not been reached.
bool add_menu_pizza(Order& order, PizzaHandler& pizzahandler, PizzaBottomHandler& bottomhandler);
//Adds pizza selected by the user on the menu.
//The return value is TRUE if the pizza was added to the menu,
//FALSE otherwise.
void add_special_pizza(Order& order,PizzaHandler& pizzahandler, ToppingsHandler& toppingshandler, PizzaBottomHandler& bottomhandler);
//Pizza with selected toppings is added to the order.


void sent_or_picked_up(Order& order);
//asks if customer wants to get a delivery
void set_delivery_addresse(Order& order);
//Sets the delivery addresse for the customer (I know this is not how to write address...)
void add_a_comment(Order& order);
//Add a comment to the order
void comment(Order& order);
vector <Toppings> get_toppings_selection();
//The user is asked to input toppings, and the return value is an vector with those
//toppings.
void add_bottom(Pizza& pizzaPizza, PizzaBottomHandler& bottomhandler, PizzaHandler& pizzahandler);
Pizza get_menu_p(PizzaHandler& pizzahandler, char& s);

bool change_status(OrderHandler& orderhandler);

#endif // ORDER_FUNCTIONS_H
