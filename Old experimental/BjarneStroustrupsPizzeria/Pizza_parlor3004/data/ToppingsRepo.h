#ifndef TOPPINGSREPO_H
#define TOPPINGSREPO_H

#include "Toppings.h"
#include <fstream>
#include <vector>
class ToppingsRepo {

public:
	ToppingsRepo();
	//Currently empty initializer.
	~ToppingsRepo();
	//Currently empty destructor.
	/*void write(Toppings topping);
	//Appends topping to a binary file located in the home directory.
	Toppings* read();
	//Return value is a dynamic array where each element is an occurrence
	//of a Toppings currently contained in "toppings.dat" in the home folder.
	//The allocated memory must be deleted where the pointer is received.*/
	int get_list_count() const;
	//Returns the size of the above list.
	vector<Toppings> read();
    //Return value is a vector where each element is an occurrence
	//of a Toppings currently contained in "toppings.dat" in the home folder.
	void write(Toppings& topping);
	//Appends topping to a binary file located in the home directory.
	void overwrite(vector<Toppings> toppings);
    //Rewrites a new file the same size as the parameter toppings, and replaces
    //the file with the content of the parameter.

private:
	Toppings topping;
	Toppings* list;
	int list_count;
	vector<Toppings> topping_list;
};


#endif // TOPPINGSREPO_H
