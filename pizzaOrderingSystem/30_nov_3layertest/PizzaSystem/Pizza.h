#ifndef PIZZA_H
#define PIZZA_H
#include "Toppings.h"
#include <iostream>
#include <string.h>
using namespace std;

class Pizza
{
public:
    Pizza();
    friend istream& operator >> (istream& ins, Pizza& pizza);
    friend ostream& operator <<(ostream& outs, Pizza& pizza);
    void set_name(string name);
    void set_price(double price);
    void add_topping(Toppings topping);
    int get_toppingcount();
    Toppings* get_toppings();

private:
    static const int MAX_TOPPINGS = 10;
    static const int MAX_NAME_SIZE = 50;
    double price;
    char name[MAX_NAME_SIZE];
    Toppings topping[MAX_TOPPINGS];
    int toppingcount;
    enum status = {pending, baking, ready};
};

#endif // PIZZA_H
