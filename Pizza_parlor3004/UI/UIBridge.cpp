#include "UIBridge.h"

UIBridge::UIBridge()
{
    //ctor
}

void UIBridge::choose_location() {
    vector<Location> locations = locationhandler.get_locations();
    bool valid = false;
    string loc = "";

    while(!valid) {
        clear();
        unsigned int i = 0;
        for(;i < locations.size(); i++) {
            cout << "[" << i + 1  << "]\t" << locations.at(i).get_name() << endl;
        }
        string inp;
        cout << endl << "Choose a location from the list by typing ";
        cin >> inp;
        validate_int(inp);
        if(stoi(inp) > 0 && stoi(inp) <= locations.size()) {
            loc = locations.at(stoi(inp) - 1).get_name();
            valid = true;
        }
        else {
            cout << "Input does not correspond a location" << endl;
        }
    }
    orderhandler.set_location(loc);
}
