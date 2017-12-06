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
        vector<string> read();
        void overwrite(int e, vector<Employee> emp);
        vector<Employee> read_all();



    private:
        Employee empl;
        vector<string> strVector;
};

#endif // EMPLOYEEREPO_H
