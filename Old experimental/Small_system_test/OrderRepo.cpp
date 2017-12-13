#include "OrderRepo.h"
#include <cstdlib>

OrderRepo::OrderRepo() {
	list = new Order[0];
}
OrderRepo::~OrderRepo() {
	delete[] list;
}
void OrderRepo::current_write(Order order) {

	ofstream fout("current_orders.dat", ios::binary|ios::app);
	fout.write((char*)(&order), sizeof(Order));
	fout.close();
}

Order* OrderRepo::archived_read() {
	read(archived);
	return list;
}
Order* OrderRepo::current_read() {
	read(current);
	return list;
}
void read(ListType list, int& list_count) {
	
	string list_instance("");
		
	if (list == current) {
		list_instance = "current_orders.dat";
		
	}
	else if (list == archived) {
		list_instance = "archived_orders.dat"
	}
	else {
		cout << "---(SYSTEM) ERROR, WRONG LIST INSTANCE IN OrderRepo---" << endl;
		exit(1);
	}
	ifstream fin(list_instance, ios::binary);

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Order);
		fin.seekg(0, fin.beg);

		list_count = record_count;

		this ->list = new Order[record_count];

		fin.read((char*)(this ->list), sizeof(Order)*record_count);

		fin.close();
	}
}
int OrderRepo::get_current_count() const {
	return this->_current_list_count;
}
int OrderRepo::get_archived_count() const {
	return this->_archived_list_count;
}
