#include "ToppingsHandler.h"

ToppingsHandler::ToppingsHandler()
{
	toppings_list = new Toppings[0];
}

ToppingsHandler::~ToppingsHandler()
{
		delete[] toppings_list;
}

void ToppingsHandler::create_toppings()
{
    Toppings topping;

    cin >> topping;

    repo.write(topping);
}

void ToppingsHandler::print_toppings()
{
	toppings_list = repo.read();
	//Retreive current toppings list from repository.
	toppings_list_count = repo.get_list_count();
	for (int i = 0; i < toppings_list_count; i++) {
		cout << toppings_list[i] << endl;
	}
}

bool ToppingsHandler::validate(string topping_name)
{
    string name;
    toppings_list = repo.read();
    toppings_list_count = repo.get_list_count();
    for(int i = 0; i < toppings_list_count; i++) {
        name = toppings_list[i].name;
        if(name == topping_name) {
            return true;
        }
    }

    return false;
}

Topping ToppingsHandler::get_topping(string topping_name)
{
    string name;
    toppings_list = repo.read();
    toppings_list_count = repo.get_list_count();
    for(int i = 0; i < toppings_list_count; i++) {
        name = toppings_list[i].name;
        if(name == topping_name) {
            return toppings_list[i];
        }
    }
}

void ToppingsHandler::operator =(Toppings* copy)
{
	delete[] toppings_list;
	toppings_list = copy;
}
