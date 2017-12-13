#include "Location.h"

Location::Location()
{
    name_count = 0;
    name[0] = '\0';
}

void Location::set_name(string in) {
	unsigned int i = 0;
	while( i < MAX_NAME_SIZE && i < in.length())
	{
		this ->name[i] = in[i];
		i++;
	}

	this -> name[i] = '\0';
}

string Location::get_name() {
    string temp = name;
    return temp;
}
