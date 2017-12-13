#ifndef USERUI_H
#define USERUI_H


#include <stdlib.h>
#include <iostream>
#include "InvalidInputException.h"
using namespace std;

class CustomerUI {
    public:
        CustomerUI();
        bool customer_menu(bool run, bool& continueRun);
        //Displays the customer menu and
        //asks for an input
        char lower(char instr);
        //takes in a character and makes it
        //lower case (A -> a)
        void terminate();
        //stop the program

    private:
        char select;
        //ToppingsHandler handler;
};

#endif // USERUI_H
