#ifndef LOGINUI_H
#define LOGINUI_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "ManagerUI.h"
#include "BakerUI.h"
#include "PhoneClerkUI.h"
#include "StoreClerkUI.h"
#include "CustomerUI.h"
#include "InvalidInputException.h"
#include "print_functions.h"


using namespace std;

class LoginUI {
    public:
        LoginUI();
        bool login_portal(bool run);
        //Displays the main login portal
        ///Implement an SSN based login system?


    private:
        char select;
        bool continueRun;
        ManagerUI mUI;
        BakerUI bUI;
        PhoneClerkUI pUI;
        StoreClerkUI sUI;
        CustomerUI cUI;
        char lower(char instr);
        //takes in a character and makes it
        //lower case (A -> a)
        void terminate();
        //stop the program
};

#endif // LOGINUI_H
