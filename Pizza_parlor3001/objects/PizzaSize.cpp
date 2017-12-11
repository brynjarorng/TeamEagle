#include "PizzaSize.h"

PizzaSize::PizzaSize() {
//    this -> price = 0.0;
//    this -> size = 0;
}

void PizzaSize::set_size(int size) {
    this -> size = size;
}

void PizzaSize::set_price(double price) {
    this -> price = price;
}

double PizzaSize::get_price() {
    return this -> price;
}

int PizzaSize::get_size() {
    return this -> size;
}

ostream& operator << (ostream& out, const PizzaSize& pizza_size) {
    out << pizza_size.size << " " << pizza_size.price << endl;
    return out;
}
