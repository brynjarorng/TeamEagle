#include "SideOrdersHandler.h"

SideOrdersHandler::SideOrdersHandler() {
    has_list = false;
}

vector<SideOrders> SideOrdersHandler::get_side_order_list() {
    got_list();
    return side_order_vector;
}

int SideOrdersHandler::get_side_order_list_size() {
    got_list();
    return (int)side_order_vector.size();
}

void SideOrdersHandler::got_list() {
    if(!has_list) {
        side_order_vector = side_order_repo.read();
    }
}

void SideOrdersHandler::create_side_order(SideOrders& side_order) throw(InvalidName, InvalidPrice) {
    got_list();
    if(validate_name(side_order.get_side_orders())) {
        throw InvalidName();
    }
    side_order_repo.write(side_order);
    side_order_vector.push_back(side_order);
}

bool SideOrdersHandler::validate_name(string name) {
    got_list();
    string name_from_list;
    for(int i = 0; i < (int)side_order_vector.size(); i++) {
        name_from_list = side_order_vector.at(i).get_side_orders();
        if(name == name_from_list) {
            return true;
        }
    }
    return false;
}

SideOrders SideOrdersHandler::get_from_side_order_list(int index) {
    got_list();
    return side_order_vector.at(index);
}

void SideOrdersHandler::remove_side_order_from_list(int index) {
    got_list();
    side_order_vector.erase(side_order_vector.begin() + index);
    side_order_repo.overwrite(side_order_vector);
}
