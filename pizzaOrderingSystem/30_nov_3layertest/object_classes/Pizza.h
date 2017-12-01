#ifndef PIZZA_H
#define PIZZA_H
#include "Toppings.h"
#include <iostream>
using namespace std;

class Pizza
{
public:
    Pizza();
    friend istream& operator >> (istream& ins, Pizza& pizza);
    friend ostream& operator <<(ostream& outs, Pizza& pizza);

private:
    static const int MAX_TOPPINGS = 10;
    static const int MAX_NAME_SIZE = 50;
    int pizza_size;
    double price;
    char name[MAX_NAME_SIZE];
    Toppings topping[MAX_TOPPINGS];
    int toppingcount;
};

#endif // PIZZA_H
