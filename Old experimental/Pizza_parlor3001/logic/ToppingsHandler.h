#ifndef TOPPINGSHANDLER_H
#define TOPPINGSHANDLER_H
#include "ToppingsRepo.h"
#include <string.h>
#include "InvalidNameException.h"
#include "InvalidPrice.h"
using namespace std;

class ToppingsHandler
{
public:
    ToppingsHandler();
    bool validate_name(string name);
    //Validates new topping that's being added to database.
    //If a topping already has the same name it return false;
    bool validate_price(double price);
    //Validates the price of a topping.
    //If price is below zero it will return false.
    void create_topping(Toppings& topping) throw(InvalidNameException, InvalidPrice);
    //Precondition: topping contains information that was input from the UI.
    //Postcondition: if the validate_name and validate_price functions return TRUE then
    //the topping will be sent to the repository.
    //Else it will throw an exception
    void print_toppings();
    //Prints the list of Toppings in the same order as the current list.
    vector<Toppings> get_topping_list();
    //Returns vector of the list of Toppings in the same order as the current list.
    Toppings get_from_topping_list(int index);
    //Returns the topping with the corresponding index from the toppings list.
    ToppingsHandler& operator =(const ToppingsHandler& right_side);
    //First delete memory assigned to the private pointer of type Toppings,
    //and then make it equal to copy.
    bool validate(string topping_name);
    //Takes a name of a topping and iterates through the list of toppings
    //from the repo and returns true if it matches a valid topping name.
    Toppings get_topping(string topping_name) throw (InvalidNameException);
    //Takes a name of a topping and iterates through the list of toppings
    //from the repo and returns the topping of a matching name.
    int get_topping_list_size();
    //Returns the length of the toppings list
    void got_list();
    //If handler has yet to fetch list from repo then gets it, if it has list then does nothing
    void remove_topping_from_list(int index);
    //Takes index of a topping and deletes it from the database.

private:
    ToppingsRepo toppings_repo;
    //Access to the data layer is through ToppingsRepo.
    vector<Toppings> toppings;
    //The list of toppings that recevies information from the ToppingsRepo.
    int toppings_list_count;
    //Size of the above list.
    bool has_list;
};

#endif // TOPPINGSHANDLER_H
