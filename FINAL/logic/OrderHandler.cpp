#include "OrderHandler.h"

OrderHandler::OrderHandler() {
    has_list = false;
    location = "";
}

void OrderHandler::mark_pizza_status(int index, PizzaStatus status) {

    //pizza_list = orders[i].get_order();
   // pizza_list[index].set_status(status);
}

void OrderHandler::generate_order_no(Order& order) {
    got_list();
    if(orders.size() != 0) {
        Order last = get_last_order();
        int new_order_number = 1 + last.get_order_number();
        order.set_order_number(new_order_number);
    }
    else {
        order.set_order_number(1);
    }
}

Order OrderHandler::get_last_order() {
    got_list();
    return orders.at(orders.size() - 1);
}

void OrderHandler::add_order(Order& order) {
    got_list();
    validate_order(order);
    order_repo.write(order, location);
    orders.push_back(order);
}

void OrderHandler::validate_order(Order& order) {
    PizzaHandler pizhandler;
    PizzaBottomHandler bothandler;
    ToppingsHandler tophandler;
    got_list();

    if(valid_order_nr(order.get_order_number())) {
        throw InvalidNumberException();
    }

    Pizza* pizzas = order.get_pizzas_in_order();

    for(int i = 0; i < order.get_order_count(); i++) {

        if(!pizzahandler.validate_price(pizzas[i].get_price())) {
            throw InvalidPrice();
        }
        if(!bothandler.validate_dupl(pizzas[i].get_bottom().get_size())) {
            throw InvalidSize();
        }
        for(int k = 0; k < pizzas[i].get_toppingcount(); k++) {
            Toppings* toppings = pizzas[i].get_toppings();
            if(!tophandler.validate_name(toppings[k].get_name())) {
                throw InvalidTopping();
            }

        }
    }
}



bool OrderHandler::max_order_count(Order order) {
    if (order.get_order_count() < order.get_max_orders()) {
        return true;
    }
    return false;
}

void OrderHandler::paid(int order_number) {
    got_list();

    //if(!isdigit(order_number)) {
       // throw InvalidAlphaNumException();
    //}

    for (unsigned int i = 0; i < orders.size(); i++) {
        if (this ->orders[i].get_order_number() == order_number) {
            this ->orders[i].set_paid();
            order_repo.overwrite(orders, location);
        }
    }
    //throw InvalidNumberException();
}

void OrderHandler::delivered(int order_number) {
    got_list();

    for (unsigned int i = 0; i < orders.size(); i++) {
        if (this ->orders[i].get_order_number() == order_number) {
            this ->orders[i].set_delivered();
            order_repo.overwrite(orders, location);
        }

    }
}

vector<Order> OrderHandler::get_orders() {
    got_list();
    return this ->orders;
}

Order OrderHandler::get_from_orders(int index) {
    got_list();
    return orders.at(index);
}

Order OrderHandler::get_order_by_number(int order_number) {
    got_list();
    for(unsigned int i = 0; i < orders.size(); i++) {
        if(order_number == orders.at(i).get_order_number()) {
            return orders.at(i);
        }
    }
    throw InvalidSize();
}

int OrderHandler::get_order_count() {
    got_list();
    return this ->orders.size();
}

void OrderHandler::got_list() {
    if(!has_list) {
        orders = order_repo.read(location);
        has_list = true;
    }
}

void OrderHandler::set_location(string location) {
    LocationHandler loc_handler;

    if(loc_handler.validate_duplicate(location)) {
        throw InvalidName();
    }

    this ->location = location;


    orders.clear();
    has_list = false;
}
bool OrderHandler::valid_order_nr(int nr) {

    for (unsigned int i = 0; i < orders.size(); i++) {
        if (orders[i].get_order_number() == nr) {
            return true;
        }
    }
    return false;
}

void OrderHandler::change_status(int ordernumber, int pizzaindex, PizzaStatus status) {
    got_list();

    if(ordernumber <= 0 || pizzaindex < 0 || orders.size() == 0){
        throw InvalidSize();
    }

    for(unsigned int i = 0; i < orders.size(); i++) {
        if(orders.at(i).get_order_number() == ordernumber) {
            if(pizzaindex >= orders.at(i).get_order_count()) {
                throw InvalidSize();
            }
            orders.at(i).get_pizzas_in_order()[pizzaindex].set_status(status);
            order_repo.overwrite(orders, location);
        }
    }
}

string OrderHandler::get_location() {
    return this -> location;
}

void OrderHandler::archive_orders() {
    got_list();
    order_repo.write_archive(orders, location);
    orders.clear();
    order_repo.overwrite(orders, location);
}


vector<Order> OrderHandler::get_archived_orders() {
    return order_repo.read_archive(this ->location);
}
