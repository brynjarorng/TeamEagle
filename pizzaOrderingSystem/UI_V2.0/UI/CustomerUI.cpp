#include "CustomerUI.h"

CustomerUI::CustomerUI()
{

}

int CustomerUI::customer_menu(bool run) {
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
        return 0;
        break;

    case 'q':
        terminate();
        break;

    default:
        customer_menu(1);
        break;
    }

    return 0;
}

void CustomerUI::terminate() {
    system("CLS");
    char cont;

    cout << "Are you sure you want to quit (y/n)? ";
        cin >> cont;
        cont = lower(cont);

    if(cont == 'y'){
        cout << "Good Bye!" << endl;
        exit(0);
    }
    customer_menu(0);
    //Double check if user wants to quit, else runs the
    //manager UI again
}

char CustomerUI::lower(char instring) {
    instring = tolower(instring);
    return instring;
}


