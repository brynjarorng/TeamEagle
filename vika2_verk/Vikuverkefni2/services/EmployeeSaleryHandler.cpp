#include "EmployeeSaleryHandler.h"
#include <cstdlib>


#include <iostream>

using namespace std;


EmployeeSaleryHandler::EmployeeSaleryHandler() {

}

/*vector<Employee> EmployeeSaleryHandler::read_to_vector() {
    strVector.clear();
    strVector.resize(0);
    empVector.clear();
    empVector.resize(0);

//   strVector = repo.read();

    for(unsigned int i = 0; i < strVector.size() - 1; i += 5){
        emp.set_name(strVector[i]);
        emp.set_SSN(strVector[i+1]);
        emp.set_salary(strVector[i+2]);
        emp.set_month(strVector[i+3]);
        emp.set_year(strVector[i+4]);

        empVector.push_back(emp);
    }
    return empVector;
}
*/
Retr_SSN_Info EmployeeSaleryHandler::get_all_records(string SSN) {
    EmployeeRepo repo;
    Retr_SSN_Info temp = get_info_on_SSN(SSN);
    return temp;
}
bool EmployeeSaleryHandler::same_month(Employee emp) {

    string SSN = emp.get_SSN();
    string month = emp.get_month();

    Retr_SSN_Info id_info = get_all_records(SSN);
    for (int i = 0; i < id_info.nr_of_entries; i++) {
        if (id_info.month[i] == month) {

            return true;
        }

    }
    return false;
//Retr_SSN_Info SSN info = repo.get_info_on_SSN()
}
void rewrite(Employee emp) {
    //get_postition = repo.stream_pos(emp.get_month())
}

void EmployeeSaleryHandler::create(Employee emp) {

        if (same_month(emp)) {
            repo.rewrite(emp);
        }
        else {
        repo.write(emp);
        }
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
            if(stoi(month) > 12 || stoi(month) < 1){
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
            if(stoi(year) > 2017 || stoi(year) < 1890){
                throw(InvalidYearException());
            }
        } else {
            throw(InvalidYearException());
        }
    }
    return 1;
}


string EmployeeSaleryHandler::total_salary_by_year(string year, string SSN) {

    Retr_year_Info temp = get_info_on_year(year);
    int salary = 0;

    for (int i = 0; i < temp.nr_of_entries; i++) {
        if (SSN == temp.SSN[i])
        salary += stoi(temp.salary[i]);
    }

    string ret  = to_string(salary);
    return ret;
}

Employee EmployeeSaleryHandler::higest_employee(string year) {

    Retr_year_Info info = get_info_on_year(year);

    Employee highest_empl;
    highest_empl.set_SSN(info.SSN[0]);


    string highest_salary = total_salary_by_year(year, highest_empl.get_SSN());

    int empl1, empl2;

    empl1 = stoi(total_salary_by_year(year, info.SSN[0] ) );
    //empl2 = stoi(highest_salary(year, info.SSN[1]));

    for (int i = 0; i < info.nr_of_entries; i++) {
        if (highest_empl.get_SSN() != info.SSN[i] ) {
            cout << "her" << endl;
            empl2 = stoi( total_salary_by_year(year, info.SSN[i]));
            cout << "empl2 " << empl2 <<endl;
            if (empl2 > empl1) {
                highest_empl.set_SSN( info.SSN[i] );
                empl1 = empl2;
            }
        }

    }


cout << highest_empl.get_SSN() << " ssn " << endl;

  return highest_empl;
}

int EmployeeSaleryHandler::get_all_records_for_year(string SSN, string year) {
    empVector.clear();
//    empVector = read_to_vector();
    string tempSSN;
    string tempYear;
    int tempSalery = 0;

    for(unsigned int i = 0; i < empVector.size(); i++) {
        tempSSN = empVector.at(i).get_SSN();
        if(SSN == tempSSN){
            tempYear = empVector.at(i).get_year();
            if(year == tempYear){
                tempSalery += stoi(empVector.at(i).get_salary());
            }
        }
    }

return tempSalery;

}
Employee highest_payed(int& total_pay, string year) {

   /* struct HighestPayed{string SSN; string tot_pay};
    EmployeeRepo repo;
    HighestPayed first, HighestPayed second;
    Retr_year_Info temp = repo.get_info_on_year(year);
    for (int i = 0; i < temp.nr_of_entries; i++) {
        first.SSI = temp.SSI[i];
        first.tot_pay = temp[i].tot_pay;
            for(int j = 0; j < temp.nr_of_entries; j++) {
                if (j != i && first.SSI == temp.SSI[j]) {
                    first.tot_pay += temp.salary[j];
                }
            }

        }
    }*/
}



string EmployeeSaleryHandler::int_to_month(string month) {

    int month_ = stoi(month);
    switch (month_) {
        case 1:
            return "January";
            break;
        case 2:
            return "February";
            break;
        case 3:
            return "March";
            break;
        case 4:
            return "April";
            break;
        case 5:
            return "May";
            break;
        case 6:
            return "June";
            break;
        case 7:
            return "July";
            break;
        case 8:
            return "August";
            break;
        case 9:
            return "September";
            break;
        case 10:
            return "Oktober";
            break;
        case 11:
            return "November";
            break;
        case 12:
            return "December";
            break;
    }
}
string EmployeeSaleryHandler::convert_month_to_2_digits(string in) {


    if (stoi(in) < 10 && in[0] != '0') {
        in = '0' + in;

    }
    return in;
}

Retr_SSN_Info EmployeeSaleryHandler::get_info_on_SSN(string SSN) {

    Retr_SSN_Info get;
    vector<string> tmp = repo.open_by_SSN(SSN);
    get.name = tmp[0];
    get.SSN =  tmp[1];

    string month, year, salary, whitespace;
    get.nr_of_entries = 0;

    for (unsigned int i = 2; i < tmp.size() - 1; i = i + 3) {

            month = tmp[i];
            year = tmp[i + 1];
            salary = tmp[i + 2];
            get.month.push_back(month);
            get.year.push_back(year);
            get.salary.push_back(salary);

            get.nr_of_entries++;
    }

    return get;
}

Retr_year_Info EmployeeSaleryHandler::get_info_on_year(string year) {

    Retr_year_Info get;
    vector<string> tmp = repo.open_by_year(year);
    get.year = tmp[0];

    string month, name, salary, SSN;
    get.nr_of_entries = 0;

    for (unsigned int i = 1; i < tmp.size() - 1; i = i + 4) {

            month = tmp[i];


            name = tmp[i + 1];
            SSN = tmp[i + 2];
            salary = tmp[i + 3];

            get.name.push_back(name);
            get.month.push_back(month);
            get.SSN.push_back(SSN);
            get.salary.push_back(salary);
            get.nr_of_entries++;
    }

    return get;
}
