#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;


class Employee {
    public:
        Employee();
        string to_file();
        //return the private variables in a specific format
        ///name + "," + SSN + "," + salary + "," + month + "," + year + ",";
        void set_name(string name);
        //Set the employees name
        void set_SSN(string SSN);
        //Set the employees SSN
        void set_salary(string salery);
        //Set the employees salary
        void set_month(string month);
        //Set the month when the salary was paid
        void set_year(string year);
        //Set the year when the salary was paid
        string get_SSN(Employee e);
        //return the employees SSN variable
        string get_year(Employee e);
        //return the employees year variable
        string get_month(Employee e);
        //return the employees month variable
        string get_salary(Employee e);
        //return the employees salary variable
        friend ostream& operator << (ostream& out, Employee& emp);


    private:
        string name;
        string SSN;
        string salary;
        string month;
        string year;
};

#endif // EMPLOYEE_H
