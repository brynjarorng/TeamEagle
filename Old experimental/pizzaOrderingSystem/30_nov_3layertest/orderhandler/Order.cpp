#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED

#include "Order.h"

Pizza::Pizza {

	order_ready = false;
	order_delivered = false;
	pizzas_in_order_count = 0;
}

Pizza* Pizza:: get_order() {

	return pizzas_in_order;
}

void Pizza::set_delivered() {

	order_delivered = true;
}

bool Pizza::delivered() {

	return order_delivered;
}

ostream& operator << (ostream& outs, const Order& order) {

	for (int i = 0; i < pizzas_in_order_count; i++) {
		outs << 
	}
istream& operator >>(istream& ins, Order& order) {

	Pizza temp;
	ins >> temp;
	order.pizza_in_order[pizzas_in_order_count] = temp;
	order.pizzas_in_order_count++;
	
	return ins;
}
void Order::all_pizzas_ready() {

	int ready_count = 0;
	for (int i = 0; i < pizzas_in_order_count; i++) {
		if (pizzas_in_order[i].get_status() == ready) {
			ready_count++;
		}
	}
	if (ready_count = pizzas_in_order_count)
	{
		order_ready = true;
	}
}
bool Pizza::ready() {

	all_pizzas_ready();
	return this ->order_ready;
}
void set_order_number(int number) {

	this ->order_number = number
}
#endif
