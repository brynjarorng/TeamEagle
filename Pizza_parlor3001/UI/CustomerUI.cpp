#include "CustomerUI.h"


CustomerUI::CustomerUI()
{

}

bool CustomerUI::customer_menu(bool run, bool& continueRun) {
    try{
        system("CLS");
        cout << "----Store portal----" << endl;
        cout << "(N) New order" << endl;
        cout << "(M) See all pizzas on menu" << endl;
        cout << "(T) See all available toppings" << endl;
        cout << "(O) See your order status" << endl;
        cout << "(B) Go back to login portal" << endl;
        cout << "(q) Quit" << endl;
        if(run){
            cout << "Incorrect input!" << endl;
        }
        cout << ": ";

        cin >> select;
        select = lower(select);

        switch (select) {
        case 'n':
            system("CLS");
            cout << "New order" << endl;
            pause_screen();

            continueRun = 1;
            return 0;
            break;

        case 'm':
            system("CLS");
            cout << "New order" << endl;
            pause_screen();

            continueRun = 1;
            return 0;
            break;

        case 'a':
            system("CLS");
            cout << "See all available pizzas" << endl;
            pause_screen();

            continueRun = 1;
            return 0;
            break;

        case 't':
            system("CLS");
            cout << "See all available toppings" << endl;
            pause_screen();

            continueRun = 1;
            return 0;
            break;

        case 'o':
            system("CLS");
            cout << "See all your order status" << endl;
            pause_screen();

            continueRun = 1;
            return 0;
            break;

        case 'b':
            continueRun = 0;
            return 0;
            break;

        case 'q':
            terminate();

            continueRun = 1;
            return 0;
            break;

        }
        throw(InvalidInputException());
    }

    catch(InvalidInputException e) {
        continueRun = 1;
        return 1;
    }

    return 0;
}

void CustomerUI::terminate() {
    system("CLS");
    char cont;

    cout << "Are you sure you want to quit (y/n)? ";
        cin >> cont;
        cont = lower(cont);

    if(cont == 'y'){
        cout << "Good Bye!" << endl;
        exit(0);
    }
}

char CustomerUI::lower(char instring) {
    instring = tolower(instring);
    return instring;
}


