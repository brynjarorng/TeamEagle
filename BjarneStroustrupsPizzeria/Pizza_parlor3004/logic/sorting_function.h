#ifndef SORTING_FUNCTION_INCLUDED
#define SORTING_FUNCTION_INCLUDED
#include "ToppingsRepo.h"
#include "PizzaRepo.h"
#include "OrderRepo.h"
#include <string.h>

enum sort_by {alph_asc, alph_desc, price_asc, price_desc};

int string_comp (string one, string two);
//If one is lexiographically greater than two then the
//return value is one, if two is l.greater the return value is two,
//if they are l.equal then the return value is 0.
bool one_is_greater(string one, string two);
//The return value is true if one is lexiographically greater than
//two, false otherwise.
/**********TOPPINGS**********/
vector <Toppings> toppings_sorted(sort_by a);
//Precondition: The binary file must contain toppings to sort, since a call to the repo is made.
//Postcondition: Return value is a sorted vector of toppings corresponding to which argument
//is made; Sorted by: descending price if argument is price_desc,
//ascending price if argument is price_asc, ascending lexiographical order if argument is alph_asc,
//descending price if argument is alph_desc, and the default return is a vector containing one element
//where the name is a message indicating that the default argument was met.
vector <Toppings> toppings_price_sort_desc();
//Precondition: The binary file must contain toppings to sort, since a call to the repo is made.
//Postcondition: return value is a vector containing Toppings as elements
//sorted by DESCENDING price.
vector <Toppings> toppings_price_sort_asc();
//Precondition: The binary file must contain toppings to sort, since a call to the repo is made.
//Postcondition: return value is a vector containing Toppings as elements
//sorted by ASCENDING price.
vector <Toppings> toppings_alph_sort_asc();
//Precondition: The binary file must contain toppings to sort, since a call to the repo is made.
//Postcondition: return value is a vector containing Toppings as elements
//sorted by ASCENDING name.
vector <Toppings> toppings_alph_sort_desc();
//Precondition: The binary file must contain toppings to sort, since a call to the repo is made.
//Postcondition: return value is a vector containing Toppings as elements
//sorted by ASCENDING name.
/**********PIZZA**********/
//Same condition apply for pizza excactly the same as above comments.
vector <Pizza> pizza_sorted(sort_by a);
vector <Pizza> pizza_price_sort_desc();
vector <Pizza> pizza_price_sort_asc();
vector <Pizza> pizza_alph_sort_asc();
vector <Pizza> pizza_alph_sort_desc();
/**********ORDERS**********//*
//Same condition apply for pizza excactly the same as above comments.
vector <Order> order_sorted(sort_by a);
vector <Order> order_price_sort_desc();
vector <Order> order_price_sort_asc();
vector <Order> order_alph_sort_asc();
vector <Order> order_alph_sort_desc();

*/

#endif // SORTING_FUNCTION_INCLUDED
