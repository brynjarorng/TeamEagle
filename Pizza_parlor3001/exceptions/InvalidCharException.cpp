#include "InvalidCharException.h"

InvalidCharException::InvalidCharException() {

}

string InvalidCharException::get_err() {
    string error = "Invalid input! \nPlease enter only one character";
    return error;
}
