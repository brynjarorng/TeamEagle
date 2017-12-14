#include "InvalidNumberException.h"

InvalidNumberException::InvalidNumberException() {

}

string InvalidNumberException::get_err() {
    string error = "Invalid input number!";
    return error;
}
