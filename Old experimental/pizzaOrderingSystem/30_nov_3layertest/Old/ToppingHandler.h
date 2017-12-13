#ifndef TOPPINGHANDLER_H
#define TOPPINGHANDLER_H

#include "Toppings.h"
#include "fstreamClass.h"
#include <iostream>
using namespace std;

class ToppingHandler
{
    public:
        ToppingHandler();
		~ToppingHandler();
        void create_topping();
        void print_toppings();
        void operator =(Toppings* copy);
		//Copy constructor
    private:
        ToppingsRepo repo;
		Toppings* toppings_list;
		int toppings_list_count;
};

#endif // TOPPINGHANDLER_H
