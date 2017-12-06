#include <iostream>

#include "MainUI.h"

using namespace std;

int main()
{
    bool run = 0;
    MainUI ui;
    bool contRun = 1;


    do{
        run = ui.print_menu(run, contRun);
    } while(contRun);


    return 0;
}
