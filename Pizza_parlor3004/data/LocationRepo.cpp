#include "LocationRepo.h"


LocationRepo::LocationRepo()
{
    //ctor
}

void LocationRepo::write(Location location) {

    ofstream fout("locations.dat", ios::binary|ios::app);
	fout.write((char*)(&location), sizeof(Location));
	fout.close();
}

vector<Location> LocationRepo::read() {

	ifstream fin("locations.dat", ios::binary);
	vector<Location> return_v;

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Location);
		fin.seekg(0, fin.beg);

		vector<Location> temp (record_count);
		fin.read((char*)(&temp[0]), sizeof(Location)*record_count);

		fin.close();
		return_v = temp;
	}
    return return_v;
}

void LocationRepo::overwrite(vector<Location> locations) {

    ofstream fout("locations.dat", ios::binary);
	fout.write((char*)(&locations[0]), sizeof(Location)*locations.size());

	fout.close();
}
