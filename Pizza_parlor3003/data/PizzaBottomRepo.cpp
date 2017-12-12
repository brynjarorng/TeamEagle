#include "PizzaBottomRepo.h"

PizzaBottomRepo::PizzaBottomRepo() {
    list_count = 0;
}

int PizzaBottomRepo::get_list_count() const {
	return list_count;
}

vector<PizzaBottom> PizzaBottomRepo::read() {
    	ifstream fin("pizza_sizes.dat", ios::binary);
        vector<PizzaBottom> return_v;

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(PizzaBottom);
		fin.seekg(0, fin.beg);

		list_count = record_count;
		vector<PizzaBottom> temp (record_count);
		fin.read((char*)(&temp[0]), sizeof(PizzaBottom)*record_count);

		fin.close();
		return_v = temp;
	}
    return return_v;
}

void PizzaBottomRepo::write(PizzaBottom& pizza_size) {
    ofstream fout("pizza_sizes.dat", ios::binary|ios::app);
	fout.write((char*)(&pizza_size), sizeof(PizzaBottom));
	fout.close();
}

void PizzaBottomRepo::overwrite(vector<PizzaBottom> pizza_sizes) {
    ofstream fout("pizza_sizes.dat", ios::binary);
    fout.write((char*)(&pizza_sizes[0]), sizeof(PizzaBottom)*pizza_sizes.size());

	fout.close();

}
