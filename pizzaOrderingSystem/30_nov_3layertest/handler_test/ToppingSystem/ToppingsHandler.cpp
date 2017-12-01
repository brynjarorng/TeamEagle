#include "ToppingsHandler.h"

ToppingsHandler::ToppingsHandler()
{
	toppings_list = new Toppings[0];
}

ToppingsHandler::~ToppingsHandler()
{
	if (toppings_list != 0)
	{
		delete[] toppings_list;
	}
}

void ToppingsHandler::create_toppings() {
    Toppings topping;
	
    cin >> topping;

    repo.write(topping);
}

void ToppingsHandler::print_toppings() {

	toppings_list = repo.read();
	//Retreive current toppings list from repository.
	toppings_list_count = repo.get_list_count();
	for (int i = 0; i < toppings_list_count; i++)
	{
		cout << toppings_list[i] << endl;
	}

}

void ToppingsHandler::operator =(Toppings* copy)
{
	delete[] toppings_list;
	toppings_list = copy;
}
