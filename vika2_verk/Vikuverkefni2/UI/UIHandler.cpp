#include "UIHandler.h"

#include <stdlib.h>

UIHandler::UIHandler()
{
    this -> isValid = 0;
}


void UIHandler::add_salery() {
    do{
        cout << "Name: ";
        try{
            cin.ignore();   //Ignores whitespaces for getline to work properly
            getline(cin, name);
            isValid = empl_sal_handl.validate_name(name);
        }
        catch(InvalidNameException e){
            isValid = 0;
            cout << "Invalid name! try again." << endl;
        }
    } while(!isValid);

    do{
        cout << "SSN (10 digits): ";
        try{
            cin >> SSN;
            isValid = empl_sal_handl.validate_SSN(SSN);
        }
        catch(InvalidSSNException e) {
            isValid = 0;
            cout << "Invalid SSN! try again." << endl;
        }
    } while(!isValid);

    do{
        cout << "Salery: ";
        try{
            cin >> salery;
            isValid = empl_sal_handl.validate_salery(salery);
        }
        catch(InvalidSaleryException e) {
            isValid = 0;
            cout << "Invalid salery! try again." << endl;
        }
    } while(!isValid);

    do{
        cout << "Month (number): ";
        try{
            cin >> month;
            isValid = empl_sal_handl.validate_month(month);
        }
        catch(InvalidMonthException e) {
            isValid = 0;
            cout << "Invalid month! try again." << endl;
        }
    } while(!isValid);

    do{
        cout << "Year: ";
        try{
            cin >> year;
            isValid = empl_sal_handl.validate_year(year);
        }
        catch(InvalidYearException e) {
            isValid = 0;
            cout << "Invalid year! try again." << endl;
        }
    }while(!isValid);
string temp[5];

    month = empl_sal_handl.convert_month_to_2_digits(month);
    Employee e;
    e.set_name(name);
    e.set_SSN(SSN);
    e.set_salary(salery);
    e.set_month(month);
    e.set_year(year);

    empl_sal_handl.create(e);
}

void UIHandler::SSN_salery_lookup() {
    system("CLS");

    do{
        try{
            cout << "Enter SSN to look up: ";
            cin >> SSN;

            isValid = empl_sal_handl.validate_SSN(SSN);
        }
        catch(InvalidSSNException e) {
            isValid = 0;
            cout << "Invalid SSN! try again." << endl;
        }

    }while(!isValid);

        print_by_SSN(SSN);


    system("PAUSE");


}

void UIHandler::salery_per_yer_SSN() {
        system("CLS");
        int sal = 0;

    do{
        try{
            cout << "Enter SSN to look up: ";
            cin >> SSN;

            isValid = empl_sal_handl.validate_SSN(SSN);
        }
        catch(InvalidSSNException e) {
            isValid = 0;
            cout << "Invalid SSN! try again." << endl;
        }

    }while(!isValid);

    do{
        try{
            cout << "Enter year to look up: ";
            cin >> year;

            isValid = empl_sal_handl.validate_year(year);
        }
        catch(InvalidYearException e) {
            isValid = 0;
            cout << "Invalid year! try again" << endl;
        }
    } while(!isValid);

    print_total_salary(SSN, year);
    //sal = empl_sal_handl.get_all_records_for_year(SSN, year);

    //cout << "Total salery: " << sal << endl;
    system("PAUSE");

}


void UIHandler::print_total_salary(string SSN, string year) {

    Retr_SSN_Info temp = empl_sal_handl.get_all_records(SSN);

    cout << "Employees name: " << temp.name << endl;
    cout << "Employees SSN: " << temp.SSN << endl;

    string total_salary = empl_sal_handl.total_salary_by_year(year, SSN);

  cout << "Total salary: $" << total_salary << endl;
}
void UIHandler::highest_salary_by_year() {
    year = "";
    Employee empl;
        do{
        cout << "Year: ";
        try{
            cin >> year;
            isValid = empl_sal_handl.validate_year(year);
        }
        catch(InvalidYearException e) {
            isValid = 0;
            cout << "Invalid year! try again." << endl;
        }
    }while(!isValid);

   empl = empl_sal_handl.higest_employee(year);

 /*  cout << "Highest payed employee: "     << endl
        << "Name: "  << empl.get_name()   << endl
        << "SSN: "   << empl.get_SSN()    << endl
        << "Total $" << empl.get_salary() << endl;*/
}

void UIHandler::print_lines(int i){
    for (int n = 0; n < i; n ++) {
        cout << "-";
    }
    cout << endl;
}
void UIHandler::print_by_SSN(string SSN) {

    Retr_SSN_Info temp = empl_sal_handl.get_all_records(SSN);
    print_lines(15);
    cout << "Name: " << temp.name << endl;
    cout << "SSN: " << temp.SSN << endl;
    print_lines(15);

    for (int i = 0; i < temp.nr_of_entries; i++) {
        print_lines(15);
        cout << "Entry #" << i + 1 << endl;
        cout << "Date: " << empl_sal_handl.int_to_month(temp.month[i])
             << " " << temp.year[i] << endl;
        cout << "Salary: " << temp.salary[i] << endl;
    }
    print_lines(15);
    cout << "End of entries." << endl;
}

