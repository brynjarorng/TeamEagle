#include "ToppingsRepo.h"

ToppingsRepo::ToppingsRepo() {
    this ->list = new Toppings[0];
}
ToppingsRepo::~ToppingsRepo() {
    delete [] this ->list;
	//Currently empty.
}
void ToppingsRepo::write(Toppings topping) {

	ofstream fout("toppings.dat", ios::binary|ios::app);
	fout.write((char*)(&topping), sizeof(Toppings));
	fout.close();
}
void ToppingsRepo::overwrite(vector<Toppings> topping) {

    Toppings* temp = new Toppings[topping.size()];
    for (int i = 0; i < topping.size(); i++) {
        temp[i] = topping[i];
    }
	ofstream fout("toppings.dat", ios::binary);
	fout.write((char*)(temp), sizeof(Toppings)*topping.size());
	fout.close();
	delete [] temp;
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
vector<Toppings> ToppingsRepo::test_read_vector() {

	ifstream fin("toppings.dat", ios::binary);

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Toppings);
		fin.seekg(0, fin.beg);

		list_count = record_count;
		Toppings temp_topping;

        for (int i = 0; i < list_count; i++) {
            fin.read((char*)(&temp_topping), sizeof(Toppings));
            topping_list.push_back(temp_topping);
        }

		fin.close();
	}
    return topping_list;
}

