#include "MainUI.h"

MainUI::MainUI()
{
    //ctor
}

bool MainUI::print_menu(bool run, bool& contRun) {
    system("CLS");

    cout << "(1) Add a salery" << endl;
    cout << "(2) See all salery records for a given SSN" << endl;
    cout << "(3) See total salery for a given year with a given SSN" << endl;
    cout << "(4) Highest paid staff of a given year" << endl;
    if(run) {
        cout << "incorrect input!" << endl;
    }
    cout << ">";

    cin >> select;

    switch (select) {
    case '1':
        system("CLS");
        ui_handler.add_salery();
        contRun = 1;
        return 0;
        break;

    case '2':
        ui_handler.SSN_salery_lookup();
        contRun = 1;
        return 0;
        break;

    case '3':
        ui_handler.salery_per_yer_SSN();
        contRun = 1;
        return 0;
        break;

    case '4':
        contRun = 1;
        return 0;
        break;

    default:
        contRun = 1;
        return 1;
        break;
    }


}
