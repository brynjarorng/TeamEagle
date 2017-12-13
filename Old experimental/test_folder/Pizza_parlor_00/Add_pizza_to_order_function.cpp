string pizza_name;
cin >> pizza_name;

if (pizzatype == menu_pizza) {

        cout << "Enter name of pizza:";
		string pizza_name;
		cin >> pizza_name;

		bool on_menu = pizzahandler.validate_name(pizza_name);
		if (on_menu) {
			pizza = pizzahandler.get_menu_pizza(pizza_name);
			order.add_pizza(pizza);
			this ->order_repo.current_write(order);
		}
		else {
			cout << "Pizza not on menu! " << endl;
		}
	}
	else if (pizzatype == special_pizza) {
		pizza = pizzahandler.create_special_pizza();
		order.add_pizza(pizza);
		this ->order_repo.current_write(order);
	}
	else {
		cout << "---(SYSTEM)NOT A PIZZATYPE---"  << endl;
	}
