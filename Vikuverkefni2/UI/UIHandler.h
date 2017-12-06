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
        void SSN_salery_lookup();
        void salery_per_yer_SSN();

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
