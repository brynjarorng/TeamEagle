#ifndef ORDERHANDLER_H
#define ORDERHANDLER_H
#include "OrderRepo.h"
#include "PizzaHandler.h"
#include "PizzaStatus.h"


class OrderHandler
{
public:
    OrderHandler();

    OrderHandler& operator = (const OrderHandler& right_side);
    //Ensure that this instance will be a distinct copy of right_side.
    void mark_pizza_status(int index, PizzaStatus status);
    //Takes index of pizza and a status as parameters and marks the pizza
    //with the corresponding index in the order with either
    //baking (in oven) or ready (out of oven).
    void generate_order_no(Order& order);
    //Reads the order no. of the last order and assigns current
    //order a number that's last order no + 1.
    void print_current_list();
    //Get's list of current orders from repo and prints them out to screen.
    Order get_last_order();
    //Get's the order list from the repo and returns the last order.
    void add_order(Order& order);
    //
    bool max_order_count(Order order);
    //Return value is TRUE if the maximum order has been reached
    //False otherwise.
    bool paid(int order_number);
    //The order with the corresponding order_number is marked as delivered
    //in the current order list
    vector<Order> get_orders();
    //Returns the list of orders.
    Order get_from_orders(int index);
    //Returns the order with the corresponding index from the order list.
    int get_order_count();
    //Returns the current order count list.
    void got_list();
    //If handler has yet to fetch list from repo then gets it, if it has list then does nothing
    void set_location(string location);
    void change_status(int ordernumber, int pizzaindex, PizzaStatus status);

private:
    OrderRepo order_repo;
    vector<Order> orders;
    int order_count;
    PizzaHandler pizzahandler;
    Order order;
    Pizza pizza;
    Pizza* pizza_list;
    bool has_list;
    string location;
};

#endif // ORDERHANDLER_H
