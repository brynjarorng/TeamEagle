#ifndef BAKERUI_H
#define BAKERUI_H

#include "LoginUI.h"
#include <iostream>


class BakerUI
{
    public:
        BakerUI();
        void baker_menu();
        char lower(char instr);
        void terminate();


    private:
        LoginUI lUI;
};

#endif // BAKERUI_H
