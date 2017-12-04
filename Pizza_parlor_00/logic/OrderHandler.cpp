#include "OrderHandler.h"

OrderHandler::OrderHandler() {
    orders = new Order[0];
    order_count = 0;
}

OrderHandler::~OrderHandler() {
    delete[] orders;
}

OrderHandler::OrderHandler(const OrderHandler &copy) {
    this->order_count = copy.order_count;
    delete this->orders;
    orders = new Order[order_count];

    for (int i = 0; i < order_count; i++) {
        orders[i] = copy.orders[i];
    }
}

OrderHandler& OrderHandler::operator = (const OrderHandler &right_side) {
    if(this ->order_count != right_side.order_count) {
        delete[] this ->orders;
        orders = new Order[right_side.order_count];
    }
    this ->order_count = right_side.order_count;

    for (int i = 0; i < order_count; i++) {
        orders[i] = right_side.orders[i];
    }

    return *this;
}

void OrderHandler::mark_pizza_status(int index, PizzaStatus status) {
    pizza_list = order.get_order();
    pizza_list[index].set_status(status);
}

void OrderHandler::generate_order_no()
    if(order_repo.get_current_count != 0) {
        Order last = get_last_order();
        int new_order_number = 1 + last.get_order_number();
        order.set_order_number(new_order_number);
    }
    else {
        order.set_order_number(1);
    }
}

Order OrderHandler::get_last_order() {
    Order last;
    order_count = order_repo.get_current_count();
    orders = order_repo.current_read();
    last = orders[order_count - 1];

    return last;
}

void OrderHandler::print_current_list() {
    orders = order_repo.current_read();

    order_count = order_repo.get_current_count();
    cout << "print_current_list: " << order_count <<"------------------" << endl;

    for(int i = 0; i < order_count; i++) {
        cout << orders[i];
        cout << "*!*!";
    }
}
void OrderHandler::add_pizza_to_order(PizzaType pizzatype) {
	if (pizzatype == menu_pizza) {

        //Temporary cout
        cout << "Enter name of pizza:";
		string pizza_name;
		cin >> pizza_name;

		bool on_menu = pizzahandler.validate_pizza(pizza_name);
		if (on_menu) {
			pizza = pizzahandler.get_menu_pizza(pizza_name);
			order.add_pizza(pizza);
			this ->order_repo.current_write(order);
		}
		else {
			cout << "Pizza not on menu! " << endl;
		}
	}
	else if (pizzatype == special_pizza) {
		pizza = pizzahandler.create_special_pizza();
		order.add_pizza(pizza);
		this ->order_repo.current_write(order);
	}
	else {
		cout << "---(SYSTEM)NOT A PIZZATYPE---"  << endl;
	}
}
