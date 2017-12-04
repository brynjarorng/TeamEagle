#include "LoginUI.h"

LoginUI::LoginUI()
{

}


void LoginUI::login_portal(bool run) {
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

    cin >> select;
    select = lower(select);

    switch(select) {
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
            login_portal(1);
            ///Print the login selector again with the error message
        break;
    }

}



void LoginUI::terminate() {
    system("CLS");
    char cont;

    cout << "Are you sure you want to quit (y/n)? ";
        cin >> cont;
        cont = lower(cont);

    if(cont == 'y'){
        cout << "Good Bye!" << endl;
        exit(0);
    }
    login_portal(0);
    //Double check if user wants to quit, else runs the
    //manager UI again
}

char LoginUI::lower(char instring) {
    instring = tolower(instring);
    return instring;
}
