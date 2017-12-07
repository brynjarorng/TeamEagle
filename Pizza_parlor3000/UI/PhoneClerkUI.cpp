#include "PhoneClerkUI.h"
PhoneClerkUI::PhoneClerkUI() {

}

bool PhoneClerkUI::phone_menu(bool run, bool& continueRun) {
    try{

        system("CLS");

        cout << "----Phone portal----" << endl;
        cout << "(N) New order" << endl;
        cout << "(A) See all orders in progress" << endl;
        cout << "(M) See all pizzas on menu" << endl;
        cout << "(T) See all toppings" << endl;
        cout << "(O) See all old orders today" << endl;
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
            new_order();

            continueRun = 1;
            return 0;
            break;

        case 'a':
            system("CLS");
            cout << "See all orders" << endl;
            print_orders(not_delivered);
            system("PAUSE");

            continueRun = 1;
            return 0;
            break;

        case 'm':
            system("CLS");
            cout <<  "See all pizzas on menu" << endl;
            system("PAUSE");

            continueRun = 1;
            return 0;
            break;

        case 't':
            system("CLS");
    //        handler.print_toppings();
            system("PAUSE");

            continueRun = 1;
            return 0;
            break;

        case 'o':
            system("CLS");
            cout <<  "See everything ordered today" << endl;
            system("PAUSE");

            continueRun = 1;
            return 0;
            break;

        case 'b':
            continueRun = 0;
            return 0;
            break;

        case 'q':
            terminate();
            continueRun = 1;
            return 0;
            break;
        }
        throw(InvalidInputException());
    }

    catch(InvalidInputException e) {
        continueRun = 1;
        return 1;
    }

    return 0;
}

void PhoneClerkUI::terminate() {
    system("CLS");
    char cont;

    cout << "Are you sure you want to quit (y/n)? ";
        cin >> cont;
        cont = lower(cont);

    if(cont == 'y'){
        cout << "Good Bye!" << endl;
        exit(1);
    }
}

char PhoneClerkUI::lower(char instring) {
    instring = tolower(instring);
    return instring;
}








