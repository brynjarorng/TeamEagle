#ifndef TOPPINGHANDLER_H
#define TOPPINGHANDLER_H

#include "Toppings.h"
#include "ToppingsRepo.h"
#include <iostream>
using namespace std;

class ToppingsHandler : public ToppingsRepo
{
    public:
        ToppingsHandler();
		//Initializes a private pointer of type Toppings to
		//point to an empty array of Toppings.
		~ToppingsHandler();
        void create_toppings();
		//Prompts the user to input the name and price of the toppings,
		//and appends to a list saved in the home folder.
        void print_toppings();
		//Prints the list of Toppings in the same order as the current list.
        void operator =(Toppings* copy);
		//First delete memory assigned to the private pointer of type Toppings,
		//and then make it equal to copy.
    private:
  		Toppings* toppings_list;
		//The list of toppings that recevies information from the ToppingsRepo.
		int toppings_list_count;
		//Size of the above list.
};

#endif // TOPPINGHANDLER_H
