#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED

#include "Order.h"

Order::Order() {
	this ->order_ready = false;
	this ->order_delivered = false;
	this ->order_paid = false;
	this ->order_sent = false;
	this ->pizzas_in_order_count = 0;
	this ->comment[0] = '\0';
	this ->delivery_addresse[0] = '\0';
	this ->comment_length = 0;
}
Pizza* Order::get_order() {

	return this->pizzas_in_order;
}

void Order::set_delivered() {

	this ->order_delivered = true;
}

bool Order::get_delivered() {

	return this ->order_delivered;
}

int Order::get_order_count() {

	return this ->pizzas_in_order_count;
}

ostream& operator <<(ostream& outs, Order& order) {

    outs << "Order nr #" << order.order_number << endl;

		for (int i = 0; i < order.pizzas_in_order_count; i++) {

			outs << order.pizzas_in_order[i] << endl;
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

	for (int i = 0; i < pizzas_in_order_count; i++) {
		if (this ->pizzas_in_order[i].get_status() != "ready") {
			order_ready = false;
		}
	}
	order_ready == true;
}

bool Order::get_ready() {

	all_pizzas_ready();
	return this ->order_ready;
}


void Order::set_order_number(int number) {

	this ->order_number = number;
}

int Order::get_order_number() {
    return this ->order_number;
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
int Order::get_max_orders() {
    return this ->MAX_ORDER_SIZE;
}
Pizza* Order::get_pizzas_in_order() {
    Pizza* new_list = this ->pizzas_in_order;
    return new_list;
}
double Order::get_total() {
    calulate_total();
    return this ->total_price;
}
void Order::calulate_total()  {

    double order_calc = 0;
    for (int i = 0; i < pizzas_in_order_count; i++ ) {
        order_calc += pizzas_in_order[i].get_price();
    }
    this ->total_price = order_calc;
}

void Order::set_paid() {
    this -> order_paid = true;
}


bool Order::get_paid() {
    if(this -> order_paid) {
        return true;
    }
    return false;
}

bool Order::get_sent() {
    if(this -> order_sent) {
        return true;
    }
    return false;
}

void Order::set_sent() {
    this -> order_sent = true;
}

void Order::set_addresse(string input) {
      for(unsigned int i = 0; i < input.size(); i++) {
        this ->delivery_addresse[i] = input [i];

        if (input.length() < MAX_ADDRESS_LENGTH) {
        delivery_addresse[input.size()] = '\0';
        }
        else {
            delivery_addresse[MAX_ADDRESS_LENGTH - 1] = '\0';
        }

        address_length++;
    }
}

string Order::get_addresse() {
    string temp = this ->delivery_addresse;
    return temp;
}

void Order::set_comment(string input) {

    for(unsigned int i = 0; i < input.size(); i++) {
        this ->comment[i] = input [i];

        if (input.length() < MAX_COMMENT_LENGTH) {
        comment[input.size()] = '\0';
        }
        else {
            comment[MAX_COMMENT_LENGTH - 1] = '\0';
        }

        comment_length++;
    }
}
int Order::get_comment_length() {
    return this ->comment_length;
}

string Order::get_comment() {

    string temp;
    temp = comment;

    return temp;
}

#endif
