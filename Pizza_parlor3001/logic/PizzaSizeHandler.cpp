#include "PizzaSizeHandler.h"

PizzaSizeHandler::PizzaSizeHandler() {
    has_list = false;
    this -> size = 0;
    this -> price = 0;
}

vector<PizzaSize> PizzaSizeHandler::get_size_list() {
    got_list();
    return pizza_size_vector;
}

PizzaSize PizzaSizeHandler::get_from_pizza_size_list(int index) {
    got_list();
    return pizza_size_vector.at(index);
}

bool PizzaSizeHandler::size_exists(int size) {
    got_list();
    int size_from_list;

    for(unsigned int i = 0; i < pizza_size_vector.size(); i++) {
        size_from_list = pizza_size_vector.at(i).get_size();
        if(size == size_from_list) {
            return true;
        }
    }
    return false;
}

bool PizzaSizeHandler::validate_price(int price) {
    if(price > 0) {
        return false;
    }

    return true;
}

void PizzaSizeHandler::validate_price(string price) throw(InvalidPrice){
    if(!isdigit(price[0])){
        throw(InvalidPrice());
    }

    for(unsigned int i = 1; i < price.size(); i++){
        if(!isdigit(price[i])){
            if(price[i] != 46){
            //ASCII value for '.'
                throw(InvalidPrice());
            }
        }
    }
}

void PizzaSizeHandler::create_pizza_size(PizzaSize& pizza_size) throw(InvalidSize, InvalidPrice) {
    got_list();

    if(size_exists(pizza_size.get_size())) {
        throw InvalidSize();
    }
    pizza_size_repo.write(pizza_size);
    pizza_size_vector.push_back(pizza_size);
}

PizzaSize PizzaSizeHandler::get_pizza_size(int pizza_size) throw (InvalidSize) {
    got_list();
    int size;

    for(unsigned int i = 0; i < pizza_size_vector.size(); i++) {
        size = pizza_size_vector.at(i).get_size();
        if(size == pizza_size) {
            return pizza_size_vector.at(i);
        }
    }
    throw InvalidSize();
}

int PizzaSizeHandler::get_pizza_size_list_size() {
    got_list();
    return (int)pizza_size_vector.size();
}


void PizzaSizeHandler::got_list() {
    if(!has_list) {
        pizza_size_vector = pizza_size_repo.read();
    }
}

void PizzaSizeHandler::validate_size(string size) throw (InvalidSize){
    for(unsigned int i = 0; i < size.size(); i++) {
        if(!isdigit(size[i])){
            throw(InvalidSize());
        }
    }
}

void PizzaSizeHandler::add_size(string size, string price) {
    p_size.set_size(stoi(size));
    p_size.set_price(stod(price));

    create_pizza_size(p_size);
}

void PizzaSizeHandler::remove_size_from_list(int index) {
    got_list();
    pizza_size_vector.erase(pizza_size_vector.begin() + index);
    pizza_size_repo.overwrite(pizza_size_vector);
}





