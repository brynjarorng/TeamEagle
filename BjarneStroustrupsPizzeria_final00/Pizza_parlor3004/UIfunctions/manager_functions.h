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

void remove_topping(ToppingsHandler& toppingshandler);

void make_new_menu_pizza(PizzaHandler& pizzahandler, ToppingsHandler& toppingshandler);

void remove_menu_pizza(PizzaHandler& pizzahandler);

bool add_pizza_size(PizzaBottomHandler& bottomhandler);

void remove_size(PizzaBottomHandler& bottomhandler);

void add_location(LocationHandler& lochandler);

void remove_locations(LocationHandler& lochandler);

void make_new_side_order(SideOrdersHandler& sideorderhandler);

void archive_orders(OrderHandler& orderhandler);




#endif // MANAGER_FUNCTIONS_H
