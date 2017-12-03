#include "OrderRepo.h"
#include <cstdlib>

OrderRepo::OrderRepo() {
	//list = new Order[0];
}
OrderRepo::~OrderRepo() {
	//delete[] list;
}
void OrderRepo::current_write(Order order) {

	ofstream fout("current_orders.dat", ios::binary|ios::app);
	fout.write((char*)(&order), sizeof(Order));
	fout.close();
}

//Order* OrderRepo::archived_read() {
	//read(archived);
	//return list;
//}
Order* OrderRepo::current_read() {
	read();
	return list;
}
void OrderRepo::read() {

    this ->current_list_count = get_current_count();

	ifstream fin("current_orders.dat", ios::binary);

	if (fin.is_open()) {

		this ->list = new Order[current_list_count];

		fin.read((char*)(this ->list), sizeof(Order)*current_list_count);

		fin.close();
	}
}
int OrderRepo::get_current_count()  const{
		ifstream fin("current_orders.dat");
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Order);
		fin.seekg(0, fin.beg);
		fin.close();

        cout << "get_current_cout: " << record_count << "---------" << endl;
        return record_count;
}

int OrderRepo::get_archived_count() const {
	return this-> archived_list_count;
}
