#ifndef MAINUI_H
#define MAINUI_H

#include "ManagerUI.h"
#include "StdInput.h"

class MainUI
{
    public:
        MainUI();
        void print_selector(bool run);
        //prints all available login options
        char lower(char instring);
        //helper function to send input to to lower function
        void terminate();
        //kills the program


    private:
        bool run;
};

#endif // MAINUI_H
