#ifndef MANAGERUI_H
#define MANAGERUI_H

#include <iostream>
#include <LoginUI.h>

using namespace std;


class ManagerUI
{
    public:
        ManagerUI();
        void manager_menu(bool run);
        void info_menu(bool run);
        void topping_menu(bool run);
        void menu_pizza_menu(bool run);
        char lower(char instr);
        void terminate();

    private:
        LoginUI lUI;
        char select;
        ToppingsHandler handler;

};

#endif // MANAGERUI_H
