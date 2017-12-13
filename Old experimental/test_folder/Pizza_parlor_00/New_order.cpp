void new_order() {
    PizzaType pizzatype;
    string pizza_name;
    Pizza pizza;
    Order order;
    OrderHandler orderhandler;
    PizzaHandler pizzahandler;
    char exit = 'y';
    char piz = ' ';

    while (exit != 'n') {
        cout << "Press m for menu pizza, s for special pizza:";
        cin >> piz;
        if (piz == 'm') {
            pizzatype = menu_pizza;
        }
        else {
            pizzatype = special_pizza;
        }
        if (pizzatype == menu_pizza) {

            cout << "Enter name of pizza:";
            string pizza_name;
            cin >> pizza_name;

            bool on_menu = pizzahandler.validate_name(pizza_name);
            if (on_menu) {
                pizza = pizzahandler.get_menu_pizza(pizza_name);
                order.add_pizza(pizza);
            }
            else {
                cout << "Pizza not on menu! " << endl;
            }
        }
        else if (pizzatype == special_pizza) {
        string topping_name = " ";
          while (topping_name != "q") {
              cout << "Enter toppings, enter q when you are finished:";
                cin >> topping_name;
                if(!pizzahandler.add_topping (topping_name, pizza)) {
                    cout << "Topping not on list!" << endl;
                }
          }
          cout << pizza << endl;
          cout << "Do you wish to add this pizza to order? (y/n)";
          char pizza_to_order;
          cin >> pizza_to_order;
          if (pizza_to_order) {
            order.add_pizza(pizza);
          }
        }
        cout << "Add more pizzas to order? (y/n)";
        cin >> exit;
    }
    bool correct;
    cout << order;
    cout << "Is this order correct (y/n)?";
    cin >> correct;
    if (correct) {
        orderhandler.add_order(order);
    }
}
