#include "OrderHandler.h"

OrderHandler::OrderHandler() {
    orders = new Order[0];
    order_count = order_repo.get_current_count();
}

OrderHandler::~OrderHandler() {
    delete[] orders;
}

OrderHandler::OrderHandler(const OrderHandler &copy) {
    this->order_count = copy.order_count;
    delete this->orders;
    orders = new Order[order_count];

    for (int i = 0; i < order_count; i++) {
        orders[i] = copy.orders[i];
    }
}

OrderHandler& OrderHandler::operator = (const OrderHandler &right_side) {
    if(this ->order_count != right_side.order_count) {
        delete[] this ->orders;
        orders = new Order[right_side.order_count];
    }
    this ->order_count = right_side.order_count;

    for (int i = 0; i < order_count; i++) {
        orders[i] = right_side.orders[i];
    }

    return *this;
}

void OrderHandler::mark_pizza_status(int index, PizzaStatus status) {
    pizza_list = order.get_order();
    pizza_list[index].set_status(status);
}

void OrderHandler::generate_order_no(Order& order) {
    if(order_repo.get_current_count() != 0) {
        Order last = get_last_order();
        int new_order_number = 1 + last.get_order_number();
        order.set_order_number(new_order_number);
    }
    else {
        order.set_order_number(1);
    }
}

Order OrderHandler::get_last_order() {
    Order last;
    order_count = order_repo.get_current_count();
    orders = order_repo.current_read();
    last = orders[order_count - 1];

    return last;
}

void OrderHandler::print_current_list() {

    orders = order_repo.current_read();

    order_count = order_repo.get_current_count();
    cout << "print_current_list: " << endl;

    for(int i = 0; i < order_count; i++) {
        cout << orders[i];
    }
}
void OrderHandler::add_order(const Order& order) {
    order_repo.current_write(order);
}
bool OrderHandler::max_order_count(Order order) {
    if (order.get_order_count() < order.get_max_orders()) {
        return false;
    }
    return false;
}
bool OrderHandler::delivered(int order_number) {

    bool found;
    this ->orders = order_repo.current_read();

    for (int i =0; i < order_count; i++) {
        if (this ->orders[i].get_order_number() == order_number) {
            this ->orders[i].set_delivered();
            found = true;
        }
        else found = false;
    }
    if (found == true) {
        this ->order_repo.overwrite_list(this ->orders, order_count);
    }
    return found;
}
 Order* OrderHandler::get_orders() {
    this ->orders = order_repo.current_read();
    return this ->orders;
 }
int OrderHandler::get_order_count() const {
    return this ->order_count;
}
