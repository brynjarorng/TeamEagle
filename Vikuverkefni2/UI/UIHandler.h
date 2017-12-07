#ifndef UIHANDLER_H
#define UIHANDLER_H

#include <iostream>
#include <string>
#include <vector>
#include "EmployeeSaleryHandler.h"
#include "InvalidNameException.h"
#include "InvalidSSNException.h"
#include "InvalidSaleryException.h"
#include "InvalidMonthException.h"
#include "InvalidYearException.h"

using namespace std;

class UIHandler
{
    public:
        UIHandler();
        void add_salery();
        //Get input from user to add a new entry into the database
        //Passes that on to the EmployeeSalaryHandler
        void SSN_salery_lookup();
        //UI for getting salary of a specific SSN
        void salery_per_yer_SSN();
        //UI for getting total salary of a specific SSN for a specific year

    private:
        string name;
        string SSN;
        string salery;
        string month;
        string year;
        vector<string> strVector;
        vector<Employee> empVector;
        bool isValid;
        EmployeeSaleryHandler empl_sal_handl;
};

#endif // UIHANDLER_H
