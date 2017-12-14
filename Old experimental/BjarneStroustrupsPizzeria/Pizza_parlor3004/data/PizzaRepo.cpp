#include "PizzaRepo.h"

PizzaRepo::PizzaRepo() {
	list_count = 0;
}
PizzaRepo::~PizzaRepo() {
	//Currently empty.
}/*
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
}*/
int PizzaRepo::get_list_count() const {
	return list_count;
}

void PizzaRepo::write(Pizza& pizza) {

    ofstream fout("pizzas.dat", ios::binary|ios::app);
	fout.write((char*)(&pizza), sizeof(Pizza));
	fout.close();
}

vector<Pizza> PizzaRepo::read() {

	ifstream fin("pizzas.dat", ios::binary);
	vector<Pizza> return_v;

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Pizza);
		fin.seekg(0, fin.beg);

		list_count = record_count;
		vector<Pizza> temp (record_count);
		fin.read((char*)(&temp[0]), sizeof(Pizza)*record_count);

		fin.close();
		return_v = temp;
	}
    return return_v;
}

void PizzaRepo::overwrite(vector<Pizza> pizzas) {

    ofstream fout("pizzas.dat", ios::binary);
    fout.write((char*)(&pizzas[0]), sizeof(Pizza)*pizzas.size());

	fout.close();
}
