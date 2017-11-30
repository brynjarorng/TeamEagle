#ifndef PIZZA_H
#define PIZZA_H

#include "Toppings.h"
#include "PizzaSize.h"

using namespace std;


class Pizza
{
    public:
        Pizza();
        Pizza(double price, Toppings toppings, string name);    ///This??? or
        void set_price(int price);   ///These three???
        //set the price of the pizza
        void set_topping(Toppings toppings);
        //set the toppings of the pizza

    private:
        string name;
        int pizza_size;
        double price;
        Toppings toppings;

};

#endif // PIZZA_H
