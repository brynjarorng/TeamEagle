#include<iostream>
#include "PizzaRepo.h"
#include "Pizza.h"
#include "Toppings.h"
#include "ToppingsRepo.h"
using namespace std;

int main ()
{
	ToppingsRepo toprepo;
	PizzaRepo pizzarepo;
	Pizza pizza;
	Toppings top;

	cin >> top;
	cin >> pizza;

	toprepo.write(top);
	pizzarepo.write(pizza);

	Pizza* p = pizzarepo.read();
	Toppings* t = toprepo.read();
	
	
	return 0;
}
