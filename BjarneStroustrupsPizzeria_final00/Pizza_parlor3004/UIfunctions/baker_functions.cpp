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
        cout << "\e[1;92m" << "#" << i + 1 << "\e[0m\ " << "  ";
        cout << pizzalist[i].get_name() << " -- ";
        print_pizzas_toppings(pizzalist[i]);
        cout << "Status: " << pizzalist[i].get_status() << endl;
    }
}

bool change_status(OrderHandler& orderhandler) {
    string order_number;
    string pizza_number;
    string status;
    try {
        cout << "Order number (0 to quit): ";
        cin >> order_number;
        validate_int(order_number);
        if(stoi(order_number) == 0) {
            return false;
        }
        cout << "Pizza number: ";
        cin >> pizza_number;
        validate_int(pizza_number);
        cout << "Status: (b for in oven, r for ready) ";
        cin >> status;
        try{
            if(status == "b") {
                orderhandler.change_status(stoi(order_number), stoi(pizza_number) - 1, baking);
            }
            else if(status == "r") {
                orderhandler.change_status(stoi(order_number), stoi(pizza_number) - 1, ready);
            }
            else {
                cout << "Not a valid status" << endl;
                pause_screen();
            }
        }
        catch(InvalidSize e) {
            cout << "Pizza not found, try again" << endl;
            pause_screen();
        }
    }
    catch(InvalidNumberException e) {
        cout << "Not a number" << endl;
        pause_screen();
    }

    return true;

}
