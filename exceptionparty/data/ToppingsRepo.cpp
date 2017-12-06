#include "ToppingsRepo.h"

ToppingsRepo::ToppingsRepo() {
	//Currently empty.
}
ToppingsRepo::~ToppingsRepo() {
	//Currently empty.
}
void ToppingsRepo::write(Toppings topping) {

	ofstream fout("toppings.dat", ios::binary|ios::app);
	fout.write((char*)(&topping), sizeof(Toppings));
	fout.close();
}
Toppings* ToppingsRepo::read() {

	ifstream fin("toppings.dat", ios::binary);

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Toppings);
		fin.seekg(0, fin.beg);

		list_count = record_count;

		list = new Toppings[record_count];


		fin.read((char*)(list), sizeof(Toppings)*record_count);

		fin.close();
	}

	return list;
}
int ToppingsRepo::get_list_count() const {
	return list_count;
}

vector<Toppings> ToppingsRepo::read_vector() {

	ifstream fin("toppings.dat", ios::binary);

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Toppings);
		fin.seekg(0, fin.beg);

		list_count = record_count;

		list = new Toppings[record_count];


		fin.read((char*)(list), sizeof(Toppings)*record_count);

		fin.close();
	}

    for(int i = 0; i < list_count; i++) {
        topping_list.push_back(list[i]);
    }

    delete[] list;
    return topping_list;
}
