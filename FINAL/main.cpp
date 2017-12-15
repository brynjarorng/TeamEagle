#include <iostream>
#include "LoginUI.h"

//Group 58
// Brynjar Örn Grétarsson, Ívar Marrow, Viktor Sveinsson

using namespace std;

int main() {


    bool run = 1;
    bool error_msg = 0;
    LoginUI lUI;

    do{
        error_msg = lUI.login_portal(error_msg);
    } while(run);


    return 0;
}
