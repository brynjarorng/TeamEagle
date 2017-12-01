#include <iostream>
#include "ToppingHandler.h"
using namespace std;

int main ()
{

	ToppingHandler handler;

	handler.create_topping();
	handler.print_toppings();
	
	return 0;
}
