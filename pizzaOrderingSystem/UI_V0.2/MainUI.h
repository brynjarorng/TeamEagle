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
        void topping_creator(int ret_val);
        //Function that calls all required handler
        //functions to create, (remove) or see all toppings
        void info_creator(int ret_val);
        //Function that calls all required handler
        //functions to view info about toppings, pizzas and (sizes)
        void pizza_creator(int ret_val);
        //Function that calls all required handler
        //functions to create, (remove) or see all pizzas
        void manager_selector(bool selector);
        //First branch under the login  screen, points
        //to pizza_creator(), info_creator() and topping_creator();
        void baker_ui();
        //The baker UI, nothing less, nothing more (maybe a little bit more ;) )


    private:
        bool run;
        int ret_val;
        ToppingHandler handler;
};

#endif // MAINUI_H
