#ifndef TOPPINGSHANDLER_H
#define TOPPINGSHANDLER_H
#include "ToppingsRepo.h"
#include <string.h>
#include "InvalidName.h"
#include "InvalidPrice.h"
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
		/*bool set_name(string name, Toppings& topping);
		//Checks whether name exists in database, if not
		//then name is set to topping and returns TRUE.
		//Else return false.
		bool set_price(double price, Toppings& topping);
		//Checks whether price is a positive number,
		//if positive then price is set to topping and returns TRUE.
		//Else return false.*/
		bool validate_name(Toppings& topping);
		//Validates new topping that's being added to database.
		//If a topping already has the same name it return false;
        bool validate_price(Toppings& topping);
        //Validates the price of a topping.
        //If price is below zero it will return false.
        void create_topping(Toppings& topping) throw(InvalidName, InvalidPrice);
        //Precondition: topping contains information that was input from the UI.
        //Postcondition: if the validate_name and validate_price functions return TRUE then
        //the topping will be sent to the repository.
        //Else it will throw an exception
        void print_toppings();
		//Prints the list of Toppings in the same order as the current list.
        vector<Toppings> get_topping_list();
		//Returns vector of the list of Toppings in the same order as the current list.
        ToppingsHandler& operator =(const ToppingsHandler& right_side);
		//First delete memory assigned to the private pointer of type Toppings,
		//and then make it equal to copy.
		bool validate(string topping_name);
		//Takes a name of a topping and iterates through the list of toppings
		//from the repo and returns true if it matches a valid topping name.
        Toppings get_topping(string topping_name) throw (InvalidName);
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
