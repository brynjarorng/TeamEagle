#include "PizzaSize.h"
using namespace std;

PizzaSize::PizzaSize()
{
    this -> price = 0;
    this -> pizza_size = 0;
}

PizzaSize::PizzaSize(int pizza_size, int price){
    this -> pizza_size = pizza_size;
    this -> price = price;
}

void PizzaSize::set_price(int price){
    this -> price = price;
}
