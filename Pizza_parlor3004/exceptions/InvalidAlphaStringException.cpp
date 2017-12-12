#include "InvalidAlphaStringException.h"

InvalidAlphaStringException::InvalidAlphaStringException() {

}

string InvalidAlphaStringException::get_err() {
    string error = "Invalid input string!";
    return error;
}
