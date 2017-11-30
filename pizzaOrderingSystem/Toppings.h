#ifndef TOPPINGS_H
#define TOPPINGS_H

#include <string>
#include <iostream>
#include <cstring>
using namespace std;

const int CNAME_SIZE = 30;


using namespace std;

class Toppings{
    public:
        Toppings();
        //Toppings(char cname, int price);
        void namegame();
        friend ostream& operator << (ostream& outs, const Toppings& topping);
        friend istream& operator >> (istream& ins, Toppings& topping);
    private:
        //string name;
        char cname[CNAME_SIZE];
        double price;

};

#endif
