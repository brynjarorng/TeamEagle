#include <PizzaHandler.h>
#include <ToppingsHandler.h

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

