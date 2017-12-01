#include <iostream>
#include "ToppingsHandler.h"
using namespace std;

int main ()
{
	ToppingsHandler one;

	Toppings topping;

	cout << topping;

	topping = one.get_topping("Skeinar");

	cout << topping;
	
	return 0;
}
