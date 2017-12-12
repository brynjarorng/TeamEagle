#ifndef PizzaBottom_H
#define PizzaBottom_H

#include "string.h"
#include <iostream>

using namespace std;

class PizzaBottom
{
    public:
        PizzaBottom();
        //initialize the size to 0 and price to 0.0
        void set_size(int size);
        //set the size of the pizza
        void set_price(double price);
        //set the price of the pizza
        double get_price();
        //returns the price of the pizza size
        int get_size();
        //Returns the size of the bottom
        friend ostream& operator << (ostream& out, const PizzaBottom& pizza_size);

    private:
        int size;
        double price;
};

#endif // PizzaBottom_H
