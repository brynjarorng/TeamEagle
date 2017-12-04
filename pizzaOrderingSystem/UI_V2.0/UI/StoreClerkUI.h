#ifndef STORECLERK_H
#define STORECLERK_H

//#include "LoginUI.h"
#include <stdlib.h>
#include <iostream>
using namespace std;

class StoreClerkUI {
    public:
        StoreClerkUI();
        int store_menu(char run);
        char lower(char instr);
        void terminate();

    private:
        char select;
//        ToppingsHandler handler;
};

#endif // STORECLERK_H
