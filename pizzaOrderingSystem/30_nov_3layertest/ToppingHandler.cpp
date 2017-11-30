#include "ToppingHandler.h"

ToppingHandler::ToppingHandler()
{
	//
}

ToppingHandler::~ToppingHandler()
{
	delete[] toppings_list;
}

void ToppingHandler::create_topping() {
    Toppings topping;
    cin >> topping;

    repo.write_toppings(topping);
}

void ToppingHandler::print_toppings() {
	
	toppings_list = repo.read_toppings();
	//Retreive current toppings list from repository.
	toppings_list_size = repo.get_topping_list_size();
	for (int i = 0; i < toppings_list_size; i++) 
	{
		cout << toppings_list[i] << endl;
	}
	
}

