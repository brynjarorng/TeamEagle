#ifndef ORDER_H
#define ORDER_H

#include "PizzaHandler.h"
#include "PizzaType.h"
class Order {

public:

	Order();
	//Initializes order_ready and order_delivered to false,
	//also the pizza count in the order is set to 0.
	Pizza* get_order();
	//Returns an array of pizzas in the order.
	void set_delivered();
	//Marks the order as delivered.
	bool delivered();
	//The return value is TRUE if the pizza is marked delivered
	//FALSE otherwise.
	friend ostream& operator <<(ostream& outs, Order& order);
	//Outstream will be each pizza in order followed by information
	//about pizza status: pizza in oven (T/F) and pizza ready (T/F).
	friend istream& operator >>(istream& ins, Order& order);
	//Instream is one occurrence of pizza wich will be the next element
	//in the private member array containing the pizzas in the order.
	void add_pizza_to_order(PizzaType pizzatype);
	//Add pizza to order, if Pizzatype = menu_pizza the a pizza of type
	//menu_pizza is added to the order, if PizzaType = special_pizza
	//then a pizza of type special pizza is added. If the Pizzatype is
	//neither of these, an error message is printed.
	void set_order_number(int number);
	//Sets the order_number of this instance of order equal to number
	bool ready();
	//Return value is true if all pizzas in orders are ready.
	//False otherwise.
	int get_order_count();
	//Returns the number of pizzas in the order.
private:
	static const int MAX_ORDER_SIZE = 100;

	bool order_ready;
    //True if all pizzas are ready in order.
	bool order_delivered;
    //True if pizza is payed.
	Pizza pizzas_in_order[MAX_ORDER_SIZE];
	int pizzas_in_order_count;//Size of above array.
	int order_number;
    //Number of this instance of order.
	void all_pizzas_ready();
    //Returns true if all pizzas are marked ready.
	void add_pizza(Pizza pizza);
	//If pizzas_in_order_count <= MAX_ORDER_SIZE, pizza is added
	//to order, else an error message is printed to the screen.
};

#endif // ORDER_H
