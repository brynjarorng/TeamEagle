#include "LoginUI.h"

LoginUI::LoginUI() {
    this ->continueRun = 0;
}


bool LoginUI::login_portal(bool run) {
    try {

        clear();

        cout << "Welcome to Stroustrup Pizzeria" << endl << endl;

        cout << "----LOGIN SELECTOR----" << endl;
        cout << "(M) Manager" << endl;
        cout << "(B) Baker" << endl;
        cout << "(T) Telephone operator" << endl;
        cout << "(S) Sales clerk" << endl;
        cout << "(C) Customer portal" << endl;
        cout << "(Q) Quit" << endl;
        if(run){
            cout << "Incorrect input!" << endl;
        }
        cout << ": ";

        cin >> select;
        select = lower(select);

        switch(select) {
        case 'm':
            run = 0;
            do{
                run = mUI.manager_menu(run, continueRun);
            } while(continueRun);
            return 0;
                ///The manager selection UI page
            break;

        case 'b':
            run = 0;
            bUI.choose_location();
            do{
                run = bUI.baker_menu(run, continueRun);
            } while(continueRun);
            return 0;
                ///The baker menu page
            break;

        case 't':
            run = 0;
            do{
                run = pUI.phone_menu(run, continueRun);
            } while(continueRun);
            return 0;
                ///The phone clerk menu page
            break;

        case 's':
            sUI.choose_location();
            run = 0;
            do{
                run = sUI.store_menu(run, continueRun);
            } while(continueRun);
            return 0;
                ///The store clerk selector page
            break;

        case 'c':
            run = 0;
            choose_location();
            do{
                run = cUI.customer_menu(run, continueRun);
            } while(continueRun);
            return 0;
                ///The customer selector page
            break;

        case 'q':
                terminate();
                ///Halts the program
            break;
        }
        throw (InvalidInputException());
    }

    catch (InvalidInputException e) {
        return 1;
    }
}



void LoginUI::terminate() {
    clear();
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


