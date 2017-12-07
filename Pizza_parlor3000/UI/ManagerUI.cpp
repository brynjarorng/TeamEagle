#include "ManagerUI.h"
#include "manager_functions.h"
ManagerUI::ManagerUI() {

}


bool ManagerUI::manager_menu(bool run, bool& continueRun) {
    try{
        do{
            system("CLS");

            cout << "----Manager Portal----" << endl;
            cout << "(I) Pizza information" << endl;
            cout << "(T) Toppings information" << endl;
            cout << "(S) Change available pizza sizes" << endl;
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
        system("CLS");

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
            system("CLS");
            //handler.print_toppings();
            system("PAUSE");

            continueRun = 1;
            return 0;
            break;

        case 'p':
            system("CLS");
            cout << "Print all pizzas: " << endl;
            system("PAUSE");

            continueRun = 1;
            return 0;
            break;

        case 's':
            system("CLS");
            cout << "Print all pizza sizes: " << endl;
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
        char cont;
        system("CLS");

        cout << "----Topping portal----" << endl;
        cout << "(A) Add toppings" << endl;
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
            system("CLS");
            do{
                create_topping();
                do{
                    cout << "Do you want to input more Toppings (y/n)? " << endl;
                    cin >> cont;
                    cont = lower(cont);
                } while(cont == 'y' && cont == 'n');
            } while(cont == 'y');

            continueRun = 1;
            return 0;
            break;

        case 'r':
            system("CLS");
            cout << "No functionality yet!" << endl;
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
}

bool ManagerUI::size_menu(bool run, bool& continueRun) {
    try{
        system("CLS");

        cout << "----Size editor portal----" << endl;
        cout << "(A) Add size" << endl;
        cout << "(R) Remove size" << endl;
        cout << "(B) Go back" << endl;
        cout << "(q) Quit" << endl;
        if(run){
            cout << "Incorrect input!" << endl;
        }
        cout << ": ";

        cin >> select;
        select = lower(select);

        switch (select)
        {
        case 'a':
            system("CLS");
            cout << "Add a new size" << endl;
            system("PAUSE");

            continueRun = 1;
            return 0;
            break;

        case 'r':
            system("CLS");
            cout << "Remove a size" << endl;
            system("PAUSE");

            continueRun = 1;
            return 0;
            break;

        case 'b':
    //        manager_menu(0);
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
        system("CLS");

        cout << "----Pizza menu portal----" << endl;
        cout << "(A) Add toppings" << endl;
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
            system("CLS");
            cout << "Create a new pizza" << endl;
            make_new_menu_pizza();

            continueRun = 1;
            return 0;
            break;

        case 'r':
            system("CLS");
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
    system("CLS");
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


