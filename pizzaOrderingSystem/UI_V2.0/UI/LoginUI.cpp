#include "LoginUI.h"

LoginUI::LoginUI()
{

}


void MainUI::login_portal(bool run) {
    system("CLS");

    cout << "Welcome to pizza & co." << endl << endl;

    cout << "----LOGIN SELECTOR----" << endl;
    cout << "(m) Manager" << endl;
    cout << "(b) Baker" << endl;
    cout << "(t) Telephone operator" << endl;
    cout << "(s) Sales clerk" << endl;
    cout << "(c) Customer portal" << endl;
    cout << "(q) Quit" << endl;
    if(run){
        cout << "Incorrect input!" << endl;
    }
    cout << ": ";

    cin >> selector;
    select = lower(select);

    switch(selector) {
    case 'm':

            ///The manager selection UI page
        break;
    case 'b':

            ///The baker menu page
        break;
    case 't':

            ///The phone clerk menu page
        break;
    case 's':

            ///The store clerk selector page
        break;
    case 'c':

            ///The customer selector page
        break;
    case 'q':
            terminate();
            ///Halts the program
        break;
    default:
            system("CLS");
            print_login_selector(1);
            ///Print the login selector again with the error message
        break;
    }

}



void MainUI::terminate() {
    system("CLS");
    char cont;

    cout << "Are you sure you want to quit (y/n)? ";
        cin >> cont;
        cont = lower(cont);

    if(cont == 'y'){
        cout << "Good Bye!" << endl;
        exit(0);
    }
    print_login_selector(0);
    //Double check if user wants to quit, else runs the
    //manager UI again
}
///Every UI has this termination class

char MainUI::lower(char instring) {
    StdInput s;
    instring = s.to_lower_case(instring);
    return instring;
}

///Every class has this to lower function
