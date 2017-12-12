#include "StoreClerkUI.h"
#include "order_functions.h"

StoreClerkUI::StoreClerkUI() {

}


bool StoreClerkUI::store_menu(bool run, bool& continueRun) {
    try{
        clear();

        cout << "----Store portal----" << endl;
        cout << "(N) New order" << endl;
        cout << "(A) See all orders in progress" << endl;
        cout << "(M) See all pizzas on menu" << endl;
        cout << "(T) See all toppings" << endl;
        cout << "(P) Mark orders paid/picked up" << endl;
        cout << "(L) See all old orders today" << endl;
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
            new_order(orderhandler, pizzahandler, toppingshandler, bottomhandler);


            continueRun = 1;
            return 0;
            break;

        case 'a':
            clear();
            cout << "See all orders" << endl;
            print_orders(not_delivered, orderhandler);
            pause_screen();
            continueRun = 1;
            return 0;
            break;

        case 'm':
            clear();
            cout <<  "All pizzas on menu" << endl;
            print_menu_pizza_list(pizzahandler);
            pause_screen();

            continueRun = 1;
            return 0;
            break;

        case 't':
            clear();
            print_topping_list(toppingshandler);
            pause_screen();

            continueRun = 1;
            return 0;
            break;

        case 'l':
            clear();
            cout <<  "See everything ordered today" << endl;
            pause_screen();

            continueRun = 1;
            return 0;
            break;

        case 'p':
            clear();
            cout <<  "Mark orders paid or picked up" << endl;
            mark_delivered(orderhandler);

            continueRun = 1;
            return 0;
            break;

        case 'b':
            continueRun = 0;
            return 0;
            break;

        case 'q':
            terminate();
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

void StoreClerkUI::terminate() {
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

char StoreClerkUI::lower(char instring) {
    instring = tolower(instring);
    return instring;
}


