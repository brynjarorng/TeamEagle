#ifndef TOPPINGSHANDLER_H
#define TOPPINGSHANDLER_H

#include "ToppingsRepo.h"
#include <string.h>
using namespace std;

class ToppingsHandler
{
    public:
        ToppingsHandler();
		//Initializes a private pointer of type Toppings to
		//point to an empty array of Toppings.
		~ToppingsHandler();
		//Destructor
		ToppingsHandler(const ToppingsHandler& copy_object);
		//Copy constructor.
        void create_toppings();
		//Prompts the user to input the name and price of the toppings,
		//and appends to a list saved in the home folder.
        void print_toppings();
		//Prints the list of Toppings in the same order as the current list.
        ToppingsHandler& operator =(const ToppingsHandler& right_side);
		//First delete memory assigned to the private pointer of type Toppings,
		//and then make it equal to copy.
		bool validate(string topping_name);
		//Takes a name of a topping and iterates through the list of toppings
		//from the repo and returns true if it matches a valid topping name.
        Toppings get_topping(string topping_name);
        //Takes a name of a topping and iterates through the list of toppings
        //from the repo and returns the topping of a matching name.
		///NOTE:SOLVE LATER PROBLEM WHEN TOPPING DOES NOT EXIST.
		//TEMPORARY SOLUTION; MAKE INSTANCE OF THE RETURNED TOPPING SOME
		//STATIC VALUE.
    private:
        ToppingsRepo repo;
		//Access to the data layer is through ToppingsRepo.
		Toppings* toppings_list;
		//The list of toppings that recevies information from the ToppingsRepo.
		int toppings_list_count;
		//Size of the above list.
};

#endif // TOPPINGSHANDLER_H
