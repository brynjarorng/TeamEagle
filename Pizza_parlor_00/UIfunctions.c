Pizza pizza;
    PizzaHandler pizzahandler;
    Toppings topping;

    bool valid_name = false;
    char exit = ' ';
    string name;
    while(!valid_name && exit != 'n') {
        cout << "Name: ";
        cin >> name;

        if(!pizzahandler.set_name(name, pizza)) {
            cout << "Pizza already exists, do you want to try again? (y/n)";
            cin >> exit; ///temp
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
    exit = '\0';
    for(int i = 0; (exit != 'n') && i < pizza.get_max_toppings(); i++) {
        cout << "Add a topping: ";
        cin >> topping_name;

        if(!pizzahandler.add_topping(topping_name, pizza)) {
            cout << "Topping does not exist" << endl;
            i--;
        }

        cout << "Would you like to add another topping? (y/n) ";
        cin >> exit;
    }

    exit = '\0';
    cout << pizza << endl;
    cout << "Would you like to add this pizza to the menu? (y/n) ";
    cin >> exit;

    if(exit == 'y'){
        pizzahandler.create_new_pizza(pizza);
    }
    else {
       // break;
    }
