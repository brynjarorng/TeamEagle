#include "ToppingHandler.h"

ToppingHandler::ToppingHandler()
{
    //ctor
}

ToppingHandler::~ToppingHandler()
{
    //dtor
}

void ToppingHandler::create_topping() {
    Toppings topping;
    cin >> topping;

    repo.write_topping(topping);
}


