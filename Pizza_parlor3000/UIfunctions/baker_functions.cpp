#include "baker_functions.h"

void pprint_lines (int line_count) {
    for (int i = 0; i <line_count; i++) {
        cout << "-";
    }
    cout << endl;
}

void print_pizza_list() {
    OrderHandler orderhandler;

    for (int i = 0; i < orderhandler.get_order_count(); i++) {
        if (orderhandler.get_from_orders(i).delivered()) {
            cout << "Order #" << orderhandler.get_from_orders(i).get_order_number() << endl;
            print_pizzas_in_order(orderhandler.get_from_orders(i));
            pprint_lines(10);
        }
    }
}

void print_pizzas_toppings(Pizza& pizza) {
    Toppings* top = pizza.get_toppings();
    int toppingcount = pizza.get_toppingcount();
    int comma_count = toppingcount - 1;
    for (int i = 0; i < toppingcount; i++) {
        cout << top[i].get_name();
        if (comma_count > 0) {
            cout << ", ";
        }
        comma_count--;
    }
    cout << "."  << endl;
}
void print_pizzas_in_order(Order& order) {
    Pizza* pizzalist = order.get_pizzas_in_order();
    for (int i = 0; i < order.get_order_count(); i++) {
        cout << "#" << i + 1 << "  ";
        cout << pizzalist[i].get_name() << " -- ";
        print_pizzas_toppings(pizzalist[i]);
    }
}

void change_status() {
    string order_number;
    string pizza_number;
    char status;
    OrderHandler handler;
    //Order* orders = handler.get_orders();
    cout << "Order number: ";
    cin >> order_number;
    cout << "Pizza number: ";
    cin >> pizza_number;
    cout << "Status: (b for in oven, r for ready) ";
    cin >> status;


}
