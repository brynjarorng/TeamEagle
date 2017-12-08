#include "EmployeeRepo.h"

#include <iostream>

EmployeeRepo::EmployeeRepo() {
    //
}

vector<string> EmployeeRepo::read_until_comma(string in) {

    vector<string> temp_v;
    string temp = "";

    int index = 0;
    index = in.find(',');
    while (index != (-1)) {
        temp = in.substr(0, index);
        temp_v.push_back(temp);
        temp = "";
        in.erase(0, index + 1);
        index = in.find(',');
    }
    return temp_v;
}

void EmployeeRepo::write(Employee e) {

        write_by_id(e);
        write_by_year(e);
}
/*
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
*/
void EmployeeRepo::write_by_year(Employee e) {

    string year = e.get_year();
    string folder = DATABASE_FOLDER;
    string store_by_year = "year/" + year + "_data.txt";

    fstream y_out((folder + store_by_year), ios::app);

    if(first_instance(e.get_year(), (folder + store_by_year), 6 )){
        y_out << "Year: " << e.get_year() << endl;
        y_out << "----------------------------------" << endl;
    }

    y_out << year_write_format(e);

    y_out.close();
}

int EmployeeRepo::month_position(Employee emp){

    string year = emp.get_year();
    string folder = DATABASE_FOLDER + "year/" + year + "_data.txt";
    string month = emp.get_month();
    fstream in(folder);
    string that_month;
    string trash;
    int tell = -1;
    if (in.is_open()) {
        in.seekg(46);
        while (getline(in, that_month, ',')) {
        if (that_month == month) {
            tell = (in.tellg() - 2);//Must be -2 since 2 characters were read.
            return tell;
        }
        that_month = "";
        getline(in, trash , '\n');
        }

        in.close();
        return tell;
    }
    in.close();
    return tell;
}
void EmployeeRepo::rewrite(Employee e) {

    int tell = month_position(e);//Checks for same month.
            rewrite_year_data(tell, e);
            rewrite_id_data(e, e.get_month());

}
void EmployeeRepo::rewrite_id_data(Employee e, string month) {

    string SSN = e.get_SSN();
    string folder = DATABASE_FOLDER + "id/" + SSN + "_data.txt";
    string trash;
    vector<string> lines;
    string line;
    string emp = id_write_format(e);
    fstream in(folder);

    int tell = find_line_in_id(month, SSN);
    if (tell != -1)
        if (in.is_open()) {
            in.seekg(tell);
            getline(in, trash, '\n');
        while (getline(in, line)) {
        lines.push_back(line);
    }
        rewrite_data(emp, folder, (tell-2), lines);
    }
    in.close();
}

int EmployeeRepo::find_line_in_id(string month, string SSN) {

    int tell;
    string input;
    string trash;
    string folder = DATABASE_FOLDER + "id/" + SSN + "_data.txt";
    fstream in (folder);

    if (in.is_open()) {
        in.seekg(62);
        while (!in.eof()) {
        getline(in, input,',');
        if (input == month) {
            tell = in.tellg();
            in.close();
            return tell - 1;
        }
        getline(in, trash, '\n');
        }
    }
    in.close();
    return -1;
}

int EmployeeRepo::same_SSN(Employee e, int tell) {

    string year = e.get_year();
    string folder = DATABASE_FOLDER + "year/" + year + "_data.txt";
    string SSN = e.get_SSN();
    string that_SSN;
    string trash;

    fstream in(folder);

    if (in.is_open()) {
        in.seekg(tell - 2);
            getline(in, trash, ',');
            getline(in, trash, ',');
            getline(in, that_SSN, ',');
            if (that_SSN == SSN) {
                return 1;
            }
            else {
                return 0;
            }
        }
    return -1;
}

void EmployeeRepo::rewrite_year_data(int tell, Employee e) {

    string year = e.get_year();
    string folder = DATABASE_FOLDER + "year/" + year + "_data.txt";
    string trash;
    vector<string> lines;
    string line;
    string emp = year_write_format(e);


    fstream in(folder);

    if (in.is_open()) {
        in.seekg(tell);
        getline(in, trash, '\n');

        while (getline(in, line)) {
        cout << "Line: " << line << endl;
        lines.push_back(line);
        }
        line = "";
        in.close();
        rewrite_data(emp, folder, (tell - 1), lines);
    }
}

void EmployeeRepo::rewrite_data(string emp, string folder, int tell, vector<string> lines) {

    fstream sout(folder);
    sout.seekg(tell);

    sout << emp;
    for (unsigned int i = 0; i < lines.size(); i++) {
        sout << lines[i] << endl;
    }

    sout.close();
}


string EmployeeRepo::year_write_format(Employee e) {

    string temp = e.get_month()   + ","
                + e.get_name()   + ","
                + e.get_SSN()    + ","
                + e.get_salary() + ",\n";

    return temp;
}

bool EmployeeRepo::first_instance(string input, string file, int pos) {

    fstream in(file);

    string first;
    if (in.is_open()) {
        in.seekg(pos);
        getline(in, first);
        in.seekg(0, in.beg);
        if (input != first) {
            return true;
        }
        else {
            return false;
        }
    }
    in.close();
    return true;
}
void EmployeeRepo::write_by_id(Employee e) {

     string id = e.get_SSN();
     string folder = DATABASE_FOLDER;
     string store_by_id = "id/" + id + "_data.txt";
     fstream i_out((folder + store_by_id), ios::app);

    if (first_instance(e.get_SSN(), (folder + store_by_id), 5)) {
        i_out << "SSN: " << e.get_SSN() << endl;
        i_out << "Name: " << e.get_name() << endl;
        i_out << "----------------------------------" << endl;

    }

    i_out << id_write_format(e);

    i_out.close();
}

string EmployeeRepo::id_write_format(Employee e) {

    string temp = e.get_month()   +  ","
                + e.get_year()    +  ","
                + e.get_salary()  +  ",\n";
    return temp;
}

void EmployeeRepo::get_year_from_stream(string& out_year, string in_year) {

    string trash;
    string folder = DATABASE_FOLDER;
    fstream in(folder + "year/" + in_year + "_data.txt");

    in.seekg(6);
    getline(in, out_year);
    in.close();
}

vector<string> EmployeeRepo::open_by_year(string year) {

    vector<string> return_vector;
    string input, name, SSN, salary;
    string folder = DATABASE_FOLDER;

    int new_line_index;
    fstream in(folder + "year/" + year + "_data.txt");

    if(in.is_open()){
        string w_year;
        get_year_from_stream(w_year, year);
        return_vector.push_back(year);
        in.seekg(46);
        while(getline(in, input, ',')){
            input = remove_new_line(input);

            return_vector.push_back(input);
        }
        in.close();

        return return_vector;
    }
}

void EmployeeRepo::get_name_ssn_from_stream(string& name, string& id, string SSN) {

    string trash;
    string folder = DATABASE_FOLDER;
    fstream in(folder + "id/" + SSN + "_data.txt");

    in.seekg(5);
    getline(in, id);
    in.seekg(0, in.beg);
    getline(in, trash);
    in.seekg(22);
    getline(in, name);
    in.seekg(0, in.beg);
    getline(in, trash);

    in.close();
}

vector<string> EmployeeRepo::open_by_SSN(string SSN) {

    vector<string> return_vector;
    string input, name, id;
    string folder = DATABASE_FOLDER;

    get_name_ssn_from_stream(name, id, SSN);

    return_vector.push_back(name);
    return_vector.push_back(id);

    int new_line_index;
    fstream in(folder + "id/" + SSN + "_data.txt");
    if(in.is_open()){
        in.seekg(62);
        while(getline(in, input, ',')){
            input = remove_new_line(input);
            return_vector.push_back(input);
        }
        in.close();
        return return_vector;
    }
}



string EmployeeRepo::remove_new_line(string in) {

    string temp = "";

    for (int i = 0; i < in.length(); i++) {
        if (in.at(i) != '\n') {
            temp += in[i];
        }
    }
    return temp;
}
