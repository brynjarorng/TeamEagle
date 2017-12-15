#include "PizzaBottom.h"

PizzaBottom::PizzaBottom() {
//    this -> price = 0.0;
//    this -> size = 0;
}

void PizzaBottom::set_size(int size) {
    this -> size = size;
}

void PizzaBottom::set_price(double price) {
    this -> price = price;
}

double PizzaBottom::get_price() {
    return this -> price;
}

int PizzaBottom::get_size() {
    return this -> size;
}

ostream& operator << (ostream& out, const PizzaBottom& pizza_size) {
    out << pizza_size.size << " " << pizza_size.price << endl;
    return out;
}
