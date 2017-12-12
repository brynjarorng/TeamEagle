#include "OrderRepo.h"
#include <cstdlib>

OrderRepo::OrderRepo() {
	//list = new Order[0];
}
OrderRepo::~OrderRepo() {
	//delete[] list;
}
/*void OrderRepo::current_write(Order order) {

	ofstream fout("current_orders.dat", ios::binary|ios::app);
	fout.write((char*)(&order), sizeof(Order));
	fout.close();
}
void OrderRepo::overwrite_list(Order* order, int list_count) {

	ofstream fout("current_orders.dat", ios::binary);
	fout.seekp(ios::beg);
	fout.write((char*)(order), sizeof(Order)*list_count);
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

int OrderRepo::get_archived_count() const {
	return this-> archived_list_count;
}
*/

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
