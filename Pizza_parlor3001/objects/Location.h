#ifndef LOCATION_H
#define LOCATION_H
#include <string.h>
#include <string>
using namespace std;

class Location
{
    public:
        Location();
        void set_name(string location);
        //set the name of the location.
        string get_name();
        //return the name of the location.
    private:
        static const int MAX_NAME_SIZE = 50;
        char name[MAX_NAME_SIZE];
        int name_count;
};

#endif // LOCATION_H
