#include <iostream>
#include "OrderHandler.h"
#include <UI.h>
using namespace std;

int main()
{
/*
    UI ui;

    ui.print_login_selector(0);
*/


    OrderHandler orderhandler;

    //for (int i = 0; i < 2; i++)
        orderhandler.add_pizza_to_order(menu_pizza);

    orderhandler.print_current_list();


    return 0;
}



