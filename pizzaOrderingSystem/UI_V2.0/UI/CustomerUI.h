#ifndef USERUI_H
#define USERUI_H


#include <stdlib.h>
#include <iostream>
using namespace std;

class CustomerUI {
    public:
        CustomerUI();
        int customer_menu(bool run);
        char lower(char instr);
        void terminate();

    private:
        char select;
        //ToppingsHandler handler;
};

#endif // USERUI_H
