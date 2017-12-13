#ifndef PHONECLERKUI_H
#define PHONECLERKUI_H

#include <stdlib.h>
#include <iostream>
#include "UITemplate.h"

using namespace std;

class PhoneClerkUI : public UITemplate{
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
