#ifndef TOPPINGHANDLER_H
#define TOPPINGHANDLER_H

#include "Toppings.h"
#include "fstreamClass.h"
#include <iostream>

class ToppingHandler
{
    public:
        ToppingHandler();
        void create_topping();
        void print_toppings();
    protected:

    private:
        fstreamClass repo;
};

#endif // TOPPINGHANDLER_H
