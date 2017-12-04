#include "PhoneClerkUI.h"

PhoneClerkUI::PhoneClerkUI()
{

}

void PhoneClerkUI::phone_menu(bool run) {

    system("CLS");

    cout << "----Phone portal----" << endl;
    cout << "(N) New order" << endl;
    cout << "(A) See all orders in progress" << endl;
    cout << "(M) See all pizzas on menu" << endl;
    cout << "(T) See all toppings" << endl;
    cout << "(L) See all old orders today" << endl;
    cout << "(B) Go back to login portal" << endl;
    cout << "(q) Quit" << endl;
    if(run){
        cout << "Incorrect input!" << endl;
    }
    cout << ": ";

    cin >> select;
    select = lower(select);

    switch (select)
    {
    case 'n':
        system("CLS");
        cout << "New order" << endl;
        system("PAUSE");
        phone_status_menu(0);
        break;

    case 'a':
        system("CLS");
        cout << "See all orders" << endl;
        system("PAUSE");
        phone_status_menu(0);
        break;

    case 'm':
        system("CLS");
        cout <<  "See all pizzas on menu" << endl;
        system("PAUSE");
        phone_status_menu(0);
        break;

    case 't':
        system("CLS");
        handler.print_toppings();
        system("PAUSE");
        phone_status_menu(0);
        break;

    case 'l':
        system("CLS");
        cout <<  "See everything ordered today" << endl;
        system("PAUSE");
        phone_status_menu(0);
        break;

    case 'b':
        lUI.login_portal(0);
        break;

    default:
        phone_menu(1);
        break;
    }
}

void PhoneClerkUI::terminate() {
    system("CLS");
    char cont;

    cout << "Are you sure you want to quit (y/n)? ";
        cin >> cont;
        cont = lower(cont);

    if(cont == 'y'){
        cout << "Good Bye!" << endl;
        exit(0);
    }
    phone_menu(0);
    //Double check if user wants to quit, else runs the
    //manager UI again
}

char PhoneClerkUI::lower(char instring) {
    instring = tolower(instring);
    return instring;
}








