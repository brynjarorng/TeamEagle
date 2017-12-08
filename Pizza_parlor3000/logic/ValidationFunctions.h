#ifndef VALIDATIONFUNCTIONS_H
#define VALIDATIONFUNCTIONS_H

#include <strings.h>
#include <iostream>
#include "InvalidNumberException.h"

using namespace std;

void validate_int(string number) {
    for(insigned int i = 0; i < number.size(); i++) {
        if(!isdigit(number[i])){
            throw(InvalidNumberException());
        }
    }
}
//This function needs a try - catch for InvalidNumberException

#endif // VALIDATIONFUNCTIONS_H
