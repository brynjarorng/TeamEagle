#ifndef UIHANDLER_H
#define UIHANDLER_H


#include "ToppingsHandler.h"
#include <iostream>
#include <cstdlib>
#include "UI.h"
#include "StdInput.h"
using namespace std;

class UIHandler {
    public:
        UIHandler();
        UIHandler(string type, string option1, string option2, string option3, string option4, string option5, string option6);
        UIHandler(string type, string option1, string option2, string option3, string option4, string option5);
        UIHandler(string type, string option1, string option2, string option3, string option4);
        UIHandler(string type, string option1, string option2, string option3);
        UIHandler(string type, string option1, string option2);
        int menuUI(bool run);
        //Calls the main UI
        void ret_to_main();
        //returns to the main menu selector
        void ret_to_manager();
        //returns to the manager selector page
        void terminate();
        //kills the program
        char lower(char instring);
        //puts a single letter to lower case
        int selector_func();

    private:
        ToppingsHandler handler;
        bool run;
        int options;
        string option1, option2, option3, option4, option5, option6;
        string type;            ///type of menu
        char selector;          ///select the appropriate option
        int ret_val;            ///Val to return to indicate what option was chosen

};

#endif // UIHANDLER_H
