#include "OrderRepo.h"
#include <cstdlib>

OrderRepo::OrderRepo() {
	//list = new Order[0];
}
OrderRepo::~OrderRepo() {
	//delete[] list;
}

int OrderRepo::get_current_count(string location)  const{

    int record_count;
    ifstream fin(location + "_orders.dat", ios::binary);
    if (fin.is_open()) {
        fin.seekg(0, fin.end);
		record_count = fin.tellg() / sizeof(Order);
        fin.seekg(0, fin.beg);
		fin.close();
		}
    else {
        record_count = 0;
    }
        return record_count;
}

void OrderRepo::write(Order& order, string location) {

    ofstream fout(location + "_orders.dat", ios::binary|ios::app);
	fout.write((char*)(&order), sizeof(Order));
	fout.close();
}

void OrderRepo::write_archive(vector<Order> orders, string location) {
    ofstream fout(location + "_orders_ARCHIVE.dat", ios::binary|ios::app);
    fout.write((char*)(&orders[0]), sizeof(Order)*orders.size());
	fout.close();
}

vector<Order> OrderRepo::read_archive(string location) {

	ifstream fin(location + "_orders_ARCHIVE.dat", ios::binary);
	vector<Order> return_v;

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Order);
		fin.seekg(0, fin.beg);

		list_count = record_count;
		vector<Order> temp (record_count);
		fin.read((char*)(&temp[0]), sizeof(Order)*record_count);

		fin.close();
		return_v = temp;
	}
    return return_v;
}


vector<Order> OrderRepo::read(string location) {

	ifstream fin(location + "_orders.dat", ios::binary);
	vector<Order> return_v;

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Order);
		fin.seekg(0, fin.beg);

		list_count = record_count;
		vector<Order> temp (record_count);
		fin.read((char*)(&temp[0]), sizeof(Order)*record_count);

		fin.close();
		return_v = temp;
	}

    return return_v;
}

void OrderRepo::overwrite(vector<Order> orders, string location) {
    ofstream fout(location + "_orders.dat", ios::binary);
    fout.write((char*)(&orders[0]), sizeof(Order)*orders.size());
	fout.close();
}
