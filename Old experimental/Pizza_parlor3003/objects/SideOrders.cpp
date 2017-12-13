#include "SideOrders.h"

SideOrders::SideOrders() {
    this ->sideordercount = 0;
    this ->price = 0;
    sideorders[0] = '\0';
}

void SideOrders::add_side_order(string sideorder) {
    for(unsigned int i = 0; i < sideorder.length() && i < 14; i++) {
        this->sideorders[i] =  sideorder[i];
        if(i == sideorder.length()) {
            this->sideorders[i + 1] = '\n';
        }
    }

    sideordercount++;
}

string SideOrders::get_side_orders() {
    string temp = " ";
    for(unsigned int i = 0; i < sizeof(this->sideorders - 1); i++) {
        temp[i] = this->sideorders[i];
    }
    return temp;
}
