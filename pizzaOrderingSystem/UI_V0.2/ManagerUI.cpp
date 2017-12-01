#include "ManagerUI.h"

ManagerUI::ManagerUI() {

}

ManagerUI::ManagerUI(string type, string option1, string option2, string option3) {
    run = 0;
    options = 3;
    this -> type = type;
    this -> option1 = option1;
    this -> option2 = option2;
    this -> option3 = option3;
}

ManagerUI::ManagerUI(string type, string option1, string option2, string option3, string option4) {
    run = 0;
    options = 4;
    this -> type = type;
    this -> option1 = option1;
    this -> option2 = option2;
    this -> option3 = option3;
    this -> option4 = option4;
}

ManagerUI::ManagerUI(string type, string option1, string option2, string option3, string option4, string option5) {
    run = 0;
    options = 5;
    this -> type = type;
    this -> option1 = option1;
    this -> option2 = option2;
    this -> option3 = option3;
    this -> option4 = option4;
    this -> option5 = option5;
}

int ManagerUI::menuUI(bool run){

switch (options){
    case 3:
        system("CLS");

        cout << "----" << type << "----" << endl;
        cout << ("(1) ") << option1 << endl;
        cout << ("(2) ") << option2 << endl;
        cout << ("(3) ") << option3 << endl;
        cout << "(r) Return to User selection" << endl;
        cout << "(q) Terminate program" << endl;

        if(run) {
            cout << "Incorrect input" << endl;
        }

        cout << ": ";

        cin >> selector;
        selector = lower(selector);

        ret_val = selector_func();
        //Sends false to incorrect input (0) and returns
        //interpretation of the user input

        break;

    case 4:
        system("CLS");

        cout << "----" << type << "----" << endl;
        cout << ("(1) ") << option1 << endl;
        cout << ("(2) ") << option2 << endl;
        cout << ("(3) ") << option3 << endl;
        cout << ("(4) ") << option4 << endl;
        cout << "(r) Return to User selection" << endl;
        cout << "(q) Terminate program" << endl;

        if(run) {
            cout << "Incorrect input" << endl;
        }

        cout << ": ";

        cin >> selector;
        selector = lower(selector);

        ret_val = selector_func();
        //Sends false to incorrect input (0) and returns
        //interpretation of the user input
        break;

    case 5:
        system("CLS");

        cout << "----" << type << "----" << endl;
        cout << ("(1) ") << option1 << endl;
        cout << ("(2) ") << option2 << endl;
        cout << ("(3) ") << option3 << endl;
        cout << ("(4) ") << option4 << endl;
        cout << ("(5) ") << option5 << endl;
        cout << "(r) Return to User selection" << endl;
        cout << "(q) Terminate program" << endl;

        if(run) {
            cout << "Incorrect input" << endl;
        }

        cout << ": ";

        cin >> selector;
        selector = lower(selector);

        ret_val = selector_func();
        //Sends false to incorrect input (0) and returns
        //interpretation of the user input

        break;
}

    return ret_val;

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
    menuUI(0);
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

int ManagerUI::selector_func() {
    if((selector > 47 + options) && (selector < 58)){
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
        ret_val = 99;
        break;
    case 'q':
        terminate();
        break;
    default:
        menuUI(1);
        break;

}
    return ret_val;
}
