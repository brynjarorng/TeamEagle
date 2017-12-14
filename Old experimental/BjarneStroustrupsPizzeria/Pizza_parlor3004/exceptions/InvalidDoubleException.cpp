#include "InvalidDoubleException.h"

InvalidDoubleException::InvalidDoubleException() {

}

string InvalidDoubleException::get_err() {
    string error = "Invalid number!";
    return error;
}
