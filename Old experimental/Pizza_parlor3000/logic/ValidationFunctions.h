#ifndef VALIDATIONFUNCTIONS_H
#define VALIDATIONFUNCTIONS_H

#include <strings.h>
#include <iostream>
#include "InvalidNumberException.h"
#include "InvalidAlphaStringException.h"
#include "InvalidBoolException.h"

using namespace std;

void validate_int(string number) {
    for(unsigned int i = 0; i < number.size(); i++) {
        if(!isdigit(number[i])){
            throw(InvalidNumberException());
        }
    }
}
//This function needs a try - catch for InvalidNumberException

void validate_string_input(string input) {
    for(unsigned int i = 0; i < input.size(); i++) {
        if(!isalpha(input[i])) {
            throw(InvalidAlphaStringException());
        }
    }

}
//This function needs a try - catch for InvalidStringException

void validate_bool_question(string input) {
    input = tolower(input[0]);

    if(input.size() > 1) {
        throw(InvalidBoolException(input));
    } else if(input != "y" && input != "n") {
        throw(InvalidBoolException(input));
    }
}

#endif // VALIDATIONFUNCTIONS_H
