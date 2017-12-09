#include <iostream>

#include "MainUI.h"

using namespace std;


int main()
{
    //EmployeeRepo repo;
    //Retr_SSN_Info test = repo.get_info_on_SSN("0512852989");

   bool run = 0;
    MainUI ui;
    bool contRun = 1;


    do{
        run = ui.print_menu(run, contRun);
    } while(contRun);


    return 0;
}

