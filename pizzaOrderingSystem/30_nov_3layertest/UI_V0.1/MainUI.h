#ifndef MAINUI_H
#define MAINUI_H

#include "ManagerUI.h"
#include "StdInput.h"

class MainUI
{
    public:
        MainUI();
        void print_welcome();
        //prints the welcome message, create console art?
        void print_selector();
        //prints all available login options
        char lower(char instring);
        //helper function to send input to to lower function


    private:
};

#endif // MAINUI_H
