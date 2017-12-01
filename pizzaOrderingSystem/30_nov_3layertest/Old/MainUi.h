#ifndef MAINUI_H
#define MAINUI_H
#include <iostream>
#include "ToppingHandler.h"
using namespace std;

class MainUi
{
public:
	MainUi();
	void insert_topping();
private:
	ToppingHandler handler;
};


#endif //TOPPINGS_H
