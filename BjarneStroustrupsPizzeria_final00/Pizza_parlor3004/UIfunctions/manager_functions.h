#ifndef MANAGER_FUNCTIONS_H
#define MANAGER_FUNCTIONS_H

#include "InvalidAlphaStringException.h"
#include "InvalidNumberException.h"
#include "InvalidBoolException.h"
#include "ValidationFunctions.h"
#include "order_functions.h"
#include "add_toppings.h"
#include "SideOrdersHandler.h"

void create_topping(ToppingsHandler& toppingshandler);
//Precondition: The user is ready to enter a name of a new
//topping.Postcondition: If the name is not already in the list, and is
//valid, the name is appended to the current toppings list.
void remove_topping(ToppingsHandler& toppingshandler);
//Pretcondtion:The user is ready to input numbers corresponding to the
//toppings to be remove.
//Postconditin: If the number selected is valid, then the topping corresponding
//to the selection has been removed from the current toppings list.
void make_new_menu_pizza(PizzaHandler& pizzahandler, ToppingsHandler& toppingshandler);
//Precondition; The user is ready to input the name, price and select toppings from the current toppings
//list from the keyboard.
//Postcondition: If the information input is
void remove_menu_pizza(PizzaHandler& pizzahandler);
//Precondition: The user is ready to select a pizza from the current menu list, the selection
//is a integer corresponding to the index of the pizza in the list.
//Postcondition: If the input is valid, then the pizza corresponding to the selected integer
//has been removed.
bool add_pizza_size(PizzaBottomHandler& bottomhandler);
//Precondition: The user is ready to input a new pizza bottom, where the information should be
//name and price.
//Postcondition: If the input is valid, then the new pizza bottom has been added to the current list
//of pizza bottoms.
void remove_size(PizzaBottomHandler& bottomhandler);
//Precondition: The user is ready to select a bottom from the current list of bottoms, where the
//selection is an integer corresponding to the position of the bottom in the list.
//Postcondition: If the input is valid, the bottom corresponding to the selection
//has been removed from the current bottoms list.
void add_location(LocationHandler& lochandler);
//Precondition: The user is ready to enter the name of the location entered from the keyboard.
//Postcondition: If the input is valid, and the name is not currently on the list of
//location, the location has been added to the list of locations.
void remove_locations(LocationHandler& lochandler);
//Precondition: The user is ready to select a location from a list, where the selection
//is an integer corresponding to a location in the current location list.
//Postcondition: If selection is valid, the location selected has now been removed from
//the list.
void archive_orders(OrderHandler& orderhandler);
//Precondition: The user is ready to choose of he wants to archive current orders list,
//and gets a selection of location too choose from.
//Postcondition: If the user selected to archive, the orders from the location now has
//been moved to the archived list.




#endif // MANAGER_FUNCTIONS_H
