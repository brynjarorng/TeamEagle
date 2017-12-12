#ifndef MANAGERUI_H
#define MANAGERUI_H

#include <stdlib.h>
#include <iostream>
#include "InvalidInputException.h"
#include "order_functions.h"
#include "print_functions.h"
#include "OrderHandler.h"
#include "PizzaHandler.h"
#include "ToppingsHandler.h"

using namespace std;

class ManagerUI {
    public:
        ManagerUI();
        bool manager_menu(bool run, bool& continueRun);
        //Displays the main manager menu and asks for input
        bool info_menu(bool run, bool& continueRun);
        //Displays the information menu (Toppings info, pizza info etc.)
        bool topping_menu(bool run, bool& continueRun);
        //Displays the menu for adding and removing toppings
        bool size_menu(bool run, bool& continueRun);
        //Displays the menu for adding and removing pizza sizes
        bool menu_pizza_menu(bool run, bool& continueRun);
        //Displays the menu for adding and removing pizzas from the menu
        char lower(char instr);
        //takes in a character and makes it
        //lower case (A -> a)
        void terminate();
        //stop the program

    private:
        char select;
        PizzaHandler pizzahandler;
        ToppingsHandler toppingshandler;
        PizzaBottomHandler bottomhandler;

};

#endif // MANAGERUI_H
