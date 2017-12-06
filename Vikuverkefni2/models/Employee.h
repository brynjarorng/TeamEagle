#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;


class Employee {
    public:
        Employee();
        Employee(string name, string SSN, string salery, string month, string year);
        string to_file();
        void set_name(string name);
        void set_SSN(string SSN);
        void set_salery(string salery);
        void set_month(string month);
        void set_year(string year);
        string get_SSN(Employee e);
        string get_year(Employee e);
        string get_month(Employee e);
        string get_salery(Employee e);
        friend ostream& operator << (ostream& out, Employee& emp);

    private:
        string name;
        string SSN;
        string salery;
        string month;
        string year;
};

#endif // EMPLOYEE_H
