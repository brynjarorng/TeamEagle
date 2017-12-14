#ifndef PizzaBottomHANDLER_H
#define PizzaBottomHANDLER_H

#include "PizzaBottomRepo.h"
#include <string.h>
#include "PizzaBottom.h"
#include "InvalidSize.h"
#include "InvalidPrice.h"
#include "ValidationFunctions.h"

class PizzaBottomHandler
{
    public:
        PizzaBottomHandler();
        vector<PizzaBottom> get_size_list();
        //Returns the vector of PizzaBottom
        PizzaBottom get_from_pizza_size_list(int index);
        //Returns the PizzaBottom with the corresponding index from the vector
        bool size_exists(int size);
        //Validates the size being added to the database
        //If the input size already exists, return false, else true.
        bool validate_price(int price);
        //Check if input price is a valid number
        void validate_price(string price) throw(InvalidPrice);
        //Check if input price is a valid number
        void create_pizza_size(PizzaBottom& pizza_size)  throw(InvalidSize, InvalidPrice);
        PizzaBottom get_pizza_size(int pizza_size) throw (InvalidSize);
        int get_pizza_size_list_size();
        void got_list();
        void validate_size(string size) throw(InvalidSize);
        //Checks if input only contains numbers
        void add_size(string size, string price);
        //Converts size to int and price to double, adds sends that to repo.
        void remove_size_from_list(int index);

    private:
        PizzaBottomRepo pizza_size_repo;
        vector<PizzaBottom> pizza_size_vector;
        int pizza_size_count;
        bool has_list;
        int size;
        double price;
        PizzaBottom bottom;
};

#endif // PizzaBottomHANDLER_H
