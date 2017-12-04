#include "ManagerUI.h"

ManagerUI::ManagerUI() {

}


int ManagerUI::manager_menu(bool run) {
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
        info_menu(0);
        ///To pizza info menu
        break;

    case 't':
        topping_menu(0);
        ///To topping menu
        break;

    case 's':
        size_menu(0);
        ///To size menu
        break;

    case 'n':
        menu_pizza_menu(0);
        ///To create a new pizza menu
        break;

    case 'b':
        return 0;
        break;

    case 'q':
        terminate();
        break;

    default:
        manager_menu(1);
        break;
    }

    return 0;
}

void ManagerUI::info_menu(bool run) {

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
        info_menu(0);

        break;
    case 'p':
        system("CLS");
        cout << "Print all pizzas: " << endl;
        system("PAUSE");
        info_menu(0);

        break;
    case 's':
        system("CLS");
        cout << "Print all pizza sizes: " << endl;
        system("PAUSE");
        info_menu(0);
        break;
    case 'b':
        system("CLS");
        manager_menu(0);
        break;

    case 'q':
        terminate();
        break;

    default:
        info_menu(1);
        break;
    }
}

void ManagerUI::topping_menu(bool run) {
    bool cont;
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
    case 'a':                   ///VERY BROKEN, DO NOT KNOW WHY (CIN?????)
        system("CLS");
       // do{
            //handler.create_toppings();
       //     do{
                cout << "Do you want to input more Toppings (y/n)? " << endl;
        //        cin >> cont;
       //         cont = lower(cont);
       //     } while(cont == 'y' && cont == 'n');
       // } while(cont == 'y');
        system("PAUSE");
        topping_menu(0);
        break;

    case 'r':
        system("CLS");
        cout << "No functionality yet!" << endl;
        system("PAUSE");
        topping_menu(0);
        break;

    case 'b':
        manager_menu(0);
        break;

    case 'q':
        terminate();
        break;

    default:
        topping_menu(1);
        break;
    }
}

void ManagerUI::size_menu(bool run) {
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
        size_menu(0);
        break;

    case 'r':
        system("CLS");
        cout << "Remove a size" << endl;
        system("PAUSE");
        size_menu(0);
        break;

    case 'b':
        manager_menu(0);
        break;

    case 'q':
        terminate();
        break;

    default:
        size_menu(1);
        break;
    }
}

void ManagerUI::menu_pizza_menu(bool run) {
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

    switch (select)
    {
    case 'a':
        system("CLS");
        cout << "Create a new pizza" << endl;
        system("PAUSE");
        break;

    case 'r':
        system("CLS");
        cout << "Remove a pizza from menu" << endl;
        system("PAUSE");
        break;

    case 'b':
        manager_menu(0);
        break;

    case 'q':
        terminate();
        break;

    default:
        menu_pizza_menu(1);
        break;
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
    manager_menu(0);
    //Double check if user wants to quit, else runs the
    //manager UI again
}

char ManagerUI::lower(char instring) {
    instring = tolower(instring);
    return instring;
}


