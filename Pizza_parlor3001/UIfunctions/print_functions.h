#ifndef PRINT_FUNCTIONS_H
#define PRINT_FUNCTIONS_H

#include <iostream>

using namespace std;

inline void pause_screen() {
    cin.ignore();
    string dump;
    cout << endl << "---Press Enter to continue---" << endl;
    getline(cin, dump);
}


#endif // PRINT_FUNCTIONS_H
