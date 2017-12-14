#include "order_functions.h"

#include "ValidationFunctions.h"
void print_orders(Order_Status status, OrderHandler& orderhandler) {

    int ordercount = orderhandler.get_order_count();

    Order temp_order;

    int counter = 0;
    for (int i = 0; i < ordercount; i ++) {
        switch (status) {
            case delivered:
                    if (orderhandler.get_orders().at(i).get_delivered()) {
                        print_order(orderhandler.get_orders().at(i));
                        counter++;
                    }
                    break;
            case not_delivered:
                    if (!orderhandler.get_orders().at(i).get_delivered()) {
                        counter++;
                        print_order(orderhandler.get_orders().at(i));
                    }
                break;
            case all:
                print_order(orderhandler.get_orders().at(i));
                counter++;
                break;
        }
    }
    if (counter == 0) {
        cout << "No orders" << endl;
    }
}

void print_order(Order& order) {

    Print print;

   cout << "\033[1;31m" << "Order #"  << order.get_order_number() << "\033[0m\ " << endl;


    print.print_lines(30);
    Pizza* pizzas_in_order = order.get_pizzas_in_order();
    Pizza temp_pizza;

    int endl_count = order.get_order_count() - 1;

    for (int i = 0; i < order.get_order_count(); i++) {
        print_pizza(pizzas_in_order[i]);
        if (endl_count > 0)
            cout << endl;
        endl_count--;
    }
    print.print_lines(30);
    cout << "Total price: " << order.get_total() << endl;
    print.print_lines(30);
    cout << print.is_paid(order) << endl;
    cout << print.is_ready(order) << endl;
    cout << print.is_sent(order) << endl;
    cout << print.is_comment(order) << endl;

    if (order.get_delivered()) {
        cout << "This order has already been delivered."
             << endl;
    }

    print.print_lines(30);
    cout << endl;

}


void print_current_orders() {

    Print print;
    print.set(1, alph_asc, price,  header, ord);
    print_navigation (print, ord, ' ', true);
}

bool new_order(OrderHandler& orderhandler, PizzaHandler& pizzahandler, ToppingsHandler& toppingshandler, PizzaBottomHandler& bottomhandler) {

    Order order;
    string select;
    bool cont = 1;

    orderhandler.generate_order_no(order);
    cout << "Order #" << order.get_order_number() << endl;

    bool in_order =
    add_pizzas(order, orderhandler, pizzahandler, toppingshandler, bottomhandler);
    clear();
    if (order.get_order_count()) {
        sent_or_picked_up(order);

        comment(order);

        print_order(order);
        if (order.get_order_count()) {
            do{
                try{
                    cout << "Is this the correct order? (y/n) ";
                    getline(cin, select, '\n');
                    select = tolower(select[0]);
                    validate_bool_question(select);
                    cont = 0;
                }
                catch(InvalidBoolException e) {
                    cont = 1;
                    cout << e.get_err() << endl;
                }
            } while(cont);

            if (select == "y") {
                orderhandler.add_order(order);
                return false;
            } else {
                cout << "Order was not added" << endl;
                    return true;

            }
        }
    }
    return false;
}

void sent_or_picked_up(Order& order) {
    string input;
    bool cont = 1;

    do{
        try{
            cout << "Should the order be delivered to you (y/n)? ";
            cin >> ws;
            getline(cin, input, '\n');
            validate_bool_question(input);
            cont = 0;
        }
        catch(InvalidBoolException e) {
            clear();
            cont = 1;
            cout << e.get_err() << endl;
        }
    } while(cont);

    if(input == "y") {
        order.set_sent();
        set_delivery_addresse(order);
    }
}

void set_delivery_addresse(Order& order) {
    bool cont = 1;
    string input;
    do{
        try{
            cout << "Please enter your address (max 25 characters): ";
            cin >> ws;
            getline(cin, input);
            validate_addresse(input);
            cont = 0;
        }
        catch(InvalidAddresseException e) {
            clear();
            cont = 1;
            cout << e.get_err() << endl;
        }
    } while (cont);
    order.set_addresse(input);
}

bool add_pizzas(Order& order, OrderHandler& orderhandler, PizzaHandler& pizzahandler, ToppingsHandler& toppingshandler, PizzaBottomHandler& bottomhandler) {

    PizzaType pizzatype;
    char run = '\0';


    pizzatype = menu_or_special(run);
    bool orders;
    string run_menu;
    bool cont_menu = 1;
    bool cont = 1;
    if(run != 'b'){
        run = '\b';
        do {
            if (pizzatype == menu_pizza) {
                add_menu_pizza(order, pizzahandler, bottomhandler);

            }
            if (pizzatype == special_pizza) {
                add_special_pizza(order, pizzahandler, toppingshandler, bottomhandler);
                orders = add_special_pizza;
            }

            do{
                try{
                    cout << "Do you wish to add more pizzas to the order (y/n)? ";
                    cin >> ws;
                    getline(cin, run_menu);
                    run_menu = tolower(run_menu[0]);
                    validate_bool_question(run_menu);
                    cont = 0;
                    if(run_menu == "y") {
                        clear();
                        pizzatype = menu_or_special(run);
                        cont_menu = 1;
                    } else {
                        cont_menu = 0;
                    }
                }
                catch(InvalidBoolException e) {
                    cont = 1;
                    cout << e.get_err() << endl;
                }
            } while(cont);

        } while(cont_menu);
    }
    return orders;
}

PizzaType menu_or_special(char& run) {

    PizzaType pizzatype;

    bool quit = false;
    string type;
    bool cont;

    do {
        do{
            try{
                cout << "Input 'M' for menu pizza or 'C' for a custom pizza (B to go back): ";
                cin >> ws;
                getline(cin, type, '\n');
                validate_char(type);
                cont = 0;
                type = tolower(type[0]);

                if(type != "m" && type != "c" && type != "b") {
                    clear();
                    cont = 1;
                    cout << "Input is not a valid option!" << endl;
                }
                //Special case
            }
            catch(InvalidCharException e) {
                clear();
                cont = 1;
                cout << e.get_err() << endl;
            }
        } while(cont);

        type = tolower(type[0]);

        if (type == "m") {
            pizzatype = menu_pizza;
            quit = true;
        } else if (type == "c") {
            pizzatype = special_pizza;
            quit = true;
        } else if (type == "b") {
            run = 'b';
            quit = true;
        }

    } while (!quit && type != "b");
    return pizzatype;
}

bool add_menu_pizza(Order& order, PizzaHandler& pizzahandler, PizzaBottomHandler& bottomhandler) {

    Pizza pizza;
    char s;
    p_print_while_not_digits(pizza, s);
    if (s == 'b') {
        return false;
    }

    add_bottom(pizza, bottomhandler, pizzahandler);
    PizzaBottom bottom = pizza.get_bottom();
    clear();
    cout << "Pizza selected: " << "\"" << pizza.get_name() << "\"" << endl
         << "\n -Price $" << pizza.get_price() << endl
         << "\n -Size: " << bottom.get_size() << "\"" << endl;
    cout << "\n -Toppings: " << endl;
    for (int i = 0; i < pizza.get_toppingcount(); i++) {
        cout << "   ." << pizza.get_toppings()[i].get_name() << endl;
    }
    cout << "\n\nDo you want to add this pizza? (y/n) :";
    string in;
    cin >> in;
    if (in[0] == 'y') {
        order.add_pizza(pizza);
        return true;
    }

}
Pizza get_menu_p(PizzaHandler& pizzahandler, char& s) {

    Pizza selection = get_menu_selection(s);

    return selection;
}

void add_bottom(Pizza& pizza, PizzaBottomHandler& bottomhandler, PizzaHandler& pizzahandler) {

    bool cont = 0;
    string input;
    do{
        try{
            print_sizes_numbers(bottomhandler);
            cout << "Please select a size with the number in front of it: ";
            cin >> ws;
            getline(cin, input, '\n');
            validate_int(input);
            cont = 0;
        }
        catch(InvalidNumberException e) {
            cont = 1;
            cout << e.get_err() << endl;
        }
    } while(cont);

    pizzahandler.add_bottom_to_pizza(pizza, input);
}



vector <Toppings> toppings_to_special(ToppingsHandler& toppingshandler) {

    vector<Toppings> selection = add_topping_to_order();

    return selection;
}

vector <Toppings> get_toppings_selection() {


}


void print_navigation (Print& print, print_item type, char in,  bool loop) {


    string input;
    while(input[0] != 'b' && loop == true) {

        clear();
        print.get(current_screen);

        if (loop) {
            cin >> input;
        }
        else {
            input[0] = in;
        }

        if (input[0] == 'n') {
            print.get(next_screen);
        }
        if (input[0] == 'p') {
            print.get(previous_screen);
        }
        if (type == top || type == pizz) {
            if (input[0] == 'd') {
                print.get(z_to_a);
            }
            if (input[0] == 'a') {
                print.get(a_to_z);
            }
            if (input[0] == 'h') {
                print.get(price_from_high);
            }
            if (input[0] == 'l') {
                print.get(price_from_low);
            }
        }
    }
}
 void add_special_pizza(Order& order, PizzaHandler& pizzahandler, ToppingsHandler& toppingshandler, PizzaBottomHandler& bottomhandler) {

    Pizza pizza;

    pizza.set_name("Special order");

    add_bottom(pizza, bottomhandler,pizzahandler);

    vector <Toppings> selection;
    selection = toppings_to_special(toppingshandler);

    bool max_topping;
    if (selection.size() > pizza.get_max_toppings()) {
        cout << "Too many toppings selected!" << endl;
    }
    if (!max_topping) {

        clear();
        for (int i = 0; i < selection.size(); i++) {
            pizza.add_topping(selection.at(i));
        }
        pizza.set_price(pizzahandler.calc_price(pizza));

        bool cont = 1;
        string input;

        do{
            try{
                print_pizza(pizza);
                cout << "Do you want to add this pizza to the order? (y/n) ";
                cin.ignore();
                getline(cin, input, '\n');
                validate_bool_question(input);
                cont = 0;
            }
            catch(InvalidBoolException e) {
                cont = 1;
                cout << e.get_err() << endl;
            }
        } while(cont);
            order.add_pizza(pizza);
    }
}

void print_pizzas_toppings(Pizza pizza) {

    Toppings* top = pizza.get_toppings();
    int toppingcount = pizza.get_toppingcount();
    int comma_count = toppingcount - 1;
    for (int i = 0; i < toppingcount; i++) {
        cout << top[i].get_name();
        if (comma_count > 0) {
            cout << ", ";
        }
        comma_count--;
    }
    cout << "."  << endl;

}
void print_pizza(Pizza pizza) {

    cout << "*" << pizza.get_name() <<endl;
    print_pizzas_toppings(pizza);
    cout << "Price: " << pizza.get_price() + pizza.get_bottom().get_price() << " ISK" << endl;
    cout << "Size : " << pizza.get_bottom().get_size() << "\"" << endl;

}


void mark_paid(OrderHandler& orderhandler) {

    vector<Order> order_list = orderhandler.get_orders();
    int next = 0;
    string in;
    int order_nr;
    int counter = 0;
    if (order_list.size() > 0) {

        while (next < order_list.size()) {
            if (!order_list[next].get_paid() && !order_list[next].get_delivered()) {
                clear();
                print_order(order_list[next]);
                cout << "(m) to mark paid (n) for next order";
                cin >> in;
                counter++;
                if (in[0] == 'm') {
                    break;
                }
            }
            next++;
        }
        order_nr = order_list[next].get_order_number();
        orderhandler.paid(order_nr);
    }

    if (counter == 0) {
        cout << "No orders!, input any character to go back ";
        cin >> in;
    }
}

void mark_delivered(OrderHandler& orderhandler) {

    vector<Order> order_list = orderhandler.get_orders();
    int next = 0;
    char in = '\0';
    int order_nr;
    int counter = 0;
    if (order_list.size() > 0) {

        while (next < order_list.size()) {
            if (!order_list[next].get_delivered()) {
                clear();
                print_order(order_list[next]);
                cout << "(m) to mark delivered (n) for next order";
                cin >> in;
                counter++;
                if (in == 'm') {
                    break;
                }
            }
            next++;
        }
        order_nr = order_list[next].get_order_number();
        orderhandler.delivered(order_nr);
    }

    if (counter == 0) {
        cout << "No orders!, press b to go back";
        cin >> in;

    }
}

void print_order_list(int& refresh, string next, OrderHandler& orderhandler, bool skipdelivered, bool skippaid) {


}

void print_topping_list() {

    Print print;
    print.set(14, price, header, top);
    print.prompt_user(true);
    print.pizza_settings(true, false);
    print_navigation(print, top, ' ', true);
    clear();
}


void print_menu_pizza_list() {

    clear();
    Print print;

    print.set(4, alph_asc,price,header, pizz);

    print.pizza_settings(true, false);

    print.prompt_user(true);

    print_navigation(print, pizz, ' ', true);

    clear();
}


void print_sizes(PizzaBottomHandler& bottomhandler) {

    vector<PizzaBottom> size_vector;

    size_vector = bottomhandler.get_size_list();

    clear();

    cout << "---Print all pizza sizes---" << endl;

    cout << "See all sizes:" << endl;
    for(unsigned int i = 0; i < size_vector.size(); i++){
        cout << size_vector[i].get_price() << " ISK, ";
        cout << size_vector[i].get_size() << "\"" << endl;
    }
    cout << endl;
     //pause_screen();
}

void print_sizes_numbers(PizzaBottomHandler& bottomhandler) {

    vector<PizzaBottom> size_vector;

    size_vector = bottomhandler.get_size_list();

    clear();

    cout << "---Print all pizza sizes---" << endl;

    cout << "See all sizes:" << endl;
    for(unsigned int i = 0; i < size_vector.size(); i++){
        cout << "[" << i + 1 << "]" << " ";
        cout << size_vector[i ].get_price() << " ISK, ";
        cout << size_vector[i].get_size() << "\"" << endl;
    }
    cout << endl;
}

void print_size_with_numbers(PizzaBottomHandler& bottomhandler) {
    vector<PizzaBottom> size_vector;

    size_vector = bottomhandler.get_size_list();

    for(unsigned int i = 0; i < size_vector.size(); i++) {
        cout << "[" << i + 1 << "]\t";
        cout << size_vector[i].get_price() << " ISK, ";
        cout << size_vector[i].get_size() << "\"" << endl;
    }
}


void comment(Order& order) {
    clear();
    bool cont = 1;
    string input;
    do{
        try{
            cout << "Do you have any special requests (y/n)? ";
            cin >> ws;
            getline(cin, input, '\n');
            validate_bool_question(input);
            cont = 0;
        }
        catch(InvalidBoolException e) {
            clear();
            cont = 1;
            cout << e.get_err() << endl;
        }
    } while(cont);

    if(input == "y") {
        add_a_comment(order);
    } else {
        order.set_comment(" ");
    }
}

void add_a_comment(Order& order) {
    string temp;
    cout << "comment: ";
    cin >> ws;
    getline(cin, temp, '\n');
    order.set_comment(temp);
}

