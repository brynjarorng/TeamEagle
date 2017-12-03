#include "OrderHandler.h"

OrderHandler::OrderHandler() {
    orders = new Order[0];
}

OrderHandler::~OrderHandler() {
    delete[] orders;
}

OrderHandler::OrderHandler(const OrderHandler &copy) {
    this->order_count = copy.order_count;
    delete this->orders;
    orders = new Orders[order_count];

    for (int i = 0; i < order_count; i++) {
        orders[i] = copy.orders[i];
    }
}

OrderHandler& OrderHandler::operator = (const &right_side) {
    if(this ->order_count != right_side.order_count) {
        delete[] this ->orders;
        orders = new Order[right_side.order_count]
    }

    this ->order_count = right_side.order_count;

    for(int = 0; i < order_count; i++) {
        order[i] = right_side.[i];
    }

    return *this;
}

void OrderHandler::mark_pizza_status(int index, PizzaStatus status) {
    pizza_list = order.get_order();
    pizza_list[index].set_status(status);
}

void OrderHandler::generate_order_no() {
    Order last = get_last_order();
    int new_order_number = 1 + last.get_order_number();
    order.set_order_number(new_order_number);
}

Order OrderHandler::get_last_order() {
    Order last;
    int order_count = order_repo.get_list_count();
    orders = order_repo.read();
    last = orders[order_count - 1];

    return last;
}

void OrderHandler::add_pizza_to_order(PizzaType pizzatype) {
	if (pizzatype == menu_pizza) {

		string pizza_name;
		cin >> pizza_name;

		bool on_menu = pizzahandler.validate_pizza(pizza_name);
		if (on_menu) {
			pizza = pizzahandler.get_menu_pizza(pizza_name);
			order.add_pizza(pizza);
		}
		else {
			cout << "Pizza not on menu! " << endl;
		}
	}
	else if (pizzatype == special_pizza) {
		temp_pizza = pizzahandler.create_special_pizza();
		order.add_pizza(pizza);
	}
	else {
		cout << "---(SYSTEM)NOT A PIZZATYPE---"  << endl;
	}
}
