#ifndef PIZZA_H
#define PIZZA_H

#include "Topping.h"

using namespace std;


class Pizza
{
    public:
        Pizza();
        Pizza(int size, double price, Topping topping, string name);    ///This??? or
        set_size(int size);                             ///These three???
        //Set the size of the pizza
        set_price(int price);
        //set the price of the pizza
        set_topping(Topping topping);
        //set the toppings of the pizza

    private:
        string name;
        int pizza_size;
        double price;
        Topping topping;

};

#endif // PIZZA_H
