#include "ManagerUI.h"

ManagerUI::ManagerUI()
{

}


void ManagerUI::manager_menu(bool run) {
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

    if(select == 'b') {
        lUI.login_portal(0);
        ///Returns to User selector

    } else if(select == 'i') {

        info_creator();
        ///To pizza info menu

    } else if(select == 'T') {

        topping_creator(ret_val);
        ///To topping menu

    } else if(select == 'S') {
        ///To size menu

    } else if(select == 'N') {

        pizza_creator(ret_val);
        ///To create a new pizza menu
    }
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
        handler.print_toppings();
        system("PAUSE");
        info_menu(0);

        break;
    case 'p':
        system("CLS");
        cout << "Print all pizzas: " << endl;
        system("PAUSE");
        info_menu(0)

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

    default:
        info_menu(1);
        break;
    }
}

void ManagerUI::topping_menu(bool run) {
    char cont;

    system("CLS");

    cout << "----Information portal----" << endl;
    cout << "(T) Add toppings" << endl;
    cout << "(S) Remove toppings" << endl;
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
            handler.create_toppings();
            do{
                cout << "Do you want to input more Toppings (y/n)? ";
                cin >> cont;
                cont = lower(cont);
            } while(cont == 'y' && cont == 'n');
        } while(cont == 'y');
        topping_menu(0);
        break;

    case 'r':
        system("CLS");
        cout << "No functionality yet!" << endl;
        topping_menu(0);
        break;

    case 'b':
        manager_menu(0);
        break;

    default:
        topping_menu(1);
        break;
    }
}

void MainUI::menu_pizza_menu(bool run) {
    char cont;

    system("CLS");

    cout << "----Information portal----" << endl;
    cout << "(T) Add toppings" << endl;
    cout << "(S) Remove toppings" << endl;
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
        cout << "Create a new pizza: Missing handler";
        system("PAUSE");
        break;

    case 'c':
        system("CLS");
        cout << "Change an existing pizza: Missing handler";
        sustem("PAUSE");
        break;

    case 'd':
        system("CLS");
        cout << "Remove a pizza from menu: Missing handler";
        system("PAUSE");
        break;

    default:
        menu_pizza_menu(1);
        break;
    }
}

