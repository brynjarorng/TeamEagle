#ifndef TOPPINGS_H
#define TOPPINGS_H
#include <string>
#include<iostream>
#include <cstring>
#include <string>

const int   CNAME_SIZE = 20;

using namespace std;

class Toppings
{
public:
	Toppings();
	//Toppings(char cname, int price);
	Toppings(string name, double price);
	//
	string namegame();
	//Makes this->cname a copy of name[].
	friend ostream& operator << (ostream& outs, const Toppings& topping);
	friend istream& operator >> (istream& ins, Toppings& topping);
	string get_name();
private:
	char cname[CNAME_SIZE];
	double price;
	void append_null(int index);
	void convert_string_cstring(string in);
};

#endif // TOPPINGS_H
