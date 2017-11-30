#include <iostream>
#include "fstreamClass.h"
using namespace std;

int main()
{
	FstreamClass test;

	test.write_toppings();

	test.read_toppings();

	test.print_toppings_list();

	test.write_pizzas();

	test.read_pizzas();

	test.print_pizza_list();
	

    return 0;
}
