#include "ToppingsHandler.h"

ToppingsHandler::ToppingsHandler() {
    has_list = false;
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
void ToppingsHandler::create_topping(Toppings& topping) throw(InvalidNameException, InvalidPrice) {
    got_list();
    if(validate_name(topping.get_name())) {
        throw InvalidNameException();
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

Toppings ToppingsHandler::get_topping(string topping_name) throw (InvalidNameException)
{
    got_list();
    string name;

    for(unsigned int i = 0; i < toppings.size(); i++) {
        name = toppings.at(i).get_name();
        if(name == topping_name) {
            return toppings.at(i);
        }
    }
    throw InvalidNameException();
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
