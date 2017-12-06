#include "EmployeeSaleryHandler.h"

#include <iostream>

using namespace std;


EmployeeSaleryHandler::EmployeeSaleryHandler() {

}

vector<Employee> EmployeeSaleryHandler::read_to_vector() {
    strVector.clear();
    strVector.resize(0);
    empVector.clear();
    empVector.resize(0);

    strVector = repo.read();

    for(unsigned int i = 0; i < strVector.size() - 1; i += 5){
        emp.set_name(strVector[i]);
        emp.set_SSN(strVector[i+1]);
        emp.set_salery(strVector[i+2]);
        emp.set_month(strVector[i+3]);
        emp.set_year(strVector[i+4]);

        empVector.push_back(emp);
    }
    return empVector;
}

void EmployeeSaleryHandler::add_to_vector(string strArr[]) {
    Employee emp1;
    runWrite = 1;

    emp1.set_name(strArr[0]);
    emp1.set_SSN(strArr[1]);
    emp1.set_salery(strArr[2]);
    emp1.set_month(strArr[3]);
    emp1.set_year(strArr[4]);



    vector<Employee> empVectorTemp;
    empVectorTemp.clear();
    empVectorTemp = read_to_vector();

    string tempYear, tempMonth, tempSSN;
    string month = emp1.get_month(emp1);
    string year = emp1.get_year(emp1);
    string SSN = emp1.get_SSN(emp1);


    try{
        for(unsigned int i = 0; i < empVectorTemp.size(); i++) {
            tempYear = empVectorTemp.at(i).get_year(empVectorTemp.at(i));
            tempMonth = empVectorTemp.at(i).get_month(empVectorTemp.at(i));
            tempSSN = empVectorTemp.at(i).get_SSN(empVectorTemp.at(i));
    cout << empVectorTemp.size() << endl;
    system("PAUSE");
            if(SSN == tempSSN){
                if(year == tempYear){
                    if( month == tempMonth){
                        system("PAUSE");
                        runWrite = 0;
                        pos = i;
                        throw(SaleryAlreadyExistsException(i));
                    }
                }
            }
        }
    }
    catch(SaleryAlreadyExistsException e) {
        vector<Employee> temp;
        temp.clear();
        temp = repo.read_all();
        temp.erase(temp.begin() + (pos));
        temp.push_back(emp1);
        repo.overwrite(pos, temp);              //Liklega eh ad her
        temp.clear();

    }

    if(runWrite){
        repo.write(emp1);
    }
    empVectorTemp.clear();
}

bool EmployeeSaleryHandler::validate_name(string name) {
    for(unsigned int i = 0; i < name.length(); i++){
        if(!isalpha(name[i])) {
            if(!isspace(name[i])){
                throw(InvalidNameException());
            }
        }
    }

    return 1;
}

bool EmployeeSaleryHandler::validate_SSN(string SSN) {
    for(unsigned int i = 0; i < SSN.length(); i++) {
        if(SSN.length() != 10 || !isdigit(SSN[i])){
            throw(InvalidSSNException());
        }
    }
    return 1;
}

bool EmployeeSaleryHandler::validate_salery(string salery) {
    for(unsigned int i = 0; i < salery.length(); i++) {
        if(!isdigit(salery[i])){
            throw(InvalidSaleryException());
        }
    }
    return 1;
}

bool EmployeeSaleryHandler::validate_month(string month) {
    for(unsigned int i = 0; i < month.length(); i++) {
        if(isdigit(month[i])){
            if(stoi(month) > 12){
                throw(InvalidMonthException());
            }
        } else {
            throw(InvalidMonthException());
        }
    }
    return 1;
}

bool EmployeeSaleryHandler::validate_year(string year) {
    for(unsigned int i = 0; i < year.length(); i++) {
        if(isdigit(year[i])){
            if(stoi(year) > 2017){
                throw(InvalidYearException());
            }
        } else {
            throw(InvalidYearException());
        }
    }
    return 1;
}

vector<Employee> EmployeeSaleryHandler::get_all_records(string SSN) {
    empVector.clear();
    empVectorTemp.clear();

    empVector = read_to_vector();
    string tempSSN;

    for(unsigned int i = 0; i < empVector.size(); i++) {
        tempSSN = empVector.at(i).get_SSN(empVector.at(i));
        if(SSN == tempSSN){
            empVectorTemp.push_back(empVector.at(i));
        }
    }
return empVectorTemp;
}

int EmployeeSaleryHandler::get_all_records_for_year(string SSN, string year) {
    empVector.clear();
    empVector = read_to_vector();
    string tempSSN;
    string tempYear;
    int tempSalery = 0;

    for(unsigned int i = 0; i < empVector.size(); i++) {
        tempSSN = empVector.at(i).get_SSN(empVector.at(i));
        if(SSN == tempSSN){
            tempYear = empVector.at(i).get_year(empVector.at(i));
            if(year == tempYear){
                tempSalery += stoi(empVector.at(i).get_salery(empVector.at(i)));
            }
        }
    }

return tempSalery;

}
