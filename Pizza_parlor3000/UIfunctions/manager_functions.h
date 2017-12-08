#ifndef MANAGER_FUNCTIONS_H
#define MANAGER_FUNCTIONS_H



#include "PizzaHandler.h"
#include "ToppingsHandler.h"

/*
void make_pizza() {
    Pizza pizza;
    PizzaHandler pizzahandler;
    Toppings topping;

    bool valid_name = false;
    char choice = ' ';
    string name;
    while(!valid_name && choice != 'n') {
        cout << "Name: ";
        cin >> name;

        if(!pizzahandler.set_name(name, pizza)) {
            cout << "Pizza already exists, do you want to try again? (y/n)";
            cin >> choice; ///temp
        }
        else {
            valid_name = true;
        }
    }

    double price;

    cout << "Price: ";
    cin >> price;

    pizza.set_price(price);

    string topping_name;
    choice = '\0';
    for(int i = 0; (choice != 'n') && i < pizza.get_max_toppings(); i++) {
        cout << "Add a topping: ";
        cin >> topping_name;

        if(!pizzahandler.add_topping(topping_name, pizza)) {
            cout << "Topping does not exist" << endl;
            i--;
        }

        cout << "Would you like to add another topping? (y/n) ";
        cin >> choice;
    }

    choice = '\0';
    cout << pizza << endl;
    cout << "Would you like to add this pizza to the menu? (y/n) ";
    cin >> choice;

    if(choice == 'y'){
        pizzahandler.create_new_pizza(pizza);
    }
}

void create_topping() {
    char choice = '\0';

    while(choice != 'n') {
        Toppings topping;
        ToppingsHandler handler;
        string name;
        bool valid_name = false;

        while(!valid_name){
            cout << "Name: ";
            cin >> name;
            valid_name = handler.set_name(name, topping);

            if(!valid_name) {
                cout << "Topping already exists" << endl;
            }
        }

        double price;
        bool valid_price = false;

        while(!valid_price) {
            cout << "Price: ";
            cin >> price;
            valid_price = handler.set_price(price, topping);
            if(!valid_price) {
                cout << "Invalid input, please try again." << endl;
            }
        }


        cout << endl << topping << endl;
        cout << "Would you like to add this topping to the database? (y/n) ";
        cin >> choice;

        if(choice == 'y') {
            handler.create_topping(topping);
        }

        choice = '\0';

        cout << endl << "Would you like to add more toppings? (y/n) ";
        cin >> choice;
    }
}
*/
void create_topping() {
    char choice = '\0';
    int max_tries = 5;

    while(choice != 'n') {
        Toppings topping;
        ToppingsHandler handler;

        string name;
        cout << "Name: ";
        cin >> name;
        topping.set_name(name);

        double price;
        cout << "Price: ";
        cin >> price;
        topping.set_price(price);

        cout << endl << topping << endl;
        cout << "Would you like to add this topping to the database? (y/n) ";
        cin >> choice;

        if(choice == 'y') {
            for(int i = 0; i <= max_tries; i++) {
                try {
                    handler.create_topping(topping);
                    i = max_tries;
                }
                catch(InvalidName e) {
                    cout << "Topping already exists" << endl;
                    i = max_tries;
                }
                catch(InvalidPrice e) {
                    if(i >= max_tries) {
                        cout << "Out of tries!" << endl;
                        break;
                    }
                    cout << "Try again (" << max_tries - i << ") left." << endl;
                    cout << "Price must be a positive number, try another:  ";
                    cin >> price;
                    topping.set_price(price);
                }
            }
        }

        choice = '\0';

        cout << endl << "Would you like to add more toppings? (y/n) ";
        cin >> choice;
        cout << endl;
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
    while(true) {
        ToppingsHandler handler;
        print_toppings_with_number();
        string number;
        cout << "Input the number of the topping to remove, 0 to quit: ";
        cin  >> number;
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
    char choice = '\0';

    string name;
    cout << "Name: ";
    cin >> name;
    pizza.set_name(name);

    double price;
    cout << "Price: ";
    cin >> price;
    pizza.set_price(price);

    string topping_name;
    for(int i = 0; (choice != 'n') && i < pizza.get_max_toppings(); i++) {
        cout << "Add a topping: ";
        cin >> topping_name;
        try{
            Toppings topptopp;
            topptopp = toppingshandler.get_topping(topping_name);
            pizza.add_topping(topptopp);
            cout << "Would you like to add another topping? (y/n) ";
            cin >> choice;
        }
        catch(InvalidName e) {
            cout << "Topping does not exist, try again." << endl;
            i--;
        }
    }

    choice = '\0';

    cout << endl << pizza << endl;
    cout << "Would you like to add this pizza to the menu? (y/n) ";
    cin >> choice;

    if(choice == 'y') {
        choice = '\0';
        while(choice != 'n') {
            choice = '\0';
            try{
                pizzahandler.create_new_menu_pizza(pizza);
                choice = 'n';
            }
            catch(InvalidName e) {
                cout << "Pizza name is taken, try again? (y/n) ";
                cin >> choice;
                if(choice == 'y') {
                    cout << "Name: ";
                    cin >> name;
                    pizza.set_name(name);
                }
            }
            catch(InvalidPrice e) {
                cout << "Price must be a positive number, try again? (y/n) ";
                cin >> choice;

                if(choice == 'y') {
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

void add_pizza_size() {
    PizzaSize pizza_size;
    PizzaSizeHandler size_handler;
    bool cont = 0;
    string size;
    string price;

    do{
        try{
            cont = 1;
            cout << "Enter new size: ";
            cin >> size;

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
            cout << "Enter price: ";
            cin >> price;

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
        system("PAUSE");
        system("CLS");
    }
    catch(InvalidPrice e) {
        cout << "Error while writing price to database!" << endl;
        cout << "Is there already a product with that price in the database?" << endl;
        system("PAUSE");
        system("CLS");
    }
}

void print_sizes() {
    PizzaSizeHandler size_handler;
    vector<PizzaSize> size_vector;

    size_vector = size_handler.get_size_list();

    for(unsigned int i = 0; i < size_vector.size(); i++){
        cout << size_vector[i];
    }
}

void print_size_with_numbers() {
    PizzaSizeHandler pizza_handler;
    vector<PizzaSize> size_vector;

    size_vector = pizza_handler.get_size_list();

    for(unsigned int i = 0; i < size_vector.size(); i++) {
        cout << "[" << i + 1 << "]\t" << size_vector[i];
    }
}

void remove_size() {
    while(true) {
        PizzaSizeHandler handler;
        print_size_with_numbers();
        string number;
        cout << "Input the number of the size to remove, 0 to quit: ";
        cin  >> number;
        if(stoi(number) == 0) {
            break;
        }
        handler.remove_size_from_list(stoi(number) - 1);
    }
}



#endif // MANAGER_FUNCTIONS_H
