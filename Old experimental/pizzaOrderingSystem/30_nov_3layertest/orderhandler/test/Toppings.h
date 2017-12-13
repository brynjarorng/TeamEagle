#ifndef TOPPINGS_H
#define TOPPINGS_H
#include <string>
#include<iostream>
#include <cstring>

using namespace std;

class Toppings
{
public:
	Toppings();
	//Initializes cname[0] = '\0' and price to 0.0. 
	Toppings(string name, double price);
	//Sets this ->price to price, and converts name to a corresponding
	//charachter array.
	//string namegame();
	friend ostream& operator << (ostream& outs, const Toppings& topping);
	//Outstreams name of topping followed by a whitespace and then the price
	//of the topping.
	friend istream& operator >> (istream& ins, Toppings& topping);
	//The order of instream is the following:
	//name then price.
	string get_name();
	//Returns the name of topping
	double get_price();
private:
	static const int NAME_SIZE = 21;
	char name[NAME_SIZE];	//Name of topping.
	double price;
	void append_null(int index);
	//Postcondtion: cname[index - 1] is now '\0'
	void convert_string_cstring(string in);
};
#endif //TOPPINGS_H
