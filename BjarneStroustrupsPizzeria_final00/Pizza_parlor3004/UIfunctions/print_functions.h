#ifndef PRINT_FUNCTIONS_H
#define PRINT_FUNCTIONS_H

#include <iostream>

using namespace std;


inline void clear() {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


inline void pause_screen() {

    cout << endl << "---Enter any character to continue---" << endl;
    cin >> ws;
    string dump;
    getline(cin, dump, '\n');

}



#endif // PRINT_FUNCTIONS_H
