#include "ToppingsRepo.h"

ToppingsRepo::ToppingsRepo() {
	//Currently empty.
}
ToppingsRepo::~ToppingsRepo() {
	//Currently empty.
}/*
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
}*/
int ToppingsRepo::get_list_count() const {
	return list_count;
}

void ToppingsRepo::write(Toppings& toppings) {

    ofstream fout("toppings.dat", ios::binary|ios::app);
	fout.write((char*)(&toppings), sizeof(Toppings));
	fout.close();
}

vector<Toppings> ToppingsRepo::read() {

	ifstream fin("toppings.dat", ios::binary);
	vector<Toppings> return_v;

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

