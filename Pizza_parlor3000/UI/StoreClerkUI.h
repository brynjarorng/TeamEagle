#ifndef STORECLERK_H
#define STORECLERK_H

#include <stdlib.h>
#include <iostream>
#include "InvalidInputException.h"
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
};

#endif // STORECLERK_H
