#include "ManagerUI.h"

ManagerUI::ManagerUI() {
    run = 0;
}

int ManagerUI::menuUI(){

switch (options){
    string type;    ///type of menu
    char selector;  ///select the appropriate option
    string optionXX ///text to output as an option
    int ret_val = 0;///Val to return to indicate what option was chosen


    case 3:
        cout << type << endl;
        cout << option1 << endl;
        cout << option2 << endl;
        cout << option3 << endl;
        cout << "(r) Return to User selection" << endl;
        cout << "(q) Terminate program" << endl;

        if(run) {
            cout << "Incorrect input" << endl;
        }

        cout << ": ";

        cin >> selector;
        selector = lower(selector);

        break;

    case 4:
        cout << type << endl;
        cout << option1 << endl;
        cout << option2 << endl;
        cout << option3 << endl;
        cout << option4 << endl;
        cout << "(r) Return to User selection" << endl;
        cout << "(q) Terminate program" << endl;

        if(run) {
            cout << "Incorrect input" << endl;
        }

        cout << ": ";

        cin >> selector;
        selector = lower(selector);
        break;

    case 5:
        cout << type << endl;
        cout << option1 << endl;
        cout << option2 << endl;
        cout << option3 << endl;
        cout << option4 << endl;
        cout << option5 << endl;
        cout << "(r) Return to User selection" << endl;
        cout << "(q) Terminate program" << endl;

        if(run) {
            cout << "Incorrect input" << endl;
        }

        cout << ": ";

        cin >> selector;
        selector = lower(selector);
        break;
}



}




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
    list_submenu(0);
    //Double check if user wants to quit, else runs the
    //manager UI again
}

void ManagerUI::ret_to_main(){
    MainUI ui;

    system("CLS");
    ui.print_selector(0);
}
//returns to the User selection

char ManagerUI::lower(char instring) {
    StdInput s;
    instring = s.to_lower_case(instring);
    return instring;
}
//calls a function to put input to lower case

int selector_func(bool selector) {
    if(selector > 47 + option && selector < 58){
        menuUI(1);
    }
    //if number inputed is too high send back to main function

switch(selector) {
    case '1':
        ret_val = 1;
        break;
    case '2':
        ret_val = 2;
        break;
    case '3':
        ret_val = 3;
        break;
    case '4':
        ret_val = 4;
        break;
    case '5':
        ret_val = 5;
        break;
    case 'r':
        ret_to_main();
        break;
    case 'q':
        terminate();
        break;
    default:
        menuUI(1);
        break;

    return ret_val;
}
