#include "ToppingsHandler.h"

ToppingsHandler::ToppingsHandler() {
    has_list = false;
}

vector<Toppings> ToppingsHandler::get_topping_list()
{
    got_list();
    return toppings;
}

Toppings ToppingsHandler::get_from_topping_list(int index) {
    got_list();
    return toppings.at(index);
}

bool ToppingsHandler::validate(string topping_name)
{
    got_list();
    string name;

    for(unsigned int i = 0; i < toppings.size(); i++) {
        name = toppings.at(i).get_name();
        if(name == topping_name) {
            return true;
        }
    }

    return false;
}

bool ToppingsHandler::validate_name(string name)
{
    got_list();
    string name_from_list;
    for(int i = 0; i < (int)toppings.size(); i++) {
        name_from_list = toppings.at(i).get_name();
        if(name == name_from_list) {
            return true;
        }
    }
    return false;
}

bool ToppingsHandler::validate_price(double price) {
    if(price < 0) {
        return false;
    }
    return true;
}


void ToppingsHandler::create_topping(Toppings& topping) throw(InvalidName, InvalidPrice) {
    got_list();
    if(validate_name(topping.get_name())) {
        throw InvalidName();
    }
    if(!validate_price(topping.get_price())) {
        throw InvalidPrice();
    }
    toppings_repo.write(topping);
    toppings.push_back(topping);
}

void ToppingsHandler::remove_topping_from_list(int index) {
    got_list();
    toppings.erase(toppings.begin() + index);
    toppings_repo.overwrite(toppings);
}

Toppings ToppingsHandler::get_topping(string topping_name) throw (InvalidName)
{
    got_list();
    string name;

    for(unsigned int i = 0; i < toppings.size(); i++) {
        name = toppings.at(i).get_name();
        if(name == topping_name) {
            return toppings.at(i);
        }
    }
    throw InvalidName();
}

int ToppingsHandler::get_topping_list_size() {
    got_list();
    return (int)toppings.size();
}


void ToppingsHandler::got_list() {
    if(!has_list) {
        toppings = toppings_repo.read();
    }
}
