#include "ToppingsHandler.h"

ToppingsHandler::ToppingsHandler() {
    toppings = toppings_repo.read();
}
/*
void ToppingsHandler::print_toppings()
{
	toppings_list = repo.read();
	//Retreive current toppings list from repository.
	toppings_list_count = repo.get_list_count();
	for (int i = 0; i < toppings_list_count; i++) {
		cout << toppings_list[i] << endl;
	}
}
*/
vector<Toppings> ToppingsHandler::get_topping_list()
{
    return toppings;
}

Toppings ToppingsHandler::get_from_topping_list(int index) {
    return toppings.at(index);
}

bool ToppingsHandler::validate(string topping_name)
{
    string name;

    for(int i = 0; i < toppings.size(); i++) {
        name = toppings.at(i).get_name();
        if(name == topping_name) {
            return true;
        }
    }

    return false;
}

bool ToppingsHandler::validate_name(string name)
{
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

/*
bool ToppingsHandler::set_name(string name, Toppings& topping) {
    if(!validate(name)) {
        topping.set_name(name);
        return true;
    }

    return false;
}
bool ToppingsHandler::set_price(double price, Toppings& topping) {
    if(price >= 0) {
        topping.set_price(price);
        return true;
    }
    else {
        return false;
    }
}
*/
void ToppingsHandler::create_topping(Toppings& topping) throw(InvalidName, InvalidPrice) {
    if(!validate_name(topping.get_name())) {
        throw InvalidName();
    }
    if(!validate_price(topping.get_price())) {
        throw InvalidPrice();
    }
    toppings_repo.write(topping);
    toppings.push_back(topping);
}

Toppings ToppingsHandler::get_topping(string topping_name) throw (InvalidName)
{
    string name;

    for(int i = 0; i < toppings.size(); i++) {
        name = toppings.at(i).get_name();
        if(name == topping_name) {
            return toppings.at(i);
        }
    }
    throw InvalidName();
}

int ToppingsHandler::get_topping_list_size() {
    return (int)toppings.size();
}
