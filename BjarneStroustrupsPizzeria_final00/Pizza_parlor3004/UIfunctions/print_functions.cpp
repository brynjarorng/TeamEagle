#include "print_functions.h"

void pause_screen() {

    cout << endl << "---Enter any character to continue---" << endl;
    cin >> ws;
    string dump;
    getline(cin, dump, '\n');

}

void clear() {

#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
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
void print_pizza(Pizza& pizza) {

    cout << "*" << pizza.get_name() <<endl;
    print_pizzas_toppings(pizza);
    cout << "Price: $" << pizza.get_price() << endl;
    cout << "Size : $" << pizza.get_bottom().get_size() << "\"" << endl;

}

void print_order(Order& order) {

    Print print;

   cout << "\033[1;31m" << "Order #"  << order.get_order_number() << "\033[0m\ " << endl;


    print.print_lines(30);
    Pizza* pizzas_in_order = order.get_pizzas_in_order();
    Pizza temp_pizza;

    int endl_count = order.get_order_count() - 1;

    for (int i = 0; i < order.get_order_count(); i++) {
        print_pizza(pizzas_in_order[i]);
        if (endl_count > 0)
            cout << endl;
        endl_count--;
    }
    print.print_lines(30);
    cout << "Total price: " << order.get_total() << endl;
    print.print_lines(30);
    cout << print.is_paid(order) << endl;
    cout << print.is_ready(order) << endl;
    cout << print.is_sent(order) << endl;
    cout << print.is_comment(order) << endl;

    if (order.get_delivered()) {
        cout << "This order has already been delivered."
             << endl;
    }

    print.print_lines(30);
    cout << endl;

}


void print_current_orders() {

    Print print;
    print.set(1, alph_asc, price,  header, ord);
    print_navigation (print, ord, ' ', true);
}

void print_orders(Order_Status status, OrderHandler& orderhandler) {

    int ordercount = orderhandler.get_order_count();

    Order temp_order;

    int counter = 0;
    for (int i = 0; i < ordercount; i ++) {
        switch (status) {
            case delivered:
                    if (orderhandler.get_orders().at(i).get_delivered()) {
                        print_order(orderhandler.get_orders().at(i));
                        counter++;
                    }
                    break;
            case not_delivered:
                    if (!orderhandler.get_orders().at(i).get_delivered()) {
                        counter++;
                        print_order(orderhandler.get_orders().at(i));
                    }
                break;
            case all:
                print_order(orderhandler.get_orders().at(i));
                counter++;
                break;
        }
    }
    if (counter == 0) {
        cout << "No orders" << endl;
    }
}
void print_topping_list() {

    Print print;
    print.set(14, price, header, top);
    print.prompt_user(true);
    print.pizza_settings(true, false);
    print_navigation(print, top, ' ', true);
    clear();
}


void print_menu_pizza_list() {

    clear();
    Print print;

    print.set(4, alph_asc,price,header, pizz);

    print.pizza_settings(true, false);

    print.prompt_user(true);

    print_navigation(print, pizz, ' ', true);

    clear();
}


void print_sizes(PizzaBottomHandler& bottomhandler) {

    vector<PizzaBottom> size_vector;

    size_vector = bottomhandler.get_size_list();

    clear();

    cout << "---Print all pizza sizes---" << endl;

    cout << "See all sizes:" << endl;
    for(unsigned int i = 0; i < size_vector.size(); i++){
        cout << "$" << size_vector[i].get_price() << ", ";
        cout << size_vector[i].get_size() << "\"" << endl;
    }
    cout << endl;
     //pause_screen();
}

void print_sizes_numbers(PizzaBottomHandler& bottomhandler) {

    vector<PizzaBottom> size_vector;

    size_vector = bottomhandler.get_size_list();

    clear();

    cout << "---Print all pizza sizes---" << endl;

    cout << "See all sizes:" << endl;
    for(unsigned int i = 0; i < size_vector.size(); i++){
        cout << "[" << i + 1 << "]" << " ";
        cout << "$" << size_vector[i ].get_price() << ", ";
        cout << size_vector[i].get_size() << "\"" << endl;
    }
    cout << endl;
}

void print_size_with_numbers(PizzaBottomHandler& bottomhandler) {
    vector<PizzaBottom> size_vector;

    size_vector = bottomhandler.get_size_list();

    for(unsigned int i = 0; i < size_vector.size(); i++) {
        cout << "[" << i + 1 << "]\t";
        cout << "$" << size_vector[i].get_price() << ", ";
        cout << size_vector[i].get_size() << "\"" << endl;
    }
}

void print_menu_pizza_list_with_numbers(PizzaHandler& pizzahandler) {
    vector<Pizza> pizza_vector;

    pizza_vector = pizzahandler.get_pizza_list();

    for(unsigned int i = 0; i < pizza_vector.size(); i++) {
        cout << "[" << i + 1 << "]\t" << pizza_vector[i];
    }
}

void print_toppings_with_number(ToppingsHandler& toppingshandler) {
    vector<Toppings> topping_vector;
    topping_vector = toppingshandler.get_topping_list();

    for(unsigned int i = 0; i < topping_vector.size(); i++) {
        cout << "[" << i + 1 << "]\t" << topping_vector[i];

    }
    cout << endl;
}

void print_pizza_baking_list(OrderHandler& orderhandler) {
    Print print;
    vector<Order> orders = orderhandler.get_orders();
    for (int i = 0; i < orderhandler.get_order_count(); i++) {
        if (!orders.at(i).get_ready()) {
            cout << "\033[1;31m" << "Order #" << orders.at(i).get_order_number() << "\033[0m\ " << endl;
            print_pizzas_in_order_for_baker(orders.at(i));
            print.print_lines(10);
        }
    }
}

void print_pizzas_in_order_for_baker(Order& order) {
    Pizza* pizzalist = order.get_pizzas_in_order();
    for (int i = 0; i < order.get_order_count(); i++) {
        cout << "\e[1;92m" << "#" << i + 1 << "\e[0m\ " << "  ";
        cout << pizzalist[i].get_name() << " -- ";
        print_pizzas_toppings(pizzalist[i]);
        cout << "Status: " << pizzalist[i].get_status() << endl;
    }
}



void print_archived_orders(OrderHandler& orderhandler) {
    clear();
    vector<Order> arc = orderhandler.get_archived_orders();
    for(int i = 0; i < arc.size(); i++) {
        print_order(arc.at(i));
    }
}

void print_locations(LocationHandler& lochandler, bool numbered) {
    vector<Location> locations = lochandler.get_locations();
    for(unsigned int i = 0; i < locations.size(); i++) {
        if(numbered){
            cout << "[" << i + 1 << "]\t";
        }
        cout <<  locations.at(i).get_name() << endl;
    }
}


