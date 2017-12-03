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
    void create_menu_pizza();
    //Creates pizza and sends it to the menu pizza repository.
    bool validate_pizza(string pizza_name);
    //Gets pizza name and iterates through the pizza menu and
    //returns true if a pizza matches name;
    bool validate_pizza(string pizza_name, int &index);
    //Method overload - takes index integer reference and changes it
    //to the corresponding index of the pizza in the pizza list if found.
    Pizza get_menu_pizza(string pizza_name);
    //Gets Pizza name and iterates through the pizza menu and
    //returns the pizza of the matching name.
    /// --- > validate_pizza must be called first < ---
    Pizza get_menu_pizza(int index);
    //Takes index as parameter and returns the pizza with the
    //corresponding index number.
    Pizza create_special_pizza();
    //Creates a special order pizza and returns it to caller.
    void print_pizzas();
    //Fetches list of pizzas from the repo and prints it to the screen.
    PizzaHandler& operator = (const PizzaHandler& right_side);
    //Overloading the = operator for dynamic array handling.
    void add_toppings();
    //Gets user input of a topping name, and checks if it exists,
    //if it does it'll be added to the pizza.
    //Loops until maximum topping number is reached or until user inputs "q".
private:

    Pizza pizza;
    PizzaRepo pizzarepo;
    ToppingsHandler toppingshandler;
	Toppings* toppings;
    Pizza* pizza_list;
    int pizza_list_count;
    void reset_pizza();
};

#endif // PIZZAHANDLER_H_INCLUDED

