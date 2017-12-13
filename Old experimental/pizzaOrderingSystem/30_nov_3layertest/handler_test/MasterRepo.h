#include <fstream>

class MasterRepo {
	
public:
	MasterRepo();
	//Currently empty initializer.
	MasterRepo();
	//Currently empty destructor.
	void write(char list);
	//Appends topping to a binary file located in the home directory.
	//Where list is a character corresponding to a list in the following
	//system: 't' for toppings, 'p' for pizzas.
	Toppings* read();
	//Return value is a dynamic array where each element is an occurrence
	//of a Toppings currently contained in "toppings.dat" in the home folder.
	//The allocated memory must be deleted where the pointer is received.
	int get_list_count() const;
	//Returns the size of the above list. 

private:
	Toppings topping;
	Toppings* list;  
	int list_count;
};
