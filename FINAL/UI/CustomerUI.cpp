#include "CustomerUI.h"


CustomerUI::CustomerUI()
{

}

bool CustomerUI::customer_menu(bool run, bool& continueRun) {
    try{
        clear();
        cout << "----Store portal----" << endl;
        cout << "(N) New order" << endl;
        cout << "(M) See all pizzas on menu" << endl;
        cout << "(T) See all available toppings" << endl;
        cout << "(O) See your order status" << endl;
        cout << "(B) Go back to login portal" << endl;
        cout << "(Q) Quit" << endl;
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

        case 'm':
            clear();
            cout <<  "All pizzas on menu" << endl;
            print_menu_pizza_list();

            continueRun = 1;
            return 0;
            break;

        case 't':
            clear();
            cout << "See all available toppings" << endl;
            print_topping_list();

            continueRun = 1;
            return 0;
            break;

        case 'o':
            clear();
            cout << "See your order status" << endl;
            see_your_order(orderhandler);

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

void CustomerUI::terminate() {
    clear();
    char cont;

    cout << "Are you sure you want to quit (y/n)? ";
        cin >> cont;
        cont = lower(cont);

    if(cont == 'y'){
        cout << "Good Bye!" << endl;
        exit(0);
    }
}

char CustomerUI::lower(char instring) {
    instring = tolower(instring);
    return instring;
}


