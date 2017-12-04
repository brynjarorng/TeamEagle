#ifndef MANAGERUI_H
#define MANAGERUI_H

#include <stdlib.h>
#include <iostream>
using namespace std;

class ManagerUI {
    public:
        ManagerUI();
        int manager_menu(bool run);
        void info_menu(bool run);
        void topping_menu(bool run);
        void size_menu(bool run);
        void menu_pizza_menu(bool run);
        char lower(char instr);
        void terminate();

    private:
        char select;
        //ToppingsHandler handler;

};

#endif // MANAGERUI_H
