#include<iostream>
#include "Toppings.h"
#include <vector>
#include <fstream>
using namespace std;

class FstreamClass
{
public:
	FstreamClass();
	~FstreamClass();
	//void print_list();
	void write_toppings(Toppings topping);
	Toppings* read_toppings();
	//write_sizes();
	//read_sizes();
	//write_pizzas();
	//read_pizzas();

private:
	Toppings topping;
	Toppings* topping_list;
	int topping_list_size;
};
