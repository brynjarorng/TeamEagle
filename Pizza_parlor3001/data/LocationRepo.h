#ifndef LOCATIONREPO_H
#define LOCATIONREPO_H
#include "Location.h"
#include <vector>
#include <fstream>

class LocationRepo
{
    public:
        LocationRepo();
        void write(Location location);
        //Appends location to a binary file located in the home directory.
        vector<Location> read();
        //Return value is a vector where each element is an occurrence
        //of a Location currently contained in "locations.dat" in the home folder.
        void overwrite(vector<Location> locations);
        //Rewrites a new file the same size as the vector locations, and replaces
        //the file with the content of the vector.
    private:


};

#endif // LOCATIONREPO_H
