#include "PhoneClerkUI.h"

PhoneClerkUI::PhoneClerkUI() {

}

bool PhoneClerkUI::phone_menu(bool run, bool& continueRun) {
    try{

        clear();

        cout << "----Phone portal----" << endl;
        cout << "(N) New order" << endl;
        cout << "(A) See all orders in progress" << endl;
        cout << "(O) See all old orders today" << endl;
        cout << "(M) See all pizzas on menu" << endl;
        cout << "(T) See all toppings" << endl;
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
            clear();

            cout << "New order" << endl;
            choose_location();
            new_order(orderhandler, pizzahandler, toppingshandler, bottomhandler);

            continueRun = 1;
            return 0;
            break;

        case 'a':
            clear();
            cout << "See all orders" << endl;
            choose_location();
            print_orders(not_delivered, orderhandler);
            pause_screen();

            continueRun = 1;
            return 0;
            break;

        case 'm':
            clear();
            cout <<  "All pizzas on menu: " << endl;
            print_menu_pizza_list();

            continueRun = 1;
            return 0;
            break;

        case 't':
            clear();
            print_topping_list();
            pause_screen();

            continueRun = 1;
            return 0;
            break;

        case 'o':
            clear();
            cout <<  "See everything ordered today" << endl;
            pause_screen();

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
    clear();
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








