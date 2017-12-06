#ifndef SALESUIFUNCTIONS_H_INCLUDED
#define SALESUIFUNCTIONS_H_INCLUDED

#include <stdlib.h>
#include "OrderHandler.h"
#include "Pizza.h"
#include <iomanip>
enum Order_Status{delivered, all, not_delivered};
bool new_order();
//Precondition: The user is ready to enter a new order.
//Postcondition: The user gets a menu where he can create a new order.
//The return value is true if the function should be called again.
PizzaType menu_or_special();
//Precondition: The user is ready to choose if he wishes to add
//menu pizza or special pizza to order.
//Postcondition: If the user has entered the correct input, then the return
//value is the type of pizza selected. Otherwise the user cans choose to retry
//or exit.
bool toppings_to_special(Pizza& pizza);
//Precondition: the reference instance of Pizza has been created and the use
//is ready to enter toppings from the keyboard.
//Postcondition: The user is prompt to input toppings, and if the toppings
//are on list they are added to this instance of pizza. The user can enter 'q'
//to indicate that he does not wish to enter more toppings.
//Returns true if the the pizza with the toppings added should be added to the order
//false otherwise.
bool yes();
//Input is a character, the function prompts the user to input a selection of (y) or (n)
//if the selectuon is neither, the user is asked again until either answer is recevied.
//if the input is 'y' then the return value is true, else the return value is false.
void add_pizzas(Pizza& pizza, Order& order);
//Prompts the user to select the type of pizza (menu or special) and allows
//the user to repeat the action provided the maximum order count has not been reached.
void add_menu_pizza(Pizza& pizza, Order& order);
//Adds pizza selected by the user on the menu.
//The return value is TRUE if the pizza was added to the menu,
//FALSE otherwise.
void add_special_pizza(Pizza& pizza, Order& order);
//Pizza with selected toppings is added to the order.
void print_pizzas_toppings(Pizza pizza);
//Precondition: Pizza contains toppings to print.
//Postcondition: Toppings of pizza have been printed to the screen.
void print_pizza(Pizza pizza);
//Prints the name of the pizza followed by its topping and lastly the price.
void print_order(Order order);
//Prints the order to the screen.
void mark_delivered();
//Lets the user mark an order delivered.
void print_orders(Order_Status status);
//status should be delivered for printing only delivered pizzas, not_delivered
//for printing all pizzas but those delivered and all for printing all pizzas.
void print_orders(Order_Status status) {

    OrderHandler orderhandler;
    Order* current_orders = orderhandler.get_orders();
    int ordercount = orderhandler.get_order_count();

    Order temp_order;
    for (int i = 0; i < ordercount; i ++) {
       switch (status) {
            case delivered:
                 if (current_orders[i].delivered()) {
                        print_order(current_orders[i]);
                        }
                 break;
            case not_delivered:
                 if (!current_orders[i].delivered()) {
                        print_order(current_orders[i]);
                        }
                break;
            case all:
                print_order(current_orders[i]);
                break;
        }
    }
}
bool new_order() {
    Order order;
    Pizza pizza;
    OrderHandler orderhandler;
    orderhandler.generate_order_no(order);
    cout << "Order #" << order.get_order_number() << endl;

    add_pizzas(pizza, order);
    system("clear");
    print_order(order);
    if (order.get_order_count() > 0) {
        cout << "Is this the correct order? (y/n)";
        if (yes()) {
            orderhandler.add_order(order);
            return false;
        }
        else {
            cout << "Order was not added" << endl;
            cout << "Retry? (y/n)";
            if (yes()) {
                return true;
            }
        }
    }
        cout << "The order is empty, retry?" << endl;
        if (yes()) {
            return true;
    }
}
void add_pizzas(Pizza& pizza, Order& order) {

    OrderHandler orderhandler;
    PizzaType pizzatype;

    pizzatype = menu_or_special();

    bool user_choice;
    do
    {
        if (orderhandler.max_order_count(order)) {
            cout << "Maximum order has been reached!" << endl;
            break;
        }
        if (pizzatype == menu_pizza) {
            add_menu_pizza(pizza, order);

        }
        if (pizzatype == special_pizza) {
            add_special_pizza(pizza, order);
        }
        cout << "Do you wish to add more pizzas to the order?";
        user_choice = yes();
        if (user_choice) {
            pizzatype = menu_or_special();
        }

    }while(user_choice);
}


PizzaType menu_or_special() {
    PizzaType pizzatype;

    cout << "Press m for menu pizza, s for special pizza:";
    char type;
    cin >> type;
    if (type == 'm') {
        pizzatype = menu_pizza;
    }
    else if (type == 's') {
        pizzatype = special_pizza;
    }
    else {
        cout << "Wrong choice, do you want to try again? (y/n)";
        if (yes()) {
            pizzatype = menu_or_special();//Repeat the function.
        }
    }
    return pizzatype;
}
void add_menu_pizza(Pizza& pizza, Order& order) {

    PizzaHandler pizzahandler;

    string pizza_name;
    cout << "Enter name of pizza:";
    cin >> pizza_name;
    bool on_menu = pizzahandler.validate_name(pizza_name);
    if (on_menu) {
        pizza = pizzahandler.get_menu_pizza(pizza_name);
        print_pizza(pizza);
        cout << "Do you want to add this pizza? (y/n)";
        if (yes()) {
            order.add_pizza(pizza);
            pizzahandler.reset_pizza(pizza);
            }
    }
    else {
        cout << "Pizza not on menu! " << endl;
    }
}

bool toppings_to_special(Pizza& pizza) {

    PizzaHandler pizzahandler;

    string topping_name = " ";
    cout << "Enter topping: ";
    cin >> topping_name;

    while (topping_name != "q") {
        bool toppings_exists =
                pizzahandler.add_topping(topping_name, pizza);
        if (!toppings_exists) {
            cout << "Topping not on list!" << endl;
        }

        cout << "Enter next topping:";
        cin >> topping_name;
        if (topping_name == "q") {
            break;
        }

        if (pizzahandler.max_toppings(pizza)) {
            cout << "Maximum topping has been reached, do you want to add this pizza"
                 << "to the order?: ";
            print_pizza(pizza);

            char in;
            cin >> in;
            if (in == 'y') {
                return true;
            }
            else {
                return false;
            }
        }
    }
    pizzahandler.create_special_pizza(pizza);
    print_pizza(pizza);
    cout << "Do you want to add this pizza to the order? (y/n)";
    return (yes());
}
void add_special_pizza(Pizza& pizza, Order& order) {
      PizzaHandler pizzahandler;
    if (toppings_to_special(pizza)) {
        pizzahandler.create_special_pizza(pizza);
        order.add_pizza(pizza);
        }

    pizzahandler.reset_pizza(pizza);
}

bool yes() {
    char input;
    cin >> input;
    if (input == 'y') {
        return true;
    }
    else if (input == 'n') {
        return false;
    }
        cout << "Please select either (y) or (n)" << endl;
        return yes();
}
void print_pizzas_toppings(Pizza pizza) {


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
void print_pizza(Pizza pizza) {
    cout << "*" << pizza.get_name() <<endl;
    print_pizzas_toppings(pizza);
    cout << "Price: " << pizza.get_price() << endl;
}

void print_order(Order order) {
    cout << "Order #" << order.get_order_number() << endl;
    for (int i = 0; i < 10; i++) {
            cout << "-";
    }
    cout << endl;

    Pizza* pizzas_in_order = order.get_pizzas_in_order();
    Pizza temp_pizza;
    for (int i = 0; i < order.get_order_count(); i++) {
        temp_pizza = pizzas_in_order[i];
        print_pizza(temp_pizza);
        cout << endl;
    }
    cout << endl;
}

void print_current_orders(char& refresh) {

    OrderHandler orderhandler;
    Order* current_orders = orderhandler.get_orders();
    int ordercount = orderhandler.get_order_count();

    Order temp_order;
    int counter = 2;

    for (int i = 0; i < ordercount; i ++) {
        if (counter == 0) {
            cout << "Press n to get the next screen or enter number of order\n";
            cin >> refresh;
            if (isdigit(refresh)) {
                break;
            }
        }
        print_order(current_orders[i]);
        counter--;
    // delete [] current_orders;
    }
    cin >> refresh;
}
void mark_delivered() {

    int remove_order_nr;

    cout << "Press (p) to print current orders, or insert the number of order to mark ready:";
    string remove_order;
    cin >> remove_order;
    char first_digit;
    if (remove_order == "p") {
        print_current_orders(first_digit);
    }
    remove_order_nr = atoi(remove_order.c_str());

    OrderHandler orderhandler;
    if (!orderhandler.delivered(remove_order_nr)) {
        cout << "Order nr not on list!" << endl;
    }
}
#endif // SALESUIFUNCTIONS_H_INCLUDED
