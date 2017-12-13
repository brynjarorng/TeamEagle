#ifndef BAKERUI_H
#define BAKERUI_H

#include <iostream>
#include <stdlib.h>
#include <iostream>
#include "UITemplate.h"


using namespace std;

class BakerUI: public UITemplate {
    public:
        BakerUI();
        bool baker_menu(bool run, bool& continueRun);
        //Prints out the main menu for the baker
        ///Design not chosen yet
        char lower(char instr);
        //takes in a character and makes it
        //lower case (A -> a)
        void terminate();
        //stop the program

    private:

};

#endif // BAKERUI_H
