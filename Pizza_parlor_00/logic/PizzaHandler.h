#ifndef PIZZAHANDLER_H
#define PIZZAHANDLER_H

#include "ToppingsHandler.h"
#include "PizzaRepo.h"

class PizzaHandler
{
public:
    PizzaHandler();
    //Copy constructor
    ~PizzaHandler();
    //Destructor
    PizzaHandler (const PizzaHandler& copy);
    //Copy constructor
    bool set_name(string name, Pizza& pizza);
    //Takes name from UI and checks if valid,
    //If valid, then name is assigned and returns TRUE.
    //Else return false.
    void create_new_menu_pizza(Pizza& pizza) ;
    //Calls validate_new_pizza does not throw exceptions then the
    bool validate_name(string pizza_name);
    //Gets pizza name and iterates through the pizza menu and
    //returns true if a pizza matches name;
    bool validate_new_pizza(Pizza& pizza) throw(InvalidName, InvalidPrice);
    //Validates new pizza that's being added to database.
    //If a pizza already has the same name it will throw InvalidName and return false.
    //If the price is below 0 it will throw InvalidPrice and return false.
    //Else return true.
    Pizza get_menu_pizza(string pizza_name);
    //Gets Pizza name and iterates through the pizza menu and
    //returns the pizza of the matching name.
    /// --- > validate_pizza must be called first < ---
    Pizza get_menu_pizza(int index);
    //Takes index as parameter and returns the pizza with the
    //corresponding index number.
    void create_special_pizza(Pizza& pizza);
    //Creates a special order pizza.
    void print_pizzas();
    //Fetches list of pizzas from the repo and prints it to the screen.
    PizzaHandler& operator = (const PizzaHandler& right_side);
    //Overloading the = operator for dynamic array handling.
    bool add_topping(string name, Pizza& pizza);
    //If name is a name of a topping existing in the current list
    //of toppings, then the topping is added to the pizza and
    //the return value is TRUE. Else nothing is done and the return
    //value is FALSE.
    bool max_toppings(const Pizza& pizza);
    //The return value is FALSE if more toppings can be added.
    //the return value is TRUE if max toppings is reached.
    void reset_pizza(Pizza& pizza);
private:

   // Pizza pizza;
    PizzaRepo pizzarepo;
    ToppingsHandler toppingshandler;
	Toppings* toppings;
    Pizza* pizza_list;
    int pizza_list_count;

};

#endif // PIZZAHANDLER_H_INCLUDED

