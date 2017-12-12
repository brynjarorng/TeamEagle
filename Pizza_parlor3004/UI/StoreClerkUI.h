#ifndef STORECLERK_H
#define STORECLERK_H

#include <stdlib.h>
#include <iostream>
#include "InvalidInputException.h"
#include "print_functions.h"
#include "OrderHandler.h"
#include "PizzaHandler.h"
#include "ToppingsHandler.h"
#include "PizzaBottomHandler.h"
using namespace std;

class StoreClerkUI {
    public:
        StoreClerkUI();
        bool store_menu(bool run, bool& continueRun);
        //Displays the store clerk menu
        char lower(char instr);
        //takes in a character and makes it
        //lower case (A -> a)
        void terminate();
        //stop the program

    private:
        char select;

        OrderHandler orderhandler;
        PizzaHandler pizzahandler;
        ToppingsHandler toppingshandler;
        PizzaBottomHandler bottomhandler;
};

#endif // STORECLERK_H
