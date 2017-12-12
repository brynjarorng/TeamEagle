#include "Location.h"

Location::Location()
{
    name_count = 0;
    name[0] = '\0';
}

void Location::set_name(string name) {
    int size_of_string = name.length();
	if (size_of_string <= MAX_NAME_SIZE) {
		name_count = (size_of_string);
	}
	else {
		name_count = (MAX_NAME_SIZE);
	}

	strncpy(this ->name, name.c_str(), name_count);

	name[name_count] = '\0';
}

string Location::get_name() {
    string temp = name;
    return temp;
}
