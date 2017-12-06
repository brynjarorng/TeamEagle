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

    temp[0] = (name);
    temp[1] = (SSN);
    temp[2] = (salery);
    temp[3] = (month);
    temp[4] = (year);

    //add to vector and write down
    empl_sal_handl.add_to_vector(temp);


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

    empVector = empl_sal_handl.get_all_records(SSN);

    for(unsigned int i = 0; i < empVector.size(); i++) {
        cout << empVector.at(i);
    }
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

    sal = empl_sal_handl.get_all_records_for_year(SSN, year);

    cout << "Total salery: " << sal << endl;
    system("PAUSE");

}







