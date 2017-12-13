#include "Pizza.h"
#include "Toppings.h"

inline Pizza::Pizza(){
    this -> price = 0;
    //this -> Topping = " ";  ///?????
    this -> name = " ";
}

inline Pizza::Pizza(double price, Toppings toppings, string name){
    this -> price = price;
    this -> toppings = toppings;
    this -> name = name;
}

//Set the size of the pizza
void Pizza::set_price(int price){
    this -> price = price;
}
//set the price of the pizza
void Pizza::set_topping(Toppings toppings){
    this -> toppings = toppings;
}
//set the toppings of the pizza
