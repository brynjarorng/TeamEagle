#ifndef LOGINUI_H
#define LOGINUI_H

#include <iostream>
#include <stdlib.h>
#include <vector>

class LoginUI
{
    public:
        LoginUI();
        void login_portal(bool run);

    private:
        char selector;
};

#endif // LOGINUI_H
