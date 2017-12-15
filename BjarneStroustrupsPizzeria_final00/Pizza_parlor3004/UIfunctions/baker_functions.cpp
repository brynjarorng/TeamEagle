#include "baker_functions.h"

void pprint_lines (int line_count) {
    for (int i = 0; i <line_count; i++) {
        cout << "-";
    }
    cout << endl;
}

void print_pizza_baking_list(OrderHandler& orderhandler) {
    vector<Order> orders = orderhandler.get_orders();
    for (int i = 0; i < orderhandler.get_order_count(); i++) {
        if (!orders.at(i).get_ready()) {
            cout << "\033[1;31m" << "Order #" << orders.at(i).get_order_number() << "\033[0m\ " << endl;
            print_pizzas_in_order(orders.at(i));
            pprint_lines(10);
        }
    }
}

void print_pizzas_in_order(Order& order) {
    Pizza* pizzalist = order.get_pizzas_in_order();
    for (int i = 0; i < order.get_order_count(); i++) {
        cout << "\e[1;92m" << "#" << i + 1 << "\e[0m\ " << "  ";
        cout << pizzalist[i].get_name() << " -- ";
        print_pizzas_toppings(pizzalist[i]);
        cout << "Status: " << pizzalist[i].get_status() << endl;
    }
}

