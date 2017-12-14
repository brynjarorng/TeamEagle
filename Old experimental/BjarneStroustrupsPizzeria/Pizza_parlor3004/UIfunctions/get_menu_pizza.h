#ifndef GET_MENU_PIZZA_H_INCLUDED
#define GET_MENU_PIZZA_H_INCLUDED

#include "Print.h"
#include "PizzaHandler.h"
#include "get_menu_pizza.h"
#include "add_toppings.h"
#include "OrderHandler.h"

Pizza get_menu_selection(char& s);
bool p_pizza_on_list(vector<Pizza> pizz);
void add_selected_pizza(vector<Pizza>& add, vector<int> digits, sort_by sort_order) ;

void p_print_while_not_digits(Pizza& selection, char& s);

void print_pizza_selection(int from, int to, sort_by& sorting_order) ;
void remove_pizza(vector <Pizza>& pizza);
vector<Pizza> new_pizza_list(const vector<int>& digits, const vector<Pizza> pizza);
bool p_validate_number(string digits, int range);
bool p_number_selected (string in, vector<int>& digits);

void p_print(vector<Pizza> in, bool indexed);

Pizza get_selected_pizza(int index, sort_by order);

void print_pizza_selection(vector<Pizza>& selection);


#endif // GET_MENU_PIZZA_H_INCLUDED
