#ifndef EMPLOYEEREPO_H
#define EMPLOYEEREPO_H

#include <fstream>
#include "Employee.h"
#include <string>
#include <vector>

using namespace std;

class EmployeeRepo
{
    public:
        EmployeeRepo();
        bool write(Employee e);
        //write the Employee class to file
        vector<string> read();
        //Read from file and return what was read as a vector of strings
        void overwrite(int e, vector<Employee> emp);
        //Function that writes a VECTOR of Employees to a file
        vector<Employee> read_all();
        //Read the whole file and return as a vector of Employees



    private:
        Employee empl;
        vector<string> strVector;
};

#endif // EMPLOYEEREPO_H
