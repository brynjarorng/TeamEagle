#ifndef LOGINUI_H
#define LOGINUI_H

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

class LoginUI
{
    public:
        LoginUI();
        void login_portal(bool run);
        char lower(char instr);
        void terminate();

    private:
        char select;
};

#endif // LOGINUI_H
