#include "PizzaRepo.h"

PizzaRepo::PizzaRepo() {
	//Currently empty.
}
PizzaRepo::~PizzaRepo() {
	//Currently empty.
}
void PizzaRepo::write(Pizza pizza) {

	ofstream fout("pizzas.dat", ios::binary|ios::app);
	fout.write((char*)(&pizza), sizeof(Pizza));
	fout.close();
}
Pizza* PizzaRepo::read() {

	ifstream fin("pizzas.dat", ios::binary);

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Pizza);
		fin.seekg(0, fin.beg);

		list_count = record_count;

		list = new Pizza[record_count];


		fin.read((char*)(list), sizeof(Pizza)*record_count);

		fin.close();
	}

	return list;
}
int PizzaRepo::get_list_count() const {
	return list_count;
}
