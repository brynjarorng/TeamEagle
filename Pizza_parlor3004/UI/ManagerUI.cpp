#include "ManagerUI.h"
#include "manager_functions.h"

ManagerUI::ManagerUI() {

}


bool ManagerUI::manager_menu(bool run, bool& continueRun) {
    try{
        do{
            clear();

            cout << "----Manager Portal----" << endl;
            cout << "(I) Pizza information" << endl;
            cout << "(T) Manage Toppings" << endl;
            cout << "(S) Manage pizza bottom" << endl;
            cout << "(N) Make a new Pizza" << endl;
            cout << "(B) Go back to Login portal" << endl;
            cout << "(q) Quit" << endl;
            if(run){
                cout << "Incorrect input!" << endl;
            }
            cout << ": ";

            cin >> select;
            select = lower(select);

            switch (select) {
            case 'i':
                run = 0;
                do{
                    run = info_menu(run, continueRun);
                } while(continueRun);
                continueRun = 1;
                ///To pizza info menu
                break;

            case 't':
                run = 0;
                do{
                    run = topping_menu(run, continueRun);
                } while(continueRun);
                continueRun = 1;
                ///To topping menu
                break;

            case 's':
                run = 0;
                do{
                    run = size_menu(run, continueRun);
                } while(continueRun);
                continueRun = 1;
                ///To size menu
                break;

            case 'n':
                run = 0;
                do{
                    run = menu_pizza_menu(run, continueRun);
                } while(continueRun);
                continueRun = 1;
                ///To create a new pizza menu
                break;

            case 'b':
                continueRun = 0;
                return 0;
                break;

            case 'q':
                terminate();
                break;

            default:
                throw (InvalidInputException());
                break;
            }
        } while(continueRun);
    }

    catch(InvalidInputException e){
        continueRun = 1;
        return 1;
    }

    return 0;
}

bool ManagerUI::info_menu(bool run, bool& continueRun) {
    try{
        clear();

        cout << "----Information portal----" << endl;
        cout << "(T) Print toppings" << endl;
        cout << "(P) Print all pizzas on menu" << endl;
        cout << "(S) Print all available pizza sizes" << endl;
        cout << "(B) Go back" << endl;
        cout << "(q) Quit" << endl;
        if(run){
            cout << "Incorrect input!" << endl;
        }
        cout << ": ";

        cin >> select;
        select = lower(select);

        switch (select) {
        case 't':
            print_topping_list(toppingshandler);
            pause_screen();
            continueRun = 1;
            return 0;
            break;

        case 'p':
            print_menu_pizza_list(pizzahandler);
            pause_screen();
            continueRun = 1;
            return 0;
            break;

        case 's':
            print_sizes(bottomhandler);

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
        default:
            throw(InvalidInputException());
            break;
        }


    }
    catch(InvalidInputException e) {
        continueRun = 1;
        return 1;
    }

    return 0;
}

bool ManagerUI::topping_menu(bool run, bool& continueRun) {
    try{
        clear();

        cout << "----Topping portal----" << endl;
        cout << "(A) Add toppings" << endl;
        cout << "(S) See all available toppings" << endl;
        cout << "(R) Remove toppings" << endl;
        cout << "(B) Go back" << endl;
        cout << "(q) Quit" << endl;
        if(run){
            cout << "Incorrect input!" << endl;
        }
        cout << ": ";

        cin >> select;
        select = lower(select);

        switch (select) {
        case 'a':
            create_topping(toppingshandler);

            continueRun = 1;
            return 0;
            break;

        case 's':
            print_topping_list(toppingshandler);
            pause_screen();
            continueRun = 1;
            return 0;
            break;

        case 'r':
            remove_topping(toppingshandler);
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
}

bool ManagerUI::size_menu(bool run, bool& continueRun) {
    try{
        clear();

        cout << "----Size editor portal----" << endl;
        cout << "(A) Add size and price" << endl;
        cout << "(S) See all sizes and prices" << endl;
        cout << "(R) Remove a size and price" << endl;
        cout << "(B) Go back" << endl;
        cout << "(q) Quit" << endl;
        if(run){
            cout << "Incorrect input!" << endl;
        }
        cout << ": ";

        cin >> select;
        select = lower(select);

        switch (select) {
        case 'a':
            add_pizza_size(bottomhandler);

            continueRun = 1;
            return 0;
            break;

        case 'r':
            remove_size(bottomhandler);

            continueRun = 1;
            return 0;
            break;

        case 's':
            print_sizes(bottomhandler);

            continueRun = 1;
            return 0;
            break;

        case 'b':
            continueRun = 0;
            return 0;
            break;

        case 'q':
            terminate();
            continueRun = 0;
            return 0;
            break;
        }
        throw(InvalidInputException());
    }
    catch(InvalidInputException()) {
        continueRun = 1;
        return 1;
    }
}

bool ManagerUI::menu_pizza_menu(bool run, bool& continueRun) {
    try {
        clear();

        cout << "----Pizza menu portal----" << endl;
        cout << "(N) Create a new pizza" << endl;
        cout << "(R) Remove pizza" << endl;
        cout << "(B) Go back" << endl;
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
            cout << "Create a new pizza" << endl;
            make_new_menu_pizza(pizzahandler, toppingshandler);

            continueRun = 1;
            return 0;
            break;

        case 'r':
            clear();
            cout << "Remove a pizza from menu" << endl;

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
}

void ManagerUI::terminate() {
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

char ManagerUI::lower(char instring) {
    instring = tolower(instring);
    return instring;
}


