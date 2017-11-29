#include "Pizza.h"

Pizza::Pizza(){
    this -> price = 0;
    this -> size = 0;
    //this -> Topping = " ";  ///?????
    this -> name = " ";
}

Pizza::Pizza(int size, double price, Topping topping, string name){
    this -> price = price;
    this -> size = size;
    this -> Topping = topping;
    this -> name = name;
}

Pizza();
set_size(int size){
    this -> size = size
}
//Set the size of the pizza
set_price(int price){
    this -> price = price;
}
//set the price of the pizza
set_topping(Topping topping){
    this -> topping = topping;
}
//set the toppings of the pizza
