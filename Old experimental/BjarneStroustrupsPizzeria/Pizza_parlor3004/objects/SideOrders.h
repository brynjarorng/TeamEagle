#ifndef SIDEORDERS_H
#define SIDEORDERS_H

#include <cstring>
#include <string>
#include <iostream>
#include "ValidationFunctions.h"


using namespace std;


class SideOrders
{
    public:
        SideOrders();
        void set_name(string name);
        string get_side_orders();
        void set_price(string price);

    private:
        static const int NAME_SIZE = 15;
        char sideorders[NAME_SIZE];
        int sideordercount;
        double price;

};

#endif // SIDEORDERS_H
