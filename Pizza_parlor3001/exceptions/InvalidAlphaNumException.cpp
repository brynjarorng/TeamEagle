#include "InvalidAlphaNumException.h"

InvalidAlphaNumException::InvalidAlphaNumException()
{
    //ctor
}

string InvalidAlphaNumException::get_err() {
    string error = "Input is not an integer/string";
    return error;
}
