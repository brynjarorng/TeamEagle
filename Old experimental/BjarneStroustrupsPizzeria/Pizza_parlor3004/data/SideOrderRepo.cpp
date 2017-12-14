#include "SideOrderRepo.h"

SideOrderRepo::SideOrderRepo()
{
    //ctor
}

void SideOrderRepo::write(SideOrders& sideorder) {

    ofstream fout("side_orders.dat", ios::binary|ios::app);
	fout.write((char*)(&sideorder), sizeof(SideOrders));
	fout.close();
}

vector<SideOrders> SideOrderRepo::read() {

	ifstream fin("side_orders.dat", ios::binary);
	vector<SideOrders> return_v;

	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(SideOrders);
		fin.seekg(0, fin.beg);

		list_count = record_count;
		vector<SideOrders> temp (record_count);
		fin.read((char*)(&temp[0]), sizeof(SideOrders)*record_count);

		fin.close();
		return_v = temp;
	}
    return return_v;
}

void SideOrderRepo::overwrite(vector<SideOrders> sideorders) {

    ofstream fout("side_orders.dat", ios::binary);
    fout.write((char*)(&sideorders[0]), sizeof(SideOrders)*sideorders.size());

	fout.close();
}

int SideOrderRepo::get_list_count() const {
	return list_count;
}
