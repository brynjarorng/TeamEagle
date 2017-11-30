#include "MainUI.h"
#include <iostream>
#include "ManagerUI.h"

using namespace std;

MainUI::MainUI()
{

}

void MainUI::print_welcome()
{
    cout << "Welcome to pizza & co." << endl << endl;
}

void MainUI::print_selector()
{
    ManagerUI manager;
    char selector = ' ';

    cout << "----LOGIN SELECTOR----" << endl;
    cout << "(m) Manager" << endl;
    cout << "(b) Baker" << endl;
    cout << "(t) Telephone operator" << endl;
    cout << "(s) Sales clerk" << endl;
    cout << ": ";

    cin >> selector;
    selector = lower(selector);

    switch(selector) {
    case 'm':
        manager.manager_menu();
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
    default:
        cout << "Incorrect selection! \nPlease try again." << endl;
        print_selector();
        break;
    }
}

char MainUI::lower(char instring) {
    StdInput s;
    instring = s.to_lower_case(instring);
    return instring;
}
