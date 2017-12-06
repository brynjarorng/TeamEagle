#ifndef MAINUI_H
#define MAINUI_H

#include "EmployeeSaleryHandler.h"
#include <iostream>
#include <stdlib.h>
#include <UIHandler.h>

using namespace std;

class MainUI
{
    public:
        MainUI();
        bool print_menu(bool run, bool& contRun);


    private:
        char select;
        UIHandler ui_handler;
};

#endif // MAINUI_H
