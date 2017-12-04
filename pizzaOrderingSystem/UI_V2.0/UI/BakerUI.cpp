#include "BakerUI.h"


BakerUI::BakerUI() {

}

int BakerUI::baker_menu() {
    system("CLS");
    cout << "----Baker menu----" << endl;
    system("Pause");
    return 0;
}

void BakerUI::terminate() {
    system("CLS");
    char cont;

    cout << "Are you sure you want to quit (y/n)? ";
        cin >> cont;
        cont = lower(cont);

    if(cont == 'y'){
        cout << "Good Bye!" << endl;
        exit(0);
    }
    baker_menu();
    //Double check if user wants to quit, else runs the
    //manager UI again
}

char BakerUI::lower(char instring) {
    instring = tolower(instring);
    return instring;
}

