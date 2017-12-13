#ifndef PIZZA_H
#define PIZZA_H
#include "Toppings.h"
#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
const int MAX_NAME_SIZE = 50;

class Pizza
{
    public:
        Pizza();
        Pizza(int size, double price, string name);    ///This??? or
        void set_size();
        //Set the size of the pizza
        void set_price();
        //set the price of the pizza
        void set_topping();
        //set the toppings of the pizza
		friend istream& operator >> (istream& ins, Pizza& pizza);
		//
		void print_dummy_list();
		//A temporary function that prints a dummy list of toppings choices.
		void make_pizza();
		//
		friend ostream& operator <<(ostream& outs, Pizza& pizza);
    private:
        string name;
        int pizza_size;
        double price;
        vector<Toppings> toppings;
		char cname[MAX_NAME_SIZE];
		
		vector<Toppings> dummy_list;
		int dummy_index;
};

#endif // PIZZA_H
