#include "EmployeeRepo.h"

#include <iostream>

EmployeeRepo::EmployeeRepo() {

}

bool EmployeeRepo::write(Employee e) {

    fstream out("storage.txt", ios::app);
    if(out.is_open()){
        out << e.to_file() << endl;
    } else {
        return 1;
    }
    out.close();
    return 0;
}

vector<string> EmployeeRepo::read() {
    string input;
    strVector.clear();

    fstream in("storage.txt");
    if(in.is_open()){
        while(!in.eof()){
            getline(in, input, ',');
            strVector.push_back(input);
        }
        in.close();
        return strVector;

    } else{
        //return 1;
    }

}

void EmployeeRepo::overwrite(int e, vector<Employee> emp) {
    fstream out("storage.txt");

    if(out.is_open()){
        for(unsigned int i = 0; i < emp.size(); i++){
            out << emp.at(i).to_file() << endl;
        }

    } else{
        cout << "Failed to open" << endl;
        system("PAUSE");
    }
    out.close();

}

vector<Employee> EmployeeRepo::read_all() {
    string input;
    vector<Employee> tempVec;
    tempVec.clear();

    fstream in("storage.txt");
    if(in.is_open()){
        while(!in.eof()){
            getline(in, input, ',');
            empl.set_name(input);
            getline(in, input, ',');
            empl.set_SSN(input);
            getline(in, input, ',');
            empl.set_salary(input);
            getline(in, input, ',');
            empl.set_month(input);
            getline(in, input, ',');
            empl.set_year(input);
            getline(in, input, '\n');


            tempVec.push_back(empl);
        }
    }
    in.close();
    return tempVec;
}

