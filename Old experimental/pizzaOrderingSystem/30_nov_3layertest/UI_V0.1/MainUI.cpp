#include "MainUI.h"
#include <iostream>
#include "ManagerUI.h"

using namespace std;

MainUI::MainUI()
{
    run = 0;
}

void MainUI::print_selector(bool run)
{
    ManagerUI manager;
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
        manager.manager_menu(0);
        break;
    case 'b':
        cout << "Nothing to see here!" << endl;
        break;
    case 't':
        cout << "Nothing to see here!" << endl;
        break;
    case 's':
        cout << "Nothing to see here!" << endl;
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
