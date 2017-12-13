#include "InvalidBoolException.h"

#include <iostream>

InvalidBoolException::InvalidBoolException(string input){
    if(input.length() == 1){
        this -> exception_type = 1;
    } else if(input.length() > 1) {
        this -> exception_type = 2;
    } else {
        this -> exception_type = 0;
    }
}

string InvalidBoolException::get_err() {
    if(exception_type == 1) {
        return "Invalid option! \nTry again";
    } else if(exception_type == 2) {
        return "Input contains more than one letter! \nTry again" ;
    } else{
         return "Error not defined! \nTry again";
    }

}
