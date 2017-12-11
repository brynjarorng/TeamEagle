#ifndef MANAGER_FUNCTIONS_H
#define MANAGER_FUNCTIONS_H


#include "InvalidAlphaStringException.h"
#include "InvalidNumberException.h"
#include "InvalidBoolException.h"
#include "PizzaHandler.h"
#include "ToppingsHandler.h"
#include "ValidationFunctions.h"
#include "order_functions.h"

void create_topping() {
    clear();
    string choice;
    bool cont = 0;

    while(choice != "n") {
        Toppings topping;
        ToppingsHandler handler;

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
                    handler.create_topping(topping);
                }
                catch(InvalidNameException e) {
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

void print_toppings_with_number() {
    vector<Toppings> topping_vector;
    ToppingsHandler toppings_handler;
    topping_vector = toppings_handler.get_topping_list();

    for(unsigned int i = 0; i < topping_vector.size(); i++) {
        cout << "[" << i + 1 << "]\t" << topping_vector[i];

    }
    cout << endl;
}

void remove_topping() {
    ToppingsHandler handler;
    string number;
    bool cont = 0;
    clear();

    while(true) {
        do{
            print_toppings_with_number();

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
        handler.remove_topping_from_list(stoi(number) - 1);
    }
}



void make_new_menu_pizza() {
    Pizza pizza;
    PizzaHandler pizzahandler;
    ToppingsHandler toppingshandler;
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
        print_topping_list();
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
        catch(InvalidNameException e) {
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
        choice = " ";
        while(choice != " ") {
            choice = " ";
            try{
                pizzahandler.create_new_menu_pizza(pizza);
                choice = " ";
            }
            catch(InvalidNameException e) {
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

void print_menu_pizza_list_with_numbers() {
    PizzaHandler pizza_handler;
    vector<Pizza> pizza_vector;

    pizza_vector = pizza_handler.get_pizza_list();

    for(unsigned int i = 0; i < pizza_vector.size(); i++) {
        cout << "[" << i + 1 << "]\t" << pizza_vector[i];
    }
}

void remove_menu_pizza() {
    PizzaHandler handler;
    string number;
    while(true) {
        print_menu_pizza_list_with_numbers();
        cout << "Input the number of the pizza to remove, 0 to quit: ";
        cin  >> number;
        if(stoi(number) == 0) {
            break;
        }
        handler.remove_pizza_from_list(stoi(number) - 1);
    }
}

bool add_pizza_size() {
    PizzaSize pizza_size;
    PizzaSizeHandler size_handler;
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
            size_handler.validate_size(size);
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

            size_handler.validate_price(price);
        }
        catch(InvalidPrice e) {
            cont = 0;
            cout << "Invalid Price!" << endl;
        }
    } while(!cont);

    try{
        size_handler.add_size(size, price);
    }
    catch(InvalidSize e) {
        cout << "Error while writing size to database!" << endl;
        cout << "Is there already a product with that size in the database?" << endl;
        pause_screen();
        clear();
    }
    return 0;
}

void remove_size() {
    bool cont = 0;
    clear();
    cout << "--Remove a size---" << endl;
    while(true) {
        PizzaSizeHandler handler;
        print_size_with_numbers();
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
        handler.remove_size_from_list(stoi(number) - 1);
    }
    pause_screen();
}



#endif // MANAGER_FUNCTIONS_H
