#ifndef PIZZAREPO_H
#define PIZZAREPO_H

#include "Pizza.h"
#include <fstream>

class PizzaRepo {

public:
	PizzaRepo();
	//Currently empty initializer.
	~PizzaRepo();
	//Currently empty destructor.
	void write(Pizza pizza);
	//Appends pizza to a binary file located in the home directory.
	Pizza* read();
	//Return value is a dynamic array where each element is an occurrence
	//of a Pizza currently contained in "pizzas.dat" in the home folder.
	//The allocated memory must be deleted where the pointer is received.
	int get_list_count() const;
	//Returns the size of the above list.

private:
	Pizza pizza;
	Pizza* list;
	int list_count;
};

#endif // PIZZAREPO_H
