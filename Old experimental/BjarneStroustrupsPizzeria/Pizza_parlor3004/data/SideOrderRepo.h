#ifndef SIDEORDERREPO_H
#define SIDEORDERREPO_H

#include "SideOrders.h"
#include <vector>
#include <string>
#include <fstream>

using namespace std;


class SideOrderRepo
{
    public:
        SideOrderRepo();
        void overwrite(vector<SideOrders> sideorders);
        void write(SideOrders& pizza);
        vector<SideOrders> read();
        int get_list_count() const;

    private:
        SideOrders sideorder;
        SideOrders* list;
        int list_count;
};

#endif // SIDEORDERREPO_H
