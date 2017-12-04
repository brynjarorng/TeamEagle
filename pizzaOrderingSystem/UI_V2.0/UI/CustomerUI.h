#ifndef USERUI_H
#define USERUI_H

#include "LoginUI.h"

class UserUI
{
    public:
        UserUI();
        void customer_menu(bool run);
        char lower(char instr);
        void terminate();

    private:
        LoginUI lUI;
        char select;
        ToppingsHandler handler;
};

#endif // USERUI_H
