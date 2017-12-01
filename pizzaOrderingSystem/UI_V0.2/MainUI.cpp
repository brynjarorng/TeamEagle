#include "MainUI.h"
#include <iostream>
#include "ManagerUI.h"

using namespace std;

    ManagerUI manager("Menu", "Pizza information", "Toppings", "Pizza size", "Make a new pizza");
    ManagerUI topping_menu("Toppings", "Add toppings", "Remove toppings", "See all toppings");


MainUI::MainUI()
{
    run = 0;
}

void MainUI::print_selector(bool run) {
    system("CLS");

    char selector = ' ';

    cout << "Welcome to pizza & co." << endl << endl;

    cout << "----LOGIN SELECTOR----" << endl;
    cout << "(m) Manager" << endl;
    cout << "(b) Baker" << endl;
    cout << "(t) Telephone operator" << endl;
    cout << "(s) Sales clerk" << endl;
    cout << "(q) Quit" << endl;
    if(run){
        cout << "Incorrect input!" << endl;
    }
    cout << ": ";

    cin >> selector;
    selector = lower(selector);

    switch(selector) {
    case 'm':
        ret_val = manager.menuUI(0);
        if(ret_val == 99) {
            print_selector(0);
            ///Returns to User selector
        } else if(ret_val == 1) {
            ///To pizza info menu
        } else if(ret_val == 2) {
            ret_val = topping_menu.menuUI(0);
            toppingCreator(ret_val);
            ///To topping menu
        } else if(ret_val == 3) {
            ///To size menu
        } else if(ret_val == 4) {
            ///To create a new pizza menu
        }

        break;
    case 'b':
        cout << "Nothing to see here!" << endl;
        system("PAUSE");
        print_selector(0);
        break;
    case 't':
        cout << "Nothing to see here!" << endl;
        system("PAUSE");
        print_selector(0);
        break;
    case 's':
        cout << "Nothing to see here!" << endl;
        print_selector(0);
        system("PAUSE");
        break;
    case 'q':
        terminate();
        break;
    default:
        system("CLS");
        print_selector(1);
        break;
    }
}

char MainUI::lower(char instring) {
    StdInput s;
    instring = s.to_lower_case(instring);
    return instring;
}

void MainUI::terminate(){
    system("CLS");
    char cont;

    cout << "Are you sure you want to quit (y/n)? ";
        cin >> cont;
        cont = lower(cont);

    if(cont == 'y'){
        cout << "Good Bye!" << endl;
        exit(0);
    }
    print_selector(0);
    //Double check if user wants to quit, else runs the
    //manager UI again
}

void MainUI::toppingCreator(int ret_val) {
    if(ret_val == 99) {
        //Go one level up, to manager menu
        manager.menuUI(0);

    } else if(0) {

    } else if(0) {

    } else if(0) {

    }
}
