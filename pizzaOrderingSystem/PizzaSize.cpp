#include "PizzaSize.h"

PizzaSize::PizzaSize()
{
    this -> price = 0;
    this -> piza_size = 0;
}

PizzaSize::PizzaSize(int pizza_size, int price){
    this -> pizza_size = pizza_size;
    this -> price = price;
}

void PizzaSize::set_size(int price){
    this -> price = price;
}
