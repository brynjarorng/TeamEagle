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

int InvalidBoolException::get_exception() {
    return this ->exception_type;
}
