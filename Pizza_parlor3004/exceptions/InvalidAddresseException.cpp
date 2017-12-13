#include "InvalidAddresseException.h"

InvalidAddresseException::InvalidAddresseException(int err){
    if(err == 1) {
        error = 1;
    } else if(err == 2) {
        error = 2;
    }
}

string InvalidAddresseException::get_err() {
    string message = "";
    if(error == 1) {
        message = "Input was too long!";
    } else if(error == 2) {
        message = "Invalid input!";
    }
    else {
        message = "Error not defined";
    }
    return message;
}
