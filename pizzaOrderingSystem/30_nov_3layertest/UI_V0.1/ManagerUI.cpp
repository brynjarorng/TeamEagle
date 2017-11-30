#include "ManagerUI.h"

ManagerUI::ManagerUI() {

}

void ManagerUI::manager_menu() {
    char selector = ' ';

    system("CLS");

    cout << "Menu" << endl;
    cout << "(i) Pizza information" << endl;
    cout << "(t) Toppings" << endl;
    cout << "(p) Pizza size" << endl;
    cout << "(m) Make a new pizza" << endl;
    cout << "(r) Return to User selection" << endl;
    cout << "(q) Terminate program" << endl;
    cout << ": ";

    cin >> selector;
    selector = lower(selector);

    switch(selector) {
    case 'i':
        print_submenu();
        break;
    case 't':
        toppings_submenu();
        break;
    case 'p':
        size_submenu();
        break;
    case 'm':
        pizza_submenu();
        break;
    case 'r':
        ret_to_main();
        break;
    case 'q':
        terminate();
        break;
    default:
        cout << "Incorrect selection! \nPlease try again." << endl;
        manager_menu();
        break;
    }

}
//Prints out the main selector page for the manager
void ManagerUI::print_submenu() {
    system("CLS");
    char selector = ' ';

    cout << "Information:" << endl;
    cout << "(t) Toppings" << endl;
    cout << "(p) Pizzas" << endl;
    cout << "(s) Pizza size" << endl;
    cout << "(b) Back to menu" << endl;
    cout << "(q) Terminate program" << endl;
    cout << ": ";

    cin >> selector;
    selector = lower(selector);

    switch(selector) {
    case 't':
        system("CLS");
        handler.print_toppings();
        cout << "------------------------------------------------------" << endl;
        system("PAUSE");
        print_submenu();
        break;
    case 'p':
        cout << "Print" << endl;

        break;
    case 's':
        cout << "size" << endl;
        break;
    case 'b':
        manager_menu();
        break;
    case 'q':
        terminate();
        break;
    default:
        cout << "Incorrect selection! \nPlease try again." << endl;
        print_submenu();
        break;
    }

}

//enters a submenu for printing out all available Pizza info
void ManagerUI::toppings_submenu() {
    system("CLS");
    char selector = ' ';

    cout << "Toppings:" << endl;
    cout << "(a) Add toppings" << endl;
    cout << "(r) Remove toppings" << endl;
    cout << "(s) See all toppings" << endl;
    cout << "(b) Back to menu" << endl;
    cout << "(q) Terminate program" << endl;
    cout << ": ";

    cin >> selector;
    selector = lower(selector);

    switch(selector) {
    case 'a':
        cout << "Add toppings" << endl;
        handler.create_topping();
		break;
    case 'r':
        cout << "Remove toppings" << endl;
        break;
    case 's':
        cout << "All toppings" << endl;
        handler.print_toppings();
        break;
    case 'b':
        manager_menu();
        break;
    case 'q':
        terminate();
        break;
    default:
        cout << "Incorrect selection! \nPlease try again." << endl;
        toppings_submenu();
        break;
    }
}
//Gives the manager an option to add or remove toppings and their price
void ManagerUI::size_submenu() {
    system("CLS");
    char selector = ' ';

    cout << "Sizes:" << endl;
    cout << "(a) Add size" << endl;
    cout << "(r) Remove size" << endl;
    cout << "(b) Back to menu" << endl;
    cout << "(s) See all sizes" << endl;
    cout << ": ";

    cin >> selector;
    selector = lower(selector);

    switch(selector) {
    case 'a':
        cout << "Add sizes" << endl;
        break;
    case 'r':
        cout << "Remove sizes" << endl;
        break;
    case 's':
        cout << "All sizes" << endl;
        break;
    case 'q':
        terminate();
        break;
    case 'b':
        manager_menu();
        break;
    default:
        cout << "Incorrect selection! \nPlease try again." << endl;
        size_submenu();
        break;
    }
}
//Allows the manager to create, remove or change available pizza sizes in inches
void ManagerUI::pizza_submenu() {
    system("CLS");
    char selector = ' ';

    cout << "Pizzas:" << endl;
    cout << "(a) Add a new pizza" << endl;
    cout << "(r) Remove an old pizza" << endl;
    cout << "(s) See all pizzas" << endl;
    cout << "(b) Back to menu" << endl;
    cout << "(q) Terminate program" << endl;
    cout << ": ";

    cin >> selector;
    selector = lower(selector);

    switch(selector) {
    case 'a':
        cout << "Add pizza" << endl;
        break;
    case 'r':
        cout << "Remove pizza" << endl;
        break;
    case 's':
        cout << "All pizzas" << endl;
        break;
    case 'b':
        manager_menu();
        break;
    case 'q':
        terminate();
        break;
    default:
        cout << "Incorrect selection! \nPlease try again." << endl;
        pizza_submenu();
        break;
    }

}
//Gives the manager an option to add or remove pizzas and their price

void ManagerUI::terminate(){
    system("CLS");
    char cont;

    cout << "Are you sure you want to quit (y/n)? ";
        cin >> cont;
        cont = lower(cont);

    if(cont == 'y'){
        cout << "Good Bye!" << endl;
        exit(0);
    }
    print_submenu();
    //Double check if user wants to quit, else runs the
    //manager UI again
}

void ManagerUI::ret_to_main(){
    MainUI ui;

    system("CLS");
    ui.print_welcome();
    ui.print_selector();
}
//returns to the User selection

char ManagerUI::lower(char instring) {
    StdInput s;
    instring = s.to_lower_case(instring);
    return instring;
}
//calls a function to put input to lower case
