#include "ToppingsHandler.h"

ToppingsHandler::ToppingsHandler() {
	toppings_list = new Toppings[0];
	toppings_list_count = 0;
}

ToppingsHandler::~ToppingsHandler() {
		delete[] toppings_list;

}
ToppingsHandler::ToppingsHandler(const ToppingsHandler& copy_object) {

    this ->toppings_list_count = copy_object.toppings_list_count;
    this ->toppings_list = new Toppings[toppings_list_count];
    for (int i = 0; i <toppings_list_count; i++) {
        this ->toppings_list[i] = copy_object.toppings_list[i];
    }
}

vector<Toppings> ToppingsHandler::get_topping_list()
{
    return repo.read_vector();
}

bool ToppingsHandler::validate(string topping_name)
{
    string name;

    toppings_list = repo.read();
    toppings_list_count = repo.get_list_count();
    for(int i = 0; i < toppings_list_count; i++) {
        name = toppings_list[i].get_name();
        if(name == topping_name) {
            return true;
        }
    }

    return false;
}


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

void ToppingsHandler::create_topping(Toppings& topping) {
        repo.write(topping);
}

Toppings ToppingsHandler::get_topping(string topping_name)
{
	Toppings remove_later("ERROR! NOT A TOPPING!", 0);

    string name;
    toppings_list = repo.read();
    toppings_list_count = repo.get_list_count();
    for(int i = 0; i < toppings_list_count; i++) {
        name = toppings_list[i].get_name();
        if(name == topping_name) {
            return toppings_list[i];
        }
    }

    return remove_later;
}

ToppingsHandler& ToppingsHandler::operator =(const ToppingsHandler& right_side)
{
	if (this ->toppings_list_count != right_side.toppings_list_count) {
            delete[] this ->toppings_list;
            toppings_list = new Toppings[right_side.toppings_list_count];
	}
	this ->toppings_list_count = right_side.toppings_list_count;

	for (int i = 0; i < toppings_list_count; i++) {
       this ->toppings_list[i] = right_side.toppings_list[i];
	}
	return *this;
}
