#include "LocationRepo.h"

LocationRepo::LocationRepo()
{
    //ctor
}

LocationRepo::~LocationRepo()
{
    //dtor
}
/*

void LocationRepo::write() {

    ofstream fout("locations.dat", ios::binary|ios::app);
	fout.write((char*)(&name), sizeof(char)*);
	fout.close();
}

vector<string> LocationRepo::read() {

	ifstream fin("location.dat", ios::binary);
	vector<To> return_v;

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Toppings);
		fin.seekg(0, fin.beg);

		list_count = record_count;
		vector<Toppings> temp (record_count);
		fin.read((char*)(&temp[0]), sizeof(Toppings)*record_count);

		fin.close();
		return_v = temp;
	}
    return return_v;
}

void ToppingsRepo::overwrite(vector<Toppings> toppings) {

    ofstream fout("toppings.dat", ios::binary);
    unsigned int file_size = toppings.size();
	//fout.write((char*)(&file_size), sizeof(unsigned));
	fout.write((char*)(&toppings[0]), sizeof(Toppings)*toppings.size());

	fout.close();
}

*/
