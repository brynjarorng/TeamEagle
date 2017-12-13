#include "Print.h"

///Toppings:

Print::Print() : user_prompt(false){

    this ->next = 'n';
    this ->previous = 'p';
    this ->alph_d = 'a';
    this ->alph_a = 'd';
    this ->price_a = 'h';
    this ->price_d = 'l';
    this ->print = none;
    this ->style = none_;
    this ->n = 0;
    this ->a = 0;
    this ->b = 0;
    this ->list_count = 0;
    this ->sort = alph_asc;
}
void Print::set(int n, print_item what) {

    this ->style = none_;
    this ->print = none;
    this ->sort = alph_asc;
    this ->print_topping_pizza = true;

    print_what(what);

    this ->a = 0;
    this ->n = n;
    this ->b = n;
}
 void Print::set(int n, print_style style, print_item what) {

    this ->sort = alph_asc;
    this ->style = style;

    print_what(what);

    this ->a = 0;
    this ->n = n;
    this ->b = n;
    this ->print_topping_pizza = true;
}
void Print::set(int n, Price price, print_item what) {

    this ->style = none_;
    this ->sort = alph_asc;
    print_what(what);
    this ->a = 0;
    this ->n = n;
    this ->b = n;
    this ->price = price;
    this ->print_topping_pizza = true;
}
void Print::set(int n, sort_by print_sort, Price price, print_item what) {

    this ->print = none;
    this ->sort = print_sort;
    this ->a = 0;
    this ->n = n;
    this ->b = n;
    this ->price = price;
    this ->print_topping_pizza = true;
    print_what(what);
}
void Print::set(int n, Price price, print_style style, print_item what) {

    this ->sort = alph_asc;
    print_what(what);
    this ->a = 0;
    this ->n = n;
    this ->b = n;
    this ->price = price;
    this ->style = style;
    this ->print_topping_pizza = true;
}

void Print::set(int n, sort_by print_sort, Price price,print_style style, print_item what) {

    this ->sort = print_sort;
    print_what(what);
    this ->a = 0;
    this ->n = n;
    this ->b = n;
    this ->price = price;
    this ->style = style;
    this ->print_topping_pizza = true;
}

void Print::set(int n, sort_by print_sort, print_item what) {

    this ->style = none_;
    this ->sort = print_sort;
    this ->a = 0;
    this ->n = n;
    this ->b = n;
    this ->print_topping_pizza = true;

    print_what(what);
}
void Print::prompt_user(bool user_prompt) {
    if (user_prompt) {
        this ->user_prompt = true;
    }
}

void Print::get(print_action action) {

    perform_action(action);
    print_what(print);
    //reset_b();

    print_selection();

}
void Print::perform_action(print_action action) {

    switch (action) {
        case next_screen:
            n_screen();
        break;
        case previous_screen:
            p_screen();
        break;
        case current_screen:
        break;
        case a_to_z:
            sort = alph_asc;
        break;
        case z_to_a:
             sort = alph_desc;
        break;
        case price_from_high:
             sort = price_desc;
        break;
        case price_from_low:
             sort = price_asc;
    }
}
void Print::print_what(print_item what) {

    if (what == top) {

        this ->toppings_list = toppings_sorted(sort);
        list_type = sort;
        this ->list_count = toppings_list.size();
       // reset_b();
        print = top;
    }
    else if (what == pizz) {

            print = pizz;
            this ->pizzas_list = pizza_sorted(sort);
            this ->list_count = pizzas_list.size();
           // reset_b();
    }
    else if (what == ord) {

            OrderHandler handler;
            this ->orders_list = handler.get_orders();
            this ->list_count = orders_list.size();
          //  reset_b();
            print = ord;
    }
    else {
        cout << "Error in print_what()" << endl;
    }

}
void Print::pizza(print_action action) {

    perform_action(action);
    print_what(pizz);
  //  reset_b();
    print_selection();
}
void Print::orders(print_action action) {

    perform_action(action);
    print_what(ord);
  //  reset_b();
    print_selection();
}

///Orders:

void Print::print_orders(int& n, sort_by sort_order) {
}
void Print::print_orders(int& a, int& b, int& n, sort_by sort_order) {
}

void Print::n_screen() {

    this ->a =  this ->b;
    this ->b =  this ->n + this ->b;

    if (this ->b > this ->list_count) {
        this ->b = this ->list_count;

        if (this ->a >= this ->list_count) {

            reset_b();
            this ->a = 0;
        }
    }
}

void Print::p_screen() {

    this ->b = this ->a;
    this ->a   = this ->a - this ->n;

    if (this ->a < 0) {
        this ->a = 0;
        reset_b();
        while (this ->b < this ->list_count) {
            n_screen();
        }
    }
}

void Print::reset_b() {

    if (this->list_count >= this ->n){
        this ->b = this ->n;
    }
    else {
        this ->b = this ->list_count;
    }
}

void Print::print_selection() {

    string selection = return_item_name(print);

    for (int i = a; i < b; i++) {

        if (print == top) {
                print_index(i);
                print_toppings(i);
        }
        if (print == pizz) {
                print_lines(50);
                print_index(i);
               // reset_b();
                print_pizzas(i);
        }
        if (print == ord) {
                print_orders(i);
        }
         cout  << " " << endl;
    }
     if (print != ord && print == pizz)  {
        print_lines(50);
    }

    if (style == header || style == head_and_index) {


        cout << setw(62)      << right      << selection
            << right << ": " << list_count << setw(65)
            << right << endl;
        cout << setw(65) << right  << " Displayed: "
            << a + 1    << " to " <<  b << setw(22) << endl;
        cout << setw(1);
        if (print != pizz) {
            print_lines(75);
        }

    }
    if (user_prompt & print != ord) {
        prompt_print();
    }
    if (print == ord) {
        prompt_order_print();
    }

    cout << endl;
}

void Print::print_toppings(int i) {

    if (i < toppings_list.size()) {

        cout << left<< setw(20)  << this -> toppings_list[i].get_name();

        cout << setw(20) << right ;

            if (this ->price) {

            cout  << "$" << this ->toppings_list[i].get_price();
            }
    }
}

void Print::print_pizzas(int i) {

    cout << setw(40) <<  left <<  this -> pizzas_list[i].get_name()

    << setw(2) << " :";

    if (this ->price) {
            cout  <<right<< " $" << this ->pizzas_list[i].get_price();
        }

    cout << " :" << endl;

    print_toppings_pizza(i);
}

void Print::print_toppings_pizza(int index) {

    Toppings* top_list = pizzas_list[index].get_toppings();
    int top_count = pizzas_list[index].get_toppingcount();
    int new_line_count = 0;

    if (print_topping_pizza) {

        for (int j = 0; j < top_count; j++) {

            cout << setw(2)<<right << "+"
                 << top_list[j].get_name() <<" ";


            if (print_topping_price) {
                cout << " $" << top_list[j].get_price() << endl;


            }

            new_line_count++;
            if (new_line_count >= 3) {
                cout << endl;
                new_line_count = 0;
            }
        }
    }
}

void Print::print_orders(int index){

    cout << "Order #"
         << this ->orders_list[index].get_order_number();
    cout << "\tTotal price: "
         << this->orders_list[index].get_total() << endl;

    print_lines(35);

    get_pizzas_order(index);
    this ->price = price;
    print_pizzas_for_order();
}

void Print::orders_toppings(bool top, bool menu) {
    this ->print_topping_pizza = top;
}

void Print::print_pizzas_for_order() {

    for (unsigned int j = 0; j < pizzas_list.size(); j++) {
        print_pizzas(j);
    }
}

void Print::get_pizzas_order(int index) {

    pizzas_in_order = orders_list[index].get_pizzas_in_order();
    pizzas_in_order_count = orders_list[index].get_order_count();
    this ->pizzas_list.clear();
    for (int i = 0; i < pizzas_in_order_count; i++ ) {
        this ->pizzas_list.push_back(pizzas_in_order[i]);
    }
}
void Print::print_index(int i) {

    if (style == indexed || style == head_and_index) {

        cout << "  (";

         if ( (i + 1) < 10) {
            cout << 0;
         }
        cout  << i + 1 << ") ";
    }
    else {
        cout << "*";
    }
}


void Print::pizza_settings(bool toppings, bool toppings_price) {
    this ->print_topping_pizza = toppings;
    this ->print_topping_price = toppings_price;
}

void Print::list_count_for(print_item print) {

    if (print == top) {
        this ->list_count = this ->toppings_list.size();
    }
    if (print == pizz) {
        this ->list_count = this ->pizzas_list.size();
    }
    if (print == ord) {
        this ->list_count = this ->orders_list.size();
    }
    else {
        this ->list_count = 0;
    }
}

void Print::print_lines (int line_count) {

    for (int i = 0; i <line_count; i++) {
        cout << "-";
    }
    cout << endl;
}

string Print::return_item_name(print_item print) {

    if (print == pizz) {
        return "Pizzas";
    }
    if (print == top) {
        return "toppings";
    }
    if (print == ord) {
        return "orders";
    }
    else {
        return "(System error) Something went wrong in the print item.";
    }
}

void Print::print_pizzas_helper(int index) {
    //cout << pizzas[index].get_name();
}

void Print::prompt_print() {

    cout  << "(a) Ascending \t\t(d) decending\n";
    cout  << "(n)" << " for next screen";
    cout <<  "\t(p)" << " for previous screen\n";
    cout <<  "(h) > price > (l)\t(b) to go back";
}
void Print::prompt_order_print() {

    cout  << "(n)" << " for next screen";
    cout <<  "\t(p)" << " for previous screen\n";
}
void Print::set_price(Price price) {
    this ->price = price;
}
