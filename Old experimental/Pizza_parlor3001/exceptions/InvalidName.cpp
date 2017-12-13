#include "InvalidName.h"

InvalidName::InvalidName() {

}

string InvalidName::get_err() {
    string error = "This name already exists!";
    return error;
}
