#include <iostream>
#include "LoginUI.h"


using namespace std;

int main()
{
/*

    #include <conio.h>
    cout << "---Press any key to continue---" << endl;
    getch();
*/


    bool run = 1;
    bool error_msg = 0;
    LoginUI lUI;

    do{
        error_msg = lUI.login_portal(error_msg);
    } while(run);


    return 0;
}
