#ifndef LOCATIONHANDLER_H
#define LOCATIONHANDLER_H
#include "LocationRepo.h"
#include "InvalidName.h"
#include "InvalidAlphaNumException.h"
#include "InvalidSize.h"


class LocationHandler
{
    public:
        LocationHandler();
        void add_location(Location location);
        // Calls the validation functions to see if location is a valid addtion
        // If not then an exception will be thrown.
        // If valid, then it will be sent to the repo.
        vector<Location> get_locations();
        //Returns vector of the list of locations in the same order as the current list.
        bool validate_location_name(string location);
        //Validates the input, the name cannot start with a space nor include any symbols other then alpha or num.
        bool validate_duplicate(string location);
        //Validates new location that's being added to database.
        //If a location already has the same name it return false;
        void got_list();
        //If handler has yet to fetch list from repo then gets it, if it has list then does nothing
        void remove_location(int index);
        //Removes location with the corresponding index.
    protected:

    private:
        LocationRepo loc_repo;
        vector<Location> locations;
        bool has_list;

};

#endif // LOCATIONHANDLER_H
