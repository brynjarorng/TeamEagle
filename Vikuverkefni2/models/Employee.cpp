#include "Employee.h"

Employee::Employee(){

}

string Employee::to_file() {
    return name + "," + SSN + "," + salary + "," + month + "," + year + ",";
}

void Employee::set_name(string name) {
    this ->name = name;
}

void Employee::set_SSN(string SSN) {
    this ->SSN = SSN;
}

void Employee::set_salary(string salery) {
  this ->salary = salary;
}

void Employee::set_month(string month) {
    this ->month = month;
}

void Employee::set_year(string year) {
    this ->year = year;
}

string Employee::get_SSN(Employee e) {
    return SSN;
}

string Employee::get_year(Employee e) {
    return year;
}

string Employee::get_month(Employee e) {
    return month;
}

string Employee::get_salary(Employee e) {
    return salary;
}

ostream& operator << (ostream& out, Employee& emp) {
    out << emp.name << " " << emp.SSN << " " << emp.salary << " " << emp.month << " " << emp.year << endl;
    return out;
}
