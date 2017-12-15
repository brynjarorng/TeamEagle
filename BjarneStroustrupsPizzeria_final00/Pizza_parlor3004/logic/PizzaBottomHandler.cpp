#include "PizzaBottomHandler.h"

PizzaBottomHandler::PizzaBottomHandler() {
    has_list = false;
    this -> size = 0;
    this -> price = 0;
}

vector<PizzaBottom> PizzaBottomHandler::get_size_list() {
    got_list();
    return pizza_size_vector;
}

PizzaBottom PizzaBottomHandler::get_from_pizza_size_list(int index) {
    got_list();
    return pizza_size_vector.at(index);
}

bool PizzaBottomHandler::size_exists(int size) {
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

bool PizzaBottomHandler::validate_price(int price) {
    if(price > 0) {
        return false;
    }

    return true;
}

void PizzaBottomHandler::validate_price(string price) throw(InvalidPrice){
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

void PizzaBottomHandler::create_pizza_size(PizzaBottom& pizza_size) throw(InvalidSize, InvalidPrice) {
    got_list();

    if(size_exists(pizza_size.get_size())) {
        throw InvalidSize();
    }
    pizza_size_repo.write(pizza_size);
    pizza_size_vector.push_back(pizza_size);
}

PizzaBottom PizzaBottomHandler::get_pizza_size(int pizza_size) throw (InvalidSize) {
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

int PizzaBottomHandler::get_pizza_size_list_size() {
    got_list();
    return (int)pizza_size_vector.size();
}


void PizzaBottomHandler::got_list() {
    if(!has_list) {
        pizza_size_vector = pizza_size_repo.read();
        has_list = true;
    }
}

void PizzaBottomHandler::validate_size(string size) throw (InvalidSize){
    for(unsigned int i = 0; i < size.size(); i++) {
        if(!isdigit(size[i])){
            throw(InvalidSize());
        }
    }
    if(!validate_dupl(stoi(size))) {
        throw(InvalidSize());
    }
}

void PizzaBottomHandler::add_size(string size, string price) {
    validate_size(size);
    validate_double(price);

    bottom.set_size(stoi(size));
    bottom.set_price(stod(price));

    create_pizza_size(bottom);
}

bool PizzaBottomHandler::validate_dupl(int size) {
    for(int i = 0; i < pizza_size_vector.size(); i++) {
        if(size == pizza_size_vector.at(i).get_size()) {
            return false;
        }
    }
    return true;
}

void PizzaBottomHandler::remove_size_from_list(int index) {
    got_list();
    if(index < 0 || index >= pizza_size_vector.size()) {
        throw InvalidSize();
    }

    pizza_size_vector.erase(pizza_size_vector.begin() + index);
    pizza_size_repo.overwrite(pizza_size_vector);
}





