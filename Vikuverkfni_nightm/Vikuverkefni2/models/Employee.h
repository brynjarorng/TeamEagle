#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>

using namespace std;


class Employee {
    public:
        void set_name(string name);
        void set_SSN(string SSN);
        void set_salary(string salery);
        void set_month(string month);
        void set_year(string year);
        string get_SSN() const;
        string get_year() const;
        string get_month() const;
        string get_salary() const;
        string get_name() const;

    private:
        string name;
        string SSN;
        string salary;
        string month;
        string year;
};

#endif // EMPLOYEE_H
