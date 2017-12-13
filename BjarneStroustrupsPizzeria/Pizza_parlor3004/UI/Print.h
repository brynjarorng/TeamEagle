#ifndef PRINT_H               //The following print variables are used:
#define PRINT_H               //print_action{next_screen, previous_screen, current_screen,
#include "sorting_function.h" //a_to_z, z_to_a, price_from_high, price_from_low}.
#include <iomanip>            //print_item{top, pizz, ord}.
#include "print_types.h"      //print_style{header, indexed, head_and_index}.
#include "OrderHandler.h" //Price {price = true, no_price = false}.

class Print {
    //the refrence variable sort_order used below can take the following values:
    //      * (alph_asc) for printing in lexiographic asceding order,
    //      * (alph_desc) for printing in lexiographic descending order,
    //      * (price_asc) for printing lowest price to highest,
    //      * (price_desc) for printing highest price to lowest.
    public:
        Print();
        ///Toppings
        void set(int n, print_item what);
        //Settings are set so that n elements will be printed of
        //the selected item.
        void set(int n, print_style style, print_item what);
        //Settings are: n items will be printed, the print style is set to
        //the variable style, and item corresponding to what will be printed.
        void set(int n, Price price, print_item what);
        //Settings are set so n elements are printed, price is displayed
        //if price = price and not displayed if price = no_price, and the selected item
        //what will be printed.
        void set(int n, sort_by print_sort, print_item what);
        //Settings are set to n print items, order of sort, price displayed if
        //display_price is true, and an item corresponding to what will be printed.
        void set(int n, sort_by print_sort, Price price, print_item what);
        //Settins are set so n elements will be printed, printed in the order
        //of sort_by (alph_desc, alph_asc, price_asc, price_desc), price or no_price can be
        //selected and item corresponding to what will be printed.
        void set(int n, sort_by print_sort, Price price,print_style style, print_item what);
        void set(int n, Price price, print_style style, print_item what);
        void print_toppings(print_action action);
       // Prints toppings from a to b, n at a time in order of sort_order.
        ///Pizza
        void pizza(print_action action);
        //Prints all pizzas in the order of the refrence sort_order.
        ///Orders
        void orders(print_action action);
        //Prints all pizzas in the order of the refrence sort_order.
        void print_orders(int& n, sort_by sort_order);
        //Prints all pizzas in the order of the refrence sort_order, n at a time.
        void print_orders(int& a, int& b, int& n, sort_by sort_order);
        //Prints pizzas from a to b, n at a time in order of sort_order.
        void get(print_action action);
        //Select between current_screen, next_screen, previous_screen, a_to_z, z_to_a,
        //price_from_high, price_from_low.
        void perform_action(print_action action);
        void prompt_user(bool user_promt);
        //If user_prompt is true, then a menu prompting the user for input is printed.
        void n_screen();
        void p_screen();

        void pizza_settings(bool toppings, bool toppings_price);
        //If toppings is true, then toppings is printed along with pizza list,
        //if toppings_price is true then price of each toppings is also printed.
        void set_price(Price price);
        //if price then price is displayed.
        void orders_toppings(bool top, bool menu);
        //if top true then toppings are printed, if menu true, then display menu.
        void topping_add(bool on);
        //If on is true, then a message approptiate when adding toppings to a special
        //pizza is printed.
        void print_lines(int line_count);
        //Print line_count length of dashed line followed by an endl.
        sort_by get_sort_order();
        string is_comment(Order& order);
        //Returns the users comment
        string is_sent(Order& order);
        //Gets the delivery addresse or pickup location
        string is_paid(Order& order);
        //Returns string to print (if order is paid or not)
        string is_ready(Order& order);
        //Returns string to print (if order is ready or not)
        void print_input(vector<Pizza> input);
    private:
        sort_by sort;
        sort_by list_type;
        print_item print;
        print_style style;
        string which_order(sort_by& sort);
        //The return value is the next available sort order.
        void which_prompt(print_item item);
        //Prints a prompt message appropriate to each print_item.
        bool user_prompt;
        bool print_topping_price;
        bool print_topping_pizza;
        bool add_topping;
        Price price;
        vector<Toppings> toppings_list;
        vector<Pizza> pizzas_list;
        vector<Order> orders_list;
        int list_count;
        void list_count_for(print_item print);
        int a;//The lower bound for print
        int b;//Upper bound for print.
        int n;//nr of elements to be printed.

        void topping_add_prompt();
        //Displays a message appropriate when adding toppings
        //top a special pizza.
        void reset_b();
        void prompt_order_print();
        //Special prompt for order.

        void print_selection();
        string return_item_name(print_item print);
        //Returns the string corresponsing to the selected item.
        void print_pizzas_helper(int index);
        void print_toppings_pizza(int index);
        void print_toppings(int i);
        void print_pizzas(int i);
        void print_orders(int index);
        void print_index(int i);
        void print_what(print_item what);
        void prompt_print();
        //Prints input prompt for the user.
        void get_pizzas_order(int index);
        void print_pizzas_for_order();
        string next;
        string previous;
        string alph_d;
        string alph_a;
        string price_a;
        string price_d;

        Pizza* pizzas_in_order;
        int pizzas_in_order_count;
        int pizza_count;

        bool input_list;
};

#endif // PRINT_H
