#include "SideOrders.h"

SideOrders::SideOrders() {
    this ->sideordercount = 0;
    this ->price = 0;
    sideorders[0] = '\0';
}

void SideOrders::set_name(string name) {
    for(unsigned int i = 0; i < name.length() && i < 14; i++) {
        this->sideorders[i] =  name[i];
        if(i == name.length()) {
            this->sideorders[i + 1] = '\n';
        }
    }

    sideordercount++;
}

void SideOrders::set_price(string price) {
    try{
        validate_double(price);
        double temp = 0;
        temp = stod(price);
        this ->price = temp;
    }
    catch(InvalidDoubleException e) {
        cerr << "Failed to set price: ";
        cerr << e.get_err() << endl;
    }
}

string SideOrders::get_side_orders() {
    string temp = " ";
    for(unsigned int i = 0; i < sizeof(this->sideorders - 1); i++) {
        temp[i] = this->sideorders[i];
    }
    return temp;
}
