#ifndef VALIDATIONFUNCTIONS_H
#define VALIDATIONFUNCTIONS_H

#include <strings.h>
#include <iostream>
#include "InvalidNumberException.h"
#include "InvalidAlphaNumException.h"
#include "InvalidDoubleException.h"
#include "InvalidAlphaStringException.h"
#include "InvalidBoolException.h"
#include "InvalidCharException.h"

using namespace std;

inline void validate_int(string number) {
    for(unsigned int i = 0; i < number.size(); i++) {
        if(!isdigit(number[i])){
            throw(InvalidNumberException());
        }
    }
}
//This function needs a try - catch for InvalidNumberException

inline void validate_string_input(string input) {
    for(unsigned int i = 0; i < input.size(); i++) {
        if(!isalpha(input[i]) && !isspace(input[i])) {
            throw(InvalidAlphaStringException());
        }
    }

}
//This function needs a try - catch for InvalidStringException

inline void validate_bool_question(string input) {
    input = tolower(input[0]);

    if(input.size() > 1) {
        throw(InvalidBoolException(input));
    } else if(input != "y" && input != "n") {
        throw(InvalidBoolException(input));
    }
}

inline void validate_double(string input) {
    int dot_count = 0;

    if(isdigit(input[0])) {
        for(unsigned int i = 1; i < input.size(); i++) {
            if(input[i] == '.') {
                dot_count += 1;
            } else if(!isdigit(input[i])) {
                throw(InvalidDoubleException());
            }
            if(dot_count > 1) {
                throw(InvalidDoubleException());
            }
        }
    } else {
        throw(InvalidDoubleException());
    }

}

inline void validate_int_string(string input) {
    for(unsigned int i = 0; i < input.size(); i++) {
        if(!isalnum(input[i]) && !isspace(input[i])) {
            throw(InvalidAlphaNumException());
        }
    }

}

inline void validate_char(string input) {
    if(input.size() > 1) {
        throw(InvalidCharException());
    }
    if(!isalpha(input[0])) {
        throw(InvalidCharException());
    }
}

inline void validate_int_p(string input) {
    if(input.length() > 1) {
        for(unsigned int i = 0; i < input.length(); i++) {
            if(!isdigit(input[i])) {
                throw(InvalidAlphaNumException());
            }
        }
    } else {
        if(input != "n" && input != "q") {
            throw(InvalidAlphaNumException());
        }
    }
}


#endif // VALIDATIONFUNCTIONS_H
