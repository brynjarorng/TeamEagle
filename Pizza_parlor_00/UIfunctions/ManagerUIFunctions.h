#include "PizzaHandler.h"
#include "ToppingsHandler.h"

void set_shortcut(Toppings& topping);
//Sets an default shortcut key for the topping based on
//the first character of its name followed by a number which
//gets higher each time a topping with the same letter is found in the
//current toppings list.


void set_shortcut(Toppings& topping) {

    ToppingsRepo toppingsrepo;
    char letter_key = topping.get_name()[0];
    int number_key = 1;

    vector<Toppings> top = toppingsrepo.test_read_vector();
    Toppings temp1;
    for (int i = 0; i < top.size(); i++) {
        temp1 = top[i];
        if (number_key == temp1.hotnum() && temp1.get_name()[0] == letter_key) {
            number_key++;
        }
    }
    topping.set_hotkey(letter_key, number_key);
}


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
                    set_shortcut(topping);
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

void make_new_menu_pizza() {
    Pizza pizza;
    PizzaHandler pizzahandler;
    ToppingsHandler toppingshandler;
    Toppings topping;
    int max_tries = 5;
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
        for(int i = 0, j = 0; i <= max_tries && j <= max_tries;) {
            try{
                pizzahandler.create_new_menu_pizza(pizza);
                i = max_tries +1;
                j = max_tries +1;
            }
            catch(InvalidName e) {
                if(i >= max_tries) {
                    cout << "Out of tries!" << endl;
                    break;
                }
                cout << "Try again (" << max_tries - i << ") left." << endl;
                cout << "Pizza name is taken, try another: ";
                cin >> name;
                pizza.set_name(name);
                i++;
            }
            catch(InvalidPrice e) {
                if(j >= max_tries) {
                    cout << "Out of tries!" << endl;
                    break;
                }
                cout << "Try again (" << max_tries - j << ") left." << endl;
                cout << "Price must be a positive number, try another: ";
                cin >> price;
                pizza.set_price(price);
                j++;
            }
        }
    }
}
