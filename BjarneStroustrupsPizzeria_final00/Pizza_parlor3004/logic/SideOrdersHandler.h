#ifndef SIDEORDERSHANDLER_H
#define SIDEORDERSHANDLER_H

#include "SideOrderRepo.h"
#include "SideOrders.h"
#include "InvalidName.h"
#include "InvalidPrice.h"
#include "ValidationFunctions.h"

class SideOrdersHandler
{
    public:
        SideOrdersHandler();
        vector<SideOrders> get_side_order_list();
        void got_list();
        int get_side_order_list_size();
        void create_side_order(SideOrders& side_order) throw(InvalidName, InvalidPrice);
        bool validate_name(string name);
        SideOrders get_from_side_order_list(int index);
        void remove_side_order_from_list(int index);
        void make_side_order(string name, string price);

    private:
        SideOrderRepo side_order_repo;
        vector<SideOrders> side_order_vector;
        int side_order_list_count;
        bool has_list;
};

#endif // SIDEORDERSHANDLER_H
