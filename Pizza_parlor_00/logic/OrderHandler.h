#ifndef ORDERHANDLER_H
#define ORDERHANDLER_H
#include "OrderRepo.h"
#include "PizzaHandler"
#include "PizzaStatusEnum.h"

class OrderHandler
{
public:
    OrderHandler();
    void mark_pizza_baking(int index, PizzaStatus status);
    //Takes index of pizza and a status as parameters and marks the pizza
    //with the corresponding index in the order with either
    //baking (in oven) or ready (out of oven).
    void generate_order_no();
    //Reads the order no. of the last order and assigns current
    //order a number that's last order no + 1.
    void print_current_list();
    //Get's list of current orders from repo and prints them out to screen.
    Order get_last_order();
    //Get's the order list from the repo and returns the last order.
    void add_pizza_to_order(PizzaType pizzatype);
	//Add pizza to order, if Pizzatype = menu_pizza the a pizza of type
	//menu_pizza is added to the order, if PizzaType = special_pizza
	//then a pizza of type special pizza is added. If the Pizzatype is
	//neither of these, an error message is printed.
private:
    OrderRepo order_repo;
    Order* orders;
    int orders_count;r
    PizzaHandler pizzahandler;
    Order order;
    Pizza pizza;
    Pizza* pizza_list;

};

#endif // ORDERHANDLER_H
