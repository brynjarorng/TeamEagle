#include "Employee.h"

Employee::Employee(){

}

Employee::Employee(string name, string SSN, string salery, string month, string year) {
    this ->name = name;
    this ->SSN = SSN;
    this ->salery = salery;
    this ->month = month;
    this ->year = year;
}

string Employee::to_file() {
    return name + "," + SSN + "," + salery + "," + month + "," + year + ",";
}

void Employee::set_name(string name) {
    this ->name = name;
}

void Employee::set_SSN(string SSN) {
    this ->SSN = SSN;
}

void Employee::set_salery(string salery) {
  this ->salery = salery;
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

string Employee::get_salery(Employee e) {
    return salery;
}

ostream& operator << (ostream& out, Employee& emp) {
    out << emp.name << " " << emp.SSN << " " << emp.salery << " " << emp.month << " " << emp.year << endl;
    return out;
}
