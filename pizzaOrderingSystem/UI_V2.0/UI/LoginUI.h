#ifndef LOGINUI_H
#define LOGINUI_H

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "ManagerUI.h"
#include "BakerUI.h"
#include "PhoneClerkUI.h"
#include "StoreClerkUI.h"
#include "CustomerUI.h"


using namespace std;

class LoginUI {
    public:
        LoginUI();
        void login_portal(bool run);
        char lower(char instr);
        void terminate();

    private:
        char select;
        ManagerUI mUI;
        BakerUI bUI;
        PhoneClerkUI pUI;
        StoreClerkUI sUI;
        CustomerUI cUI;
};

#endif // LOGINUI_H
