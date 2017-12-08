#include "OrderHandler.h"

OrderHandler::OrderHandler() {
    orders = order_repo.read();
}

OrderHandler::~OrderHandler() {
}

void OrderHandler::mark_pizza_status(int index, PizzaStatus status) {
    orders;

    //pizza_list = orders[i].get_order();
   // pizza_list[index].set_status(status);
}

void OrderHandler::generate_order_no(Order& order) {
    if(orders.size() != 0) {
        Order last = get_last_order();
        int new_order_number = 1 + last.get_order_number();
        order.set_order_number(new_order_number);
    }
    else {
        order.set_order_number(1);
    }
}

Order OrderHandler::get_last_order() {

    return orders.at(orders.size() - 1);
}
/*
void OrderHandler::print_current_list() {

    orders = order_repo.current_read();

    order_count = order_repo.get_current_count();
    cout << "print_current_list: " << endl;

    for(int i = 0; i < order_count; i++) {
        cout << orders[i];
    }
}*/
void OrderHandler::add_order(Order& order) {
    order_repo.write(order);
    orders.push_back(order);
}
bool OrderHandler::max_order_count(Order order) {
    if (order.get_order_count() < order.get_max_orders()) {
        return true;
    }
    return false;
}
bool OrderHandler::delivered(int order_number) {

    bool found;

    for (int i =0; i < orders.size(); i++) {
        if (this ->orders[i].get_order_number() == order_number) {
            this ->orders[i].set_delivered();
            found = true;
        }
        else found = false;
    }
    if (found == true) {
        this ->order_repo.overwrite(orders);
    }
    return found;
}
vector<Order> OrderHandler::get_orders() {
    return this ->orders;
 }

Order OrderHandler::get_from_orders(int index) {
    return orders.at(index);
}
int OrderHandler::get_order_count() const {
    return this ->orders.size();
}
