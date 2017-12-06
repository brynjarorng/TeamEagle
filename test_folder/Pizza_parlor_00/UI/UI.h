#ifndef UI_H
#define UI_H

#include "UIHandler.h"
#include "StdInput.h"

class UI {
    public:
        UI();
        void print_login_selector(bool run);
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
        void baker_selector();
        //The baker UI, nothing less, nothing more (maybe a little bit more ;) )
        void phone_status_ui(int ret_val);
        //Calls functions to get status of current orders,
        //all pizzas and all toppings
        void phone_selector(bool selector);
        //Main landing page for the phone operator
        void clerk_status_ui(int ret_val);
        //Calls functions to get status of current orders,
        //all pizzas and all toppings
        void clerk_selector(bool selector);
        //Main landing page for the store clerk operator
        void customer_selector(bool selector);
        //Main landing page for the customer



    private:
        bool run;
        int ret_val;
        ToppingsHandler handler;
};


#endif // UI_H
