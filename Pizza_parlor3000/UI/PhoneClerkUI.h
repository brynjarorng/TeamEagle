#ifndef PHONECLERKUI_H
#define PHONECLERKUI_H

#include <stdlib.h>
#include <iostream>
#include "order_functions.h"

#include "InvalidInputException.h"
using namespace std;

class PhoneClerkUI {
    public:
        PhoneClerkUI();
        bool phone_menu(bool run, bool& continueRun);
        //Displays the phone operator menu
        char lower(char instr);
        //takes in a character and makes it
        //lower case (A -> a)
        void terminate();
        //stop the program

    private:
        char select;
};

#endif // PHONECLERKUI_H
