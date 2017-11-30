#ifndef FSTREAMCLASS_H
#define FSTREAMCLASS_H
#include<iostream>
#include <vector>
#include <fstream>
#include "toppings.h"
#include "Pizza.h"
//#include "PizzaSize.h"
using namespace std;

class FstreamClass
{
public:
	FstreamClass();
	~FstreamClass();
	void print_pizza_list();
	//Temporary function to print list of pizza.
	void print_toppings_list();
	//Temporary function to print lists
	void write_toppings();
	//Writes an occurrence of topping to "toppings.dat" in the home folder.
	void read_toppings();
	//Reads all information contained in "toppings.dat" where each occurrence
	//of a topping will be contained in the dynamic_array topping_list.
/*	void write_sizes();
	
	void read_sizes();
	//Reads all information contained in "pizzas.dat" where each occurrence
	//of a topping will be contained in the dynamic_array topping_list.*/
	void write_pizzas();
	//Writes an occurrence of Pizza to "pizzas.dat" in the home folder.
	void read_pizzas();
private:
	Pizza pizza;
	Pizza* pizza_list;
	int pizza_list_size;
	///////////////////////////////////////////////////
/*	PizzaSize pizza_size;
	//Includes an occurrence of PizzaSize.
	PizzaSize* pizza_size_list;
	//Dynamic variable to get current list from "pizza_size.dat"
	int pizza_size_list_size;
	//The size of the dynamic array holding the loaded list.
	///////////////////////////////////////////////////////////////*/
	Toppings topping;
	//Includes an occurrence of ToppingsList.
	Toppings* topping_list;
	//The size of the dynamic array holding the loaded list.
	int topping_list_size;
//The size of the array holding the current information on toppings.	///////////////////////////////////////////////////////////////
};
#endif // FSTREAMCLASS_H
