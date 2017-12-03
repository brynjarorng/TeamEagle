#ifndef TOPPINGSREPO_H
#define TOPPINGSREPO_H

#include "Toppings.h"
#include <fstream>

class ToppingsRepo {

public:
	ToppingsRepo();
	//Currently empty initializer.
	~ToppingsRepo();
	//Currently empty destructor.
	void write(Toppings topping);
	//Appends topping to a binary file located in the home directory.
	Toppings* read();
	//Return value is a dynamic array where each element is an occurrence
	//of a Toppings currently contained in "toppings.dat" in the home folder.
	//The allocated memory must be deleted where the pointer is received.
	int get_list_count() const;
	//Returns the size of the above list.

private:
	Toppings topping;
	Toppings* list;
	int list_count;
};


#endif // TOPPINGSREPO_H
