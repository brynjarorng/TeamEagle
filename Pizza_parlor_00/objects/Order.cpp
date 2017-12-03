#include "Order.h"

Order::Order() {
	this ->order_ready = false;
	this ->order_delivered = false;
	this ->pizzas_in_order_count = 0;
}
Pizza* Order::get_order() {

	return this->pizzas_in_order;
}
void Order::set_delivered() {

	this ->order_delivered = true;
}

bool Order::delivered() {

	return this ->order_delivered;
}
int Order::get_order_count() {

	return this ->pizzas_in_order_count;
}

ostream& operator <<(ostream& outs, Order& order) {

	for (int i = 0; i < order.pizzas_in_order_count; i++) {

		outs << "Order nr #" << order.order_number << endl;

		for (int i = 0; i < order.pizzas_in_order_count; i++) {

			outs << order.pizzas_in_order[i] << endl;
		}
	}
	return outs;
}

istream& operator >>(istream& ins, Order& order) {

	Pizza temp;
	ins >> temp;
	int index = order.pizzas_in_order_count;
	order.pizzas_in_order[index] = temp;
	order.pizzas_in_order_count++;

	return ins;
}
void Order::all_pizzas_ready() {

	bool temp = true; //Temporary until pizzahandler is ready.
	int ready_count = 0;
	for (int i = 0; i < pizzas_in_order_count; i++) {
		if (temp) {
			//Remember ->pizzas_in_order[i].get_status() == read
			ready_count++;
		}
	}
	if (ready_count == pizzas_in_order_count) {

		this ->order_ready = true;
	}
}
bool Order::ready() {

	all_pizzas_ready();
	return this ->order_ready;
}
void Order::set_order_number(int number) {

	this ->order_number = number;
}
void Order::add_pizza(Pizza pizza) {
	if(pizzas_in_order_count <= MAX_ORDER_SIZE) {

		this ->pizzas_in_order[this ->pizzas_in_order_count] = pizza;
		this ->pizzas_in_order_count++;
	}

	else {
		cout << "Order has reached maximum size!" << endl;
	}
}
void Order::add_pizza_to_order(PizzaType pizzatype) {

	PizzaHandler pizzahandler;
	Pizza temp_pizza;

	if (pizzatype == menu_pizza) {

		string pizza_name;
		cin >> pizza_name;

		bool on_menu = pizzahandler.validate_pizza(pizza_name);
		if (on_menu) {
			temp_pizza = pizzahandler.get_menu_pizza(pizza_name);
			add_pizza(temp_pizza);
		}
		else {
			cout << "Pizza not on menu! " << endl;
		}
	}
	else if (pizzatype == special_pizza) {
		temp_pizza = pizzahandler.create_special_pizza();
		add_pizza(temp_pizza);
	}
	else {
		cout << "---(SYSTEM)NOT A PIZZATYPE---"  << endl;
	}
}

