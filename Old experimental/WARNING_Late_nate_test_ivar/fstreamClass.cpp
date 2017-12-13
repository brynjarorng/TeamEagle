#include "fstreamClass.h"
void FstreamClass::print_toppings_list()
{
	for (int i = 0; i < topping_list_size; i++) {
		cout << topping_list[i] << endl;
	}
}
void FstreamClass::print_pizza_list()
{
	for (int i = 0; i < pizza_list_size; i++) {
		cout << pizza_list[i] << endl;
	}
}

FstreamClass::FstreamClass()
{
	topping_list = new Toppings[1];
	pizza_list = new Pizza[1];
}
FstreamClass::~FstreamClass()
{
	delete[] topping_list;
	delete[] pizza_list;
//	delete[] pizza_size_list;
}
void FstreamClass ::write_toppings()
{
	cin >> topping;
	ofstream fout("toppings.dat", ios::binary|ios::app);
	fout.write((char*)(&topping), sizeof(Toppings));
	fout.close();
}
void FstreamClass::read_toppings()
{
	ifstream fin("toppings.dat", ios::binary);
	
	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Toppings);
		fin.seekg(0, fin.beg);

		topping_list_size = record_count;
		
		topping_list = new Toppings[record_count];
		
		
		fin.read((char*)(topping_list), sizeof(Toppings)*record_count);
		
		fin.close();
	}

//	return &topping_list;
}
/*void FstremClass::write_sizes()
{
	cin >> pizza_size;
	ofstream fout("pizza_size.dat", ios::binary|ios::app);
	fout.write((char*)(&pizza_size), sizeof(PizzaSize));
	fout.close();
}
void FstreamClass::read_sizes()
{
	ifstream fin("pizza_size.dat", ios::binary);
	
	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(PizzaSize);
		fin.seekg(0, fin.beg);

		pizza_size_list_size = record_count;
		
		pizza_size_list = new Toppings[record_count];
		
		
		fin.read((char*)(pizza_size_list), sizeof(PizzaSize)*record_count);
		
		fin.close();
	}
	}*/
void FstreamClass::write_pizzas()
{
	pizza.make_pizza();
	ofstream fout("pizza.dat", ios::binary|ios::app);
	fout.write((char*)(&pizza), sizeof(Pizza));
	fout.close();
}
void FstreamClass::read_pizzas()
{
	ifstream fin("pizzas.dat", ios::binary);
	
	if (fin.is_open()) {
		fin.seekg(0, fin.end);
		int record_count = fin.tellg() / sizeof(Pizza);
		fin.seekg(0, fin.beg);

		pizza_list_size = record_count;
		
		pizza_list = new Pizza[record_count];
		
		
		fin.read((char*)(pizza_list), sizeof(Pizza)*record_count);
		
		fin.close();
	}
}
   
