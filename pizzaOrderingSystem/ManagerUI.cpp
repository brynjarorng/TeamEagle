#include "ManagerUI.h"
ManagerUI::ManagerUI() {

}

void ManagerUI::manager_menu() {
    char selector = ' ';

    cout << "Menu" << endl;
    cout << "(i) Pizza information" << endl;
    cout << "(t) Toppings" << endl;
    cout << "(p) Pizza size" << endl;
    cout << "(m) Make a new pizza" << endl;

    cin >> selector;

    switch(selector) {
    case 'i':
        print_submenu();
        break;
    case 't':
        cout << "Topping" << endl;
        break;
    case 'p':
        cout << "Pizza size" << endl;
        break;
    case 'm':
        cout << "Make a new pizza" << endl;
        break;
    default:
        cout << "Incorrect selection! \nPlease try again." << endl;
        manager_menu();
        break;
    }

}
//Prints out the main selector page for the manager
void ManagerUI::print_submenu() {
     char selector = ' ';

    cout << "Information:" << endl;
    cout << "(t) Toppings" << endl;
    cout << "(p) Pizzas" << endl;
    cout << "(s) Pizza size" << endl;

    cin >> selector;

    switch(selector) {
    case 'p':
        cout << "Pizza's" << endl;
        break;
    case 't':
        cout << "Toppings" << endl;
        break;
    case 's':
        cout << "size" << endl;
        break;
    default:
        cout << "Incorrect selection! \nPlease try again." << endl;
        manager_menu();
        break;
    }

}

//enters a submenu for printing out all available Pizza info
void ManagerUI::toppings_submenu() {

}
//Gives the manager an option to add or remove toppings and their price
void ManagerUI::size_submenu() {

}
//Allows the manager to create, remove or change available pizza sizes in inches
void ManagerUI::pizza_submenu() {

}
//Gives the manager an option to add or remove pizzas and their price
