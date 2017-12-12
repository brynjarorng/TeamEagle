#ifndef SIDEORDERS_H
#define SIDEORDERS_H

#include <cstring>
#include <string>
#include<iostream>
using namespace std;


class SideOrders
{
    public:
        SideOrders();
        void add_side_order(string sideorder);
        string get_side_orders();

    private:
        static const int NAME_SIZE = 15;
        char sideorders[NAME_SIZE];
        int sideordercount;
        double price;

};

#endif // SIDEORDERS_H
