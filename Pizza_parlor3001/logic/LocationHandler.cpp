#include "LocationHandler.h"

LocationHandler::LocationHandler()
{
    //ctor
}

LocationHandler::~LocationHandler()
{
    //dtor
}

void LocationHandler::add_location(string location) {
    if(!validate_location_name(location)) {
        throw InvalidAlphaNumException();
    }
    if(!validate_location_name_length(location)) {
        throw InvalidSize();
    }
    if(!validate_duplicate(location)) {
        throw InvalidNameException();
    }

    locrepo.write();
}

vector<string> LocationHandler::get_locations() {
    return locrepo.read();
}

bool LocationHandler::validate_location_name(string location) {

}

bool LocationHandler::validate_location_name_length(string location) {
    if(location_name_length < location) {
        return false;
    }

    return true;
}

bool LocationHandler::validate_duplicate(string location) {
    vector<string> locations = locrepo.read();

    for(int i = 0; i < locations.size(); i++) {
        if(locations == location) {
            return false;
        }
    }

    return true;
}
