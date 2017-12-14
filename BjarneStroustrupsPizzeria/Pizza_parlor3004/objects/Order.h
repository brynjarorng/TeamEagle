#ifndef ORDER_H
#define ORDER_H
#include "Pizza.h"
#include "PizzaType.h"
class Order {

public:

	Order();
	//Initializes order_ready and order_delivered to false,
	//also the pizza count in the order is set to 0.
	Pizza* get_order();
	//Returns an array of pizzas in the order.
	void set_delivered();
	//Marks the order as delivered.
	void set_paid();
	//Marks order paid
	bool get_delivered();
	//The return value is TRUE if the pizza is marked delivered
	//FALSE otherwise.
	friend ostream& operator <<(ostream& outs, Order& order);
	//Outstream will be each pizza in order followed by information
	//about pizza status: pizza in oven (T/F) and pizza ready (T/F).
	friend istream& operator >>(istream& ins, Order& order);
	//Instream is one occurrence of pizza wich will be the next element
	//in the private member array containing the pizzas in the order.d
    void add_pizza(Pizza pizza);
	//If pizzas_in_order_count <= MAX_ORDER_SIZE, pizza is added
	//to order, else an error message is printed to the screen.
	void set_order_number(int number);
	//Sets the order_number of this instance of order equal to number
	int get_order_number();
	//Returns the order number.
	bool ready();
	//Return value is true if all pizzas in orders are ready.
	//False otherwise.
	int get_order_count();
	//Returns the number of pizzas in the order.
	int get_max_orders();
	//Returns the maximum allowed orders.
	Pizza* get_pizzas_in_order();
	//Returns the list of pizza in the current order.
	double get_total();
	//Returns the total price of order.
	bool get_paid();
	//Returns true if the order is paid
	bool get_ready();
	//Returns true if order is ready
	void set_ready();
	//set order status to ready
    bool get_sent();
	//Returns true if order should be sent
	void set_sent();
	//set order status to order should be sent
	string get_addresse();
	//Returns string of the addresse
    void set_addresse(string input);
	//set the addresse
	string get_comment();
	//Returns string of the comment
    void set_comment(string input);
	//set the comment
	int get_comment_length();
private:
	static const int MAX_ORDER_SIZE = 20;
    //
    static const int MAX_COMMENT_LENGTH = 50;
    static const int MAX_ADDRESS_LENGTH = 26;
	bool order_ready;
    //True if all pizzas are ready in order.
	bool order_delivered;
    //True if pizza delivered.
    bool order_paid;
    //True if order has been paid
    bool order_sent;
    //True if order should be sent, false if it should be picked up
	Pizza pizzas_in_order[MAX_ORDER_SIZE];
	int pizzas_in_order_count;
	//Size of above array.
	int order_number;
    //Number of this instance of order.
	void all_pizzas_ready();
    //Returns true if all pizzas are marked ready.
    double total_price;
    //
    void calulate_total();
    //Calculates the order total and sets this->total_price equal to the total.
    char delivery_addresse[MAX_ADDRESS_LENGTH];
    //Addresse to deliver to
    char comment[MAX_COMMENT_LENGTH];
    //Any special request regarding the order go here
    int comment_length;
    int address_length;

};
#endif //ORDER
