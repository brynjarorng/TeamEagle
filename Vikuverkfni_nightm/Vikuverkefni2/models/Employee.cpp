#include "Employee.h"

void Employee::set_name(string name) {
    this ->name = name;
}

void Employee::set_SSN(string SSN) {
    this ->SSN = SSN;
}

void Employee::set_salary(string salary) {
  this ->salary = salary;
}

void Employee::set_month(string month) {
    this ->month = month;
}

void Employee::set_year(string year) {
    this ->year = year;
}
string Employee::get_name() const{
    return this ->name;
}
string Employee::get_SSN() const{
    return this->SSN;
}

string Employee::get_year() const{
    return this->year;
}

string Employee::get_month() const{
    return this->month;
}

string Employee::get_salary() const{
    return this->salary;
}
