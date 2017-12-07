#ifndef EMPLOYEESALERYHANDLER_H
#define EMPLOYEESALERYHANDLER_H

#include "Employee.h"
#include "EmployeeRepo.h"
#include "InvalidNameException.h"
#include "InvalidSSNException.h"
#include "InvalidSaleryException.h"
#include "InvalidMonthException.h"
#include "InvalidYearException.h"
#include "SaleryAlreadyExistsException.h"
#include <vector>
#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;


class EmployeeSaleryHandler {
    public:
        EmployeeSaleryHandler();
        vector<Employee> read_to_vector();
        //Calls the repo and returns it as a vector of Employees
        void add_to_vector(string strVector[]);
        //Takes input from the UI, stores it as a vector<Employee>
        //and sends it down to be written. If the entry already exists
        //it is overwritten
        bool validate_name(string name);
        //Check if input name is valid else throw an exception
        bool validate_SSN(string SSN);
        //Check if input SSN is valid else throw an exception
        bool validate_salery(string salery);
        //Check if input month is valid else throw an exception
        bool validate_month(string month);
        //Check if input month is valid else throw an exception
        bool validate_year(string month);
        //Check if input year is valid else throw an exception
        vector<Employee> get_all_records(string SSN);
        //Call the repo to read everything from a file and return
        //it as a vector<Employee>
        int get_all_records_for_year(string SSN, string year);
        //Find all records of a specific year, add the salary and return it

    private:
        Employee emp;
        EmployeeRepo repo;
        vector<string> strVector;
        vector<Employee> empVector;
        vector<Employee> empVectorTemp;
        bool runWrite;
        int pos;
};

#endif // EMPLOYEESALERYHANDLER_H
