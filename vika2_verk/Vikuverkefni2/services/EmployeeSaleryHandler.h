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
 struct Retr_SSN_Info {
        string name;
        string SSN;
        vector<string>month;
        vector<string>year;
        vector<string>salary;
        int nr_of_entries;
        };

        struct Retr_year_Info {
        string year;
        vector<string>SSN;
        vector<string>month;
        vector<string>salary;
        vector<string>name;
        int nr_of_entries;
        };


class EmployeeSaleryHandler {



    public:

        Employee higest_employee(string year);
        Retr_SSN_Info get_info_on_SSN(string SSN);
        //Returns information retrived by SSN.
        Retr_year_Info get_info_on_year(string year);
        //Returns the information from the year DATABASE in the form of
        //a struct defined above.
        EmployeeSaleryHandler();
        vector<Employee> read_to_vector();
        //Calls the repo and returns it as a vector of Employees
        void create(Employee emp);
        //Input is a instance of employee, which is written
        //to a file through a repo.
        bool validate_name(string name);
            Retr_SSN_Info get_all_records(string SSN);
        //Check if input name is valid else throw an exception
        bool validate_SSN(string SSN);
        //Check if input SSN is valid else throw an exception
        bool validate_salery(string salery);
        //Check if input month is valid else throw an exception
        bool validate_month(string month);
        //Check if input month is valid else throw an exception
        bool validate_year(string month);
        //Check if input year is valid else throw an exception
        //vector<Employee> get_all_records(string SSN);
        //Call the repo to read everything from a file and return
        //it as a vector<Employee>
        int get_all_records_for_year(string SSN, string year);
        //Find all records of a specific year, add the salary and return it
        string int_to_month(string month);
        //Converts the integer month to the string month.

        string total_salary_by_year(string year, string SSN);
        //The return value is the total salary of a employee for
        //a given year.
        string convert_month_to_2_digits(string in);
        //Format will be nn.
        bool same_month(Employee emp);
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
