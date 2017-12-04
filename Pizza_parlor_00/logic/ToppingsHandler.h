#ifndef TOPPINGSHANDLER_H
#define TOPPINGSHANDLER_H
#include "ToppingsRepo.h"
#include <string.h>
#include <vector>
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
        bool add_topping(Toppings topping);
        //Precondition: topping contains information that was input from the UI.
        //Postcondition: if the topping contains the information in the correct format
        //then the topping is sent to the repository and the return value is TRUE.
        //Else nothing is done and the return value is FALSE.
        vector<Toppings> get_topping_list();
		//Returns vector of the list of Toppings in the same order as the current list.
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
