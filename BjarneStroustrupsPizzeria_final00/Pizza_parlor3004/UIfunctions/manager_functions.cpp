#include "manager_functions.h"


void create_topping(ToppingsHandler& toppingshandler) {
    clear();
    string choice;
    bool cont = 0;

    while(choice != "n") {
        Toppings topping;
        clear();

        string name;
        do{
            try{
                cout << "Name: ";
                cin >> name;
                validate_string_input(name);
                cont = 0;
            }
            catch(InvalidAlphaStringException e) {
                cont = 1;
                cout << e.get_err() << endl;
            }
        } while(cont);
        topping.set_name(name);

        string price;
        do{
            try{
                cout << "Price: ";
                cin >> price;
                validate_int(price);
                cont = 0;
            }
            catch(InvalidNumberException e) {
                cont = 1;
                cout << e.get_err() << endl;
            }
        } while(cont);

        topping.set_price(price);

        do{
            try{
                cout << endl << topping << endl;
                cout << "Would you like to add this topping to the database? (y/n) ";
                cin >> choice;
                validate_bool_question(choice);
                cont = 0;
            }
            catch(InvalidBoolException e) {
                cont = 1;
                cout << e.get_err() << endl;

            }
        } while(cont);

        if(choice == "y") {
                try {
                    toppingshandler.create_topping(topping);
                }
                catch(InvalidName e) {
                    cout << "Topping already exists" << endl;
                    pause_screen();
                }
        }


        do{
            try{
                cout << endl << "Would you like to add more toppings? (y/n) ";
                cin >> choice;
                validate_bool_question(choice);
                cont = 0;
            }
            catch(InvalidBoolException e) {
                cont = 1;
                cout << e.get_err() << endl;
            }
        } while(cont);
    }
}



void remove_topping(ToppingsHandler& toppingshandler) {
    string number;
    bool cont = 0;
    clear();

    do{
        print_toppings_with_number(toppingshandler);

        try{
            cout << "Input the number of the topping to remove, 0 to quit: ";
            cin  >> number;
            validate_int(number);
            cont = 0;
            if(stoi(number) == 0) {
                cont = false;
            }
            toppingshandler.remove_topping_from_list(stoi(number) - 1);

        }
        catch(InvalidNumberException e) {
            clear();
            cont = 1;
            cout << e.get_err() << endl;
        }
        catch(InvalidSize e) {
            cout << "Number not on list"  << endl;
            pause_screen();
        }
        clear();
    } while(cont);
}




void make_new_menu_pizza(PizzaHandler& pizzahandler, ToppingsHandler& toppingshandler) {
    Pizza pizza;
    Toppings topping;
    string choice;
    bool cont = 0;

    string name;
    do{
        try{
            cout << "Name: ";
            cin.ignore();
            getline(cin, name);
            validate_int_string(name);
            cont = 0;
        }
        catch(InvalidAlphaNumException e) {
            cout << e.get_err() << endl;
            cont = 1;
        }
    } while(cont);

    pizza.set_name(name);

    string price;
    do{
        try{
            cout << "Price: ";
            cin >> price;
            validate_double(price);
            cont = 0;
        }
        catch(InvalidDoubleException e) {
            cont = 1;
            cout << e.get_err() << endl;
        }
    } while(cont);

    pizza.set_price(price);

    vector<Toppings> selection = add_topping_to_order();
    bool max_top = false;
    if ( selection.size() >= pizza.get_max_toppings()) {
        cout << "Too many toppings!!" << endl;
        max_top = true;
    }
    Toppings topptopp;
    for (unsigned int i = 0; i < selection.size(); i++) {

            if(!max_top) {
                topptopp = selection[i];
                pizza.add_topping(topptopp);
            }
    }

    choice = " ";

    cout << endl << pizza << endl;
    cout << "Would you like to add this pizza to the menu? (y/n) ";
    do{
        try{
            cin >> choice;
            validate_bool_question(choice);
            cont = 0;
        }
        catch(InvalidBoolException e) {
            cont = 1;
            cout << e.get_err() << endl;
        }
    } while(cont);

    if(choice == "y") {
        while(choice != " ") {
            choice = " ";
            try{
                pizzahandler.create_new_menu_pizza(pizza);
                choice = " ";
            }
            catch(InvalidName e) {
                cout << "Pizza name is taken, try again? (y/n) ";
                do{
                    try{
                        cin >> choice;
                        validate_bool_question(choice);
                        cont = 0;
                    }
                    catch(InvalidBoolException e) {
                        cont = 1;
                        cout << e.get_err() << endl;
                    }
                } while(cont);

                if(choice == "y") {
                    cout << "Name: ";
                    do{
                        try{
                            cin >> name;
                            validate_int_string(name);
                            cont = 0;
                        }
                        catch(InvalidAlphaNumException e) {
                            cont = 1;
                            cout << e.get_err();
                        }
                    } while(cont);

                    pizza.set_name(name);
                }
            }
            catch(InvalidPrice e) {
                cout << "Price must be a positive number, try again? (y/n) ";
                do{
                    try{
                        cin >> choice;
                    }
                    catch(InvalidBoolException e) {
                        cont = 1;
                        cout << e.get_err() << endl;
                    }
                } while(cont);
                if(choice == "y") {
                    cout << "Price: ";
                    cin >> price;
                    pizza.set_price(price);
                }
            }
        }
    }
}



void remove_menu_pizza(PizzaHandler& pizzahandler) {
    string number;
    while(true) {
        print_menu_pizza_list_with_numbers(pizzahandler);
        cout << "Input the number of the pizza to remove, 0 to quit: ";
        cin  >> number;
        try{
            validate_int(number);
            if(stoi(number) == 0) {
                break;
            }
            pizzahandler.remove_pizza_from_list(stoi(number) - 1);
        }
        catch(InvalidNumberException e) {
            cout << "Not a number" << endl;
        }
        catch(InvalidSize e) {
            cout << "Number not on list"  << endl;
            pause_screen();
        }
    }
}

bool add_pizza_size(PizzaBottomHandler& bottomhandler) {
    PizzaBottom pizza_size;
    bool cont = 0;
    string size;
    string price;

    clear();

    cout << "---Add a new size---" << endl;

    do{
        try{
            cont = 1;
            cout << "Enter new size (q to quit): ";
            cin >> ws;
            getline(cin, size);
            if(size == "q") {
                return 0;
            }
            bottomhandler.validate_size(size);
        }
        catch(InvalidSize e) {
            cont = 0;
            cout << "Invalid size!" << endl;
        }
    } while(!cont);

    do{
        try{
            cont = 1;
            cout << "Enter price (q to quit): ";
            cin >> price;
            if(size == "q") {
                return 0;
            }

            bottomhandler.validate_price(price);
        }
        catch(InvalidPrice e) {
            cont = 0;
            cout << "Invalid Price!" << endl;
        }
    } while(!cont);

    try{
        bottomhandler.add_size(size, price);
    }
    catch(InvalidSize e) {
        cout << "Error while writing size to database!" << endl;
        cout << "Is there already a product with that size in the database?" << endl;
        pause_screen();
        clear();
    }
    return 0;
}

void remove_size(PizzaBottomHandler& bottomhandler) {
    bool cont = true;
    clear();
    cout << "---Remove a size---" << endl;
    while(true) {
        print_size_with_numbers(bottomhandler);
        string number;
        do{
            try{
                cout << "Input the number of the size to remove, 0 to quit: ";
                cin  >> number;
                validate_int(number);
                if(stoi(number) == 0) {
                    break;
                }
                bottomhandler.remove_size_from_list(stoi(number) - 1);
                cont = false;
            }
            catch(InvalidNumberException e) {
                cout << "Not a number" << endl;
            }
            catch(InvalidSize e) {
                cout << "Size not found" << endl;
            }
        } while(cont);

        if(stoi(number) == 0) {
            break;
        }

    }
}

void make_new_side_order(SideOrdersHandler& sideorderhandler) {
    bool cont = 0;
    string name = " ";
    string price = " ";
    clear();
    cout << "---Create a new side order---" << endl;
    do{
        try{
            cout << "Input the name of new side order: ";
            cin >> ws;
            getline(cin, name, '\n');
            validate_string_input(name);
            cont = 0;
        }
        catch(InvalidAlphaStringException e) {
            clear();
            cont = 1;
            cout << e.get_err() << endl;
        }
    } while(cont);
    do {
        try{
            cout << "Input the price of new side order: ";
            cin >> ws;
            getline(cin, price, '\n');
            validate_double(price);
            cont = 0;
        }
        catch(InvalidDoubleException e) {
            clear();
            cont = 1;
            cout << e.get_err() << endl;
        }
    } while(cont);

    sideorderhandler.make_side_order(name, price);
}

void add_location(LocationHandler& lochandler) {
    string name;
    cout << "Name: ";
    cin >> ws;
    getline(cin, name);
    Location location;
    location.set_name(name);
    lochandler.add_location(location);
}

void remove_locations(LocationHandler& lochandler) {
    print_locations(lochandler, true);

    string ans;
    getline(cin, ans);
    bool cont = true;
    do{
        try{
            cout << "Insert number of location to remove (0 to quit): ";
            cin >> ws;
            getline(cin, ans);
            validate_int(ans);
            if(stoi(ans) == 0) {
                break;
            }
            lochandler.remove_location(stoi(ans) - 1);
            cont = false;
        }
        catch(InvalidNumberException e) {
            cout << "Not a number" << endl;
            pause_screen();
        }
        catch(InvalidSize e) {
            cout << "Location not on list" << endl;
            pause_screen();
        }
    }while(cont);
}

void archive_orders(OrderHandler& orderhandler) {
    cout << "Do you wish to archive the orders for " << orderhandler.get_location() << " ? ";
    string ans;
    cin >> ws;
    getline(cin, ans);
    try{
        validate_bool_question(ans);
        orderhandler.archive_orders();
    }
    catch(InvalidBoolException e) {
        cout << "Invalid answer" << endl;
        pause_screen();
    }
}


