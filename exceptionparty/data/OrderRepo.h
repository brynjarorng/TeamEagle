#ifndef ORDERREPO_H
#define ORDERREPO_H

#include "Order.h"
#include <fstream>
#include <string>
enum ListType{current, archived};

class OrderRepo {

public:
	OrderRepo();
	//Currently empty initializer.
	~OrderRepo();
	//Currently empty destructor.
	void current_write(Order orders);
	//Appends orders to a binary file located in the home directory.
	Order* current_read();
	//Return value is a dynamic array where each element is an occurrence
	//of a current Order currently contained in "current_orders.dat" in the home folder.
	//The allocated memory must be deleted where the pointer is received.
	int get_current_count() const;
	//Returns the size of the above list
	Order* archived_read();
	//Return value is a dynamic array where each element is an occurrence
	//of an archived Order currently contained in "archived_orders.dat" in the home folder.
	//The allocated memory must be deleted where the pointer is received
	int get_archived_count() const;
	//Returns the size of the above list
    //void move_to_archived(int order_number);
	//Moves an order in the current order to archived order.
	void overwrite_list(Order* order, int list_count);
	//Rewrites the "current_orders.dat" with order.

private:

	Order orders;
	Order* list;
	//For dumping list.
	int archived_list_count;
	int current_list_count;
	void read();
	//Dumps the list of type List to the private pointer list.
};

#endif // ORDERREPO_H
