#ifndef PRINT_FUNCTIONS_H
#define PRINT_FUNCTIONS_H

#include <iostream>

using namespace std;


inline void clear(void) {
#ifdef _WIN32
    system("cls");
#elif defined(unix) || defined(_unix_) || defined(_unix) || (defined(__APPLE_) && defined(_MACH_))
    system("clear");

#else
    #error "OS not supported."
#endif
}


inline void pause_screen() {

    //string dump;
    cout << endl << "---Press Enter to continue---" << endl;
    //cin >> ws;
    //getline(cin, dump, '\n');
    cin.clear();
    cin.ignore();
    cin.get();
    //getchar();
    /*do{
        cout << endl << "---Press Enter to continue---" << endl;
    } while(cin.get() != '\n');
*/
}



#endif // PRINT_FUNCTIONS_H
