#include "PizzaSizeRepo.h"

PizzaSizeRepo::PizzaSizeRepo() {
    list_count = 0;
}

int PizzaSizeRepo::get_list_count() const {
	return list_count;
}

vector<PizzaSize> PizzaSizeRepo::read() {
    	ifstream fin("pizza_sizes.dat", ios::binary);
        vector<PizzaSize> return_v;

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(PizzaSize);
		fin.seekg(0, fin.beg);

		list_count = record_count;
		vector<PizzaSize> temp (record_count);
		fin.read((char*)(&temp[0]), sizeof(PizzaSize)*record_count);

		fin.close();
		return_v = temp;
	}
    return return_v;
}

void PizzaSizeRepo::write(PizzaSize& pizza_size) {
    ofstream fout("pizza_sizes.dat", ios::binary|ios::app);
	fout.write((char*)(&pizza_size), sizeof(PizzaSize));
	fout.close();
}

void PizzaSizeRepo::overwrite(vector<PizzaSize> pizza_sizes) {
    ofstream fout("pizza_sizes.dat", ios::binary);
    fout.write((char*)(&pizza_sizes[0]), sizeof(PizzaSize)*pizza_sizes.size());

	fout.close();

}
