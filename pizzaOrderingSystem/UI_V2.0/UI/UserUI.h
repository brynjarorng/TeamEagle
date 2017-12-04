#ifndef USERUI_H
#define USERUI_H

#include "LoginUI.h"

class UserUI
{
    public:
        UserUI();

    private:
        LoginUI lUI;
        bool select;
        ToppingsHandler handler;
};

#endif // USERUI_H
