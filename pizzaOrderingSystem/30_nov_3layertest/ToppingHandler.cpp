#include "ToppingHandler.h"

ToppingHandler::ToppingHandler()
{
	toppings_list = new Toppings[0];

}

ToppingHandler::~ToppingHandler()
{
	if (toppings_list != 0)
	{
		delete[] toppings_list;
	}
}

void ToppingHandler::create_topping() {
    Toppings topping;
    cin >> topping;

    repo.write_toppings(topping);
}

void ToppingHandler::print_toppings() {

	toppings_list = repo.read();
	//Retreive current toppings list from repository.
	toppings_list_size = repo.get_list_count();
	for (int i = 0; i < toppings_list_size; i++)
	{
		cout << toppings_list[i] << endl;
	}

}

void ToppingHandler::operator =(Toppings* copy)
{
	delete[] toppings_list;
	toppings_list = copy;
}
