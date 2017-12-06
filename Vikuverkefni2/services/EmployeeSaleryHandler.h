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
        void add_to_vector(string strVector[]);
        bool validate_name(string name);
        bool validate_SSN(string SSN);
        bool validate_salery(string salery);
        bool validate_month(string month);
        bool validate_year(string month);
        vector<Employee> get_all_records(string SSN);
        int get_all_records_for_year(string SSN, string year);

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
