#ifndef MANAGER_FUNCTIONS_H
#define MANAGER_FUNCTIONS_H


#include "InvalidAlphaStringException.h"
#include "InvalidNumberException.h"
#include "InvalidBoolException.h"
#include "ValidationFunctions.h"
#include "order_functions.h"

void create_topping(ToppingsHandler& toppingshandler) {
    clear();
    string choice;
    bool cont = 0;

    while(choice != "n") {
        Toppings topping;

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

void print_toppings_with_number(ToppingsHandler& toppingshandler) {
    vector<Toppings> topping_vector;
    topping_vector = toppingshandler.get_topping_list();

    for(unsigned int i = 0; i < topping_vector.size(); i++) {
        cout << "[" << i + 1 << "]\t" << topping_vector[i];

    }
    cout << endl;
}

void remove_topping(ToppingsHandler& toppingshandler) {
    string number;
    bool cont = 0;
    clear();

    while(true) {
        do{
            print_toppings_with_number(toppingshandler);

            try{
                cout << "Input the number of the topping to remove, 0 to quit: ";
                cin  >> number;
                validate_int(number);
                cont = 0;
            }
            catch(InvalidNumberException e) {
                clear();
                cont = 1;
                cout << e.get_err() << endl;
            }
            clear();
        } while(cont);


        if(stoi(number) == 0) {
            break;
        }
        toppingshandler.remove_topping_from_list(stoi(number) - 1);
    }
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

    string topping_name;
    for(int i = 0; (choice != "n") && i < pizza.get_max_toppings(); i++) {
        clear();
        print_topping_list(toppingshandler);
        cout << "Add a topping: ";
        cin >> topping_name;
        try{
            Toppings topptopp;
            topptopp = toppingshandler.get_topping(topping_name);
            pizza.add_topping(topptopp);
            do{
                try{
                    cout << "Would you like to add another topping? (y/n) ";
                    cin >> choice;
                    validate_bool_question(choice);
                    cont = 0;
                }
                catch(InvalidBoolException e) {
                    cont = 1;
                    cout << e.get_err() << endl;
                }
            } while (cont);

        }
        catch(InvalidName e) {
            //Special error
            cout << "Not a valid topping!" << endl;
            pause_screen();
            i--;
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

void print_menu_pizza_list_with_numbers(PizzaHandler& pizzahandler) {
    vector<Pizza> pizza_vector;

    pizza_vector = pizzahandler.get_pizza_list();

    for(unsigned int i = 0; i < pizza_vector.size(); i++) {
        cout << "[" << i + 1 << "]\t" << pizza_vector[i];
    }
}

void remove_menu_pizza(PizzaHandler& pizzahandler) {
    string number;
    while(true) {
        print_menu_pizza_list_with_numbers(pizzahandler);
        cout << "Input the number of the pizza to remove, 0 to quit: ";
        cin  >> number;
        if(stoi(number) == 0) {
            break;
        }
        pizzahandler.remove_pizza_from_list(stoi(number) - 1);
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
            cin >> size;
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
    bool cont = 0;
    clear();
    cout << "--Remove a size---" << endl;
    while(true) {
        print_size_with_numbers(bottomhandler);
        string number;
        do{
            try{
                cout << "Input the number of the size to remove, 0 to quit: ";
                cin  >> number;
                validate_int(number);
                cont = 0;
            }
            catch(InvalidNumberException e) {
                cont = 1;
                cout << e.get_err() << endl;
            }
        } while(cont);

        if(stoi(number) == 0) {
            break;
        }
        bottomhandler.remove_size_from_list(stoi(number) - 1);
    }
    pause_screen();
}



#endif // MANAGER_FUNCTIONS_H
