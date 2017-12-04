#include <iostream>
#include "LoginUI.h"
using namespace std;

int main()
{
    bool run = 1;
    LoginUI lUI;

    do{
        lUI.login_portal(0);
    } while(run);


    return 0;
}
