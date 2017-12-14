#include "BakerUI.h"
//#include "print_functions.h"

BakerUI::BakerUI() {

}

bool BakerUI::baker_menu(bool run, bool& continueRun) {
    bool cont = true;
    while(cont) {
        clear();
        cout << "----Baker menu----" << endl;
        print_pizza_baking_list(orderhandler);
        cont = change_status(orderhandler);
    }
    pause_screen();
    return 0;
}
