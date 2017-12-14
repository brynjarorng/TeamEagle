#ifndef MANAGERUI_H
#define MANAGERUI_H

#include <stdlib.h>
#include <iostream>
#include "UIBridge.h"


using namespace std;

class ManagerUI: public UIBridge {
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
        bool side_order_menu(bool run, bool& continueRun);
        //menu for side orders
        bool archive_menu(bool run, bool& continueRun);
        //menu for archive functions
        char lower(char instr);
        //takes in a character and makes it
        //lower case (A -> a)
        void terminate();
        //stop the program


    private:
        char select;


};

#endif // MANAGERUI_H
