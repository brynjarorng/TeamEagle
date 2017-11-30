#ifndef MANAGERUI_H
#define MANAGERUI_H

#include "ToppingHandler.h"
#include <iostream>
#include <cstdlib>
#include "MainUI.h"
#include "StdInput.h"
 using namespace std;

class ManagerUI {
    public:
        ManagerUI(int options);
        void ret_to_main();
        //returns to the main menu selector
        void ret_to_manager();
        //returns to the manager selector page
        void terminate();
        //kills the program
        char lower(char instring);

    private:
       ToppingHandler handler;
       bool run;
       int options;
};

#endif // MANAGERUI_H
