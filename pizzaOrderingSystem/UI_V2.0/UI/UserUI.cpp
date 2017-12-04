#include "UserUI.h"

UserUI::UserUI()
{

}

void UserUI::customer_menu(bool run) {
system("CLS");

    cout << "----Store portal----" << endl;
    cout << "(N) New order" << endl;
    cout << "(M) See all pizzas on menu" << endl;
    cout << "(T) See all available toppings" << endl;
    cout << "(O) See your order status" << endl;
    cout << "(B) Go back to login portal" << endl;
    cout << "(q) Quit" << endl;
    if(run){
        cout << "Incorrect input!" << endl;
    }
    cout << ": ";

    cin >> select;
    select = lower(select);

    switch (select) {
    case 'n':
        system("CLS");
        cout << "New order" << endl;
        system("PAUSE");
        customer_menu(0);
        break;

    case 'm':
        system("CLS");
        cout << "New order" << endl;
        system("PAUSE");
        customer_menu(0);
        break;

    case 'a':
        system("CLS");
        cout << "See all available pizzas" << endl;
        system("PAUSE");
        customer_menu(0);
        break;

    case 't':
        system("CLS");
        cout << "See all available toppings" << endl;
        system("PAUSE");
        customer_menu(0);
        break;

    case 'o':
        system("CLS");
        cout << "See all your order status" << endl;
        system("PAUSE");
        customer_menu(0);
        break;

    case 'b':
        lui.login_portal(0);
        break;

    default:
        customer_menu(1);
        break;
    }

}

