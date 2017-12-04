#include "UI.h"
#include <iostream>
#include "UIHandler.h"

using namespace std;


    UIHandler info_menu("Info:", "Toppings", "Pizzas", "Pizza sizes");
    //Set the text on the 'Toppings info' submenu. Used for looking
    //at all available food ordering options
    UIHandler toppings_menu("Toppings:", "Add toppings", "Remove toppings", "See all toppings");
    //Set the text on the 'toppings' submenu page
    UIHandler new_pizza_menu("Create a new pizza:", "Create pizza", "Remove pizza", "See all pizas");
    //set the text on the 'create new pizza' submenu
    //SIZE STILL NEEDS TO BE IMPLEMENTED!
    UIHandler manager("Menu:", "Pizza information", "Toppings", "Pizza size", "Make a new pizza");
    //Set the text on the default manager menu page
    ///UI var. for Manager

    UIHandler baker_menu("Baker:", "Toggle in oven", "Toggle ready");
    //Set the text on the default Baker menu page
    ///Baker UI (WILL CHANGE IN FULL SYSTEM!)

    UIHandler phone_status_menu("Get status of:", "Current orders", "Pizzas", "Toppings");
    //Set the text on the 'status' submenu for the phone clerk
    UIHandler phone_menu("Phone orders: ", "New order", "Get all orders", "status");
    //Set the text on the default phone clerk menu
    ///Telephone clerk

    UIHandler clerk_order_menu("Orders:", "Current orders", "Pizzas", "Toppings");
    //Set the text on 'order' submenu. For marking paid, sent and picked up
    UIHandler clerk_status_menu("Get status of:", "Current orders", "Pizzas", "Toppings");
    //Set the text on the 'status of order and items' submenu
    UIHandler clerk_menu("Salesman orders: ", "New order", "Get all orders", "status", "Order details");
    //Set the text on the default Sales clerk menu
    ///Sales clerk

    UIHandler customer_menu("Customer portal:", "Order a new pizza", "Order status", "Pizza list", "Topping list");
    //global decl. of UI elements

UI::UI() {
    run = 0;
}

void UI::print_login_selector(bool run) {
    system("CLS");

    char selector = ' ';

    cout << "Welcome to pizza & co." << endl << endl;

    cout << "----LOGIN SELECTOR----" << endl;
    cout << "(m) Manager" << endl;
    cout << "(b) Baker" << endl;
    cout << "(t) Telephone operator" << endl;
    cout << "(c) Customer portal" << endl;
    cout << "(s) Sales clerk" << endl;
    cout << "(q) Quit" << endl;
    if(run){
        cout << "Incorrect input!" << endl;
    }
    cout << ": ";

    cin >> selector;
    selector = lower(selector);

    switch(selector) {
    case 'm':
            manager_selector(selector);
            ///The manager selection UI page
        break;
    case 'b':
            baker_selector();
            ///The baker menu page
        break;
    case 't':
            system("CLS");
            phone_selector(selector);
            ///The phone clerk menu page
        break;
    case 's':
            system("CLS");
            clerk_selector(selector);
            ///The store clerk selector page
        break;
    case 'c':
            system("CLS");
            customer_selector(selector);
            ///The customer selector page
        break;
    case 'q':
            terminate();
            ///Halts the program
        break;
    default:
            system("CLS");
            print_login_selector(1);
            ///Print the login selector again with the error message
        break;
    }

}

char UI::lower(char instring) {
    StdInput s;
    instring = s.to_lower_case(instring);
    return instring;
}

void UI::terminate() {
    system("CLS");
    char cont;

    cout << "Are you sure you want to quit (y/n)? ";
        cin >> cont;
        cont = lower(cont);

    if(cont == 'y'){
        cout << "Good Bye!" << endl;
        exit(0);
    }
    print_login_selector(0);
    //Double check if user wants to quit, else runs the
    //manager UI again
}

void UI::manager_selector(bool selectorn) {
    ret_val = manager.menuUI(0);

    if(ret_val == 99) {
        print_login_selector(0);
        ///Returns to User selector

    } else if(ret_val == 1) {
        ret_val = info_menu.menuUI(0);
        info_creator(ret_val);
        ///To pizza info menu

    } else if(ret_val == 2) {
        ret_val = toppings_menu.menuUI(0);
        topping_creator(ret_val);
        ///To topping menu

    } else if(ret_val == 3) {
        ///To size menu

    } else if(ret_val == 4) {
        ret_val = new_pizza_menu.menuUI(0);
        pizza_creator(ret_val);
        ///To create a new pizza menu
    }


}

void UI::info_creator(int ret_val) {
    if(ret_val == 99) {
        manager_selector(0);
        //Go one level up, to manager menu
    } else if(ret_val == 1) {
        cout << "Print toppings: " << endl;
        system("CLS");
        handler.print_toppings();
        system("PAUSE");
        manager_selector(0);
        //print all toppings
    } else if(ret_val == 2) {
        system("CLS");
        cout << "Print all pizzas: " << endl;
        system("PAUSE");
        manager_selector(0);
        //print all pizza sizes
    } else if(ret_val == 3) {
        system("CLS");
        cout << "Print all pizza sizes: " << endl;
        system("PAUSE");
        manager_selector(0);
        //print all pre-made pizzas
}
}

void UI::topping_creator(int ret_val) {
    char cont = 0;
    if(ret_val == 99) {
        manager_selector(0);
        //Go one level up, to manager menu
    } else if(ret_val == 1) {
        cout << "Add toppings" << endl;
        do{
            handler.create_toppings();
            do{
                cout << "Do you want to input more Toppings (y/n)? ";
                cin >> cont;
                //system("PAUSE");
                cont = lower(cont);
            } while(cont == 'y' && cont == 'n');
        } while(cont == 'y');
        manager_selector(0);
        //Add toppings
    } else if(ret_val == 2) {
        system("CLS");
        cout << "remove toppings" << endl;
        system("PAUSE");
        manager_selector(0);
        //remove toppings
    } else if(ret_val == 3) {
        system("CLS");
        cout << "All toppings" << endl;
        handler.print_toppings();
        system("PAUSE");
        manager_selector(0);
        //see all toppings
    }
}

void UI::pizza_creator(int ret_val) {
    if(ret_val == 99) {
        manager_selector(0);
        //Go one level up, to manager menu
    } else if(ret_val == 1) {
        system("CLS");
        cout << "Create a new pizza: Missing handler" << endl;
        system("PAUSE");
        manager_selector(0);
        //Add toppings
    } else if(ret_val == 2) {
        system("CLS");
        cout << "Remove an old pizza: Missing handler";
        system("PAUSE");
        //remove toppings
    } else if(ret_val == 3) {
        system("CLS");
        cout << "See all pizzas: Missing handler" << endl;
        system("PAUSE");
        manager_selector(0);
        //see all toppings
    }
}

void UI::baker_selector() {
    char cont;
    system("CLS");

    cout << "Print out list of pizzas her" << endl;

    ret_val = baker_menu.menuUI(0);

    if(ret_val == 99) {
        print_login_selector(0);
        ///Returns to User selector

    } else if(ret_val == 1) {
        ///MISSING FUNCTION CALLS
        do{
            do{
                system("CLS");
                cout << "Print out list of pizzas her" << endl;
                cout << "Do you want to toggle another pizza in oven (y/n)? ";
                cin >> cont;
                cont = lower(cont);
            } while(cont == 'y' && cont == 'n');
        } while(cont == 'y');
        baker_selector();
        ///Toggle in oven

    } else if(ret_val == 2) {
        ///MISSING FUNCTION CALLS
        do{
            do{
                system("CLS");
                cout << "Print out list of pizzas her" << endl;
                cout << "Do you want to toggle more pizzas ready (y/n)? ";
                cin >> cont;
                cont = lower(cont);
            } while(cont == 'y' && cont == 'n');
        } while(cont == 'y');

        baker_selector();
        ///Toggle ready
    }
}


void UI::phone_selector(bool selector) {
    ret_val = phone_menu.menuUI(0);

    if(ret_val == 99) {
        print_login_selector(0);
        ///Returns to User selector

    } else if(ret_val == 1) {
        cout << "New order function" << endl;
        system("PAUSE");
        phone_selector(1);
        ///New order menu

    } else if(ret_val == 2) {
        cout << "Get all current orders" << endl;
        system("PAUSE");
        phone_selector(0);
        ///To topping menu

    } else if(ret_val == 3) {
        ret_val = phone_status_menu.menuUI(0);
        phone_status_ui(ret_val);
        phone_selector(0);
        ///To size menu
    }

}

void UI::phone_status_ui(int ret_val) {
    if(ret_val == 99) {
        phone_selector(0);
        //Go one level up, to manager menu
    } else if(ret_val == 1) {
        system("CLS");
        cout << "Current orders: missing function call" << endl;
        system("PAUSE");
        phone_status_ui(0);
        //Add toppings
    } else if(ret_val == 2) {
        system("CLS");
        cout << "Pizza list: missing function call" << endl;
        system("PAUSE");
        phone_status_ui(0);
        //remove toppings
    } else if(ret_val == 3) {
        system("CLS");
        cout << "Topping list: missing function call" << endl;
        system("PAUSE");
        phone_status_ui(0);
        //see all toppings
    }
}

void UI::clerk_selector(bool selector) {
    ret_val = clerk_menu.menuUI(0);

    if(ret_val == 99) {
        print_login_selector(0);
        ///Returns to User selector

    } else if(ret_val == 1) {
        cout << "New order function" << endl;
        system("PAUSE");
        clerk_selector(1);
        ///New order menu

    } else if(ret_val == 2) {
        cout << "Get all current orders" << endl;
        system("PAUSE");
        clerk_selector(0);
        ///To topping menu

    } else if(ret_val == 3) {
        ret_val = clerk_order_menu.menuUI(0);
        clerk_status_ui(ret_val);
        clerk_selector(0);
        ///To order completion menu

    } else if(ret_val == 4) {
        ret_val = clerk_status_menu.menuUI(0);
        clerk_status_ui(ret_val);
        clerk_selector(0);
        ///To size menu
    }

}

void UI::clerk_status_ui(int ret_val) {
    if(ret_val == 99) {
        clerk_selector(0);
        //Go one level up, to manager menu
    } else if(ret_val == 1) {
        system("CLS");
        cout << "Current orders: missing function call" << endl;
        system("PAUSE");
        clerk_status_ui(0);
        //Add toppings
    } else if(ret_val == 2) {
        system("CLS");
        cout << "Pizza list: missing function call" << endl;
        system("PAUSE");
        clerk_status_ui(0);
        //remove toppings
    } else if(ret_val == 3) {
        system("CLS");
        cout << "Topping list: missing function call" << endl;
        system("PAUSE");
        clerk_status_ui(0);
        //see all toppings
    }
}

void UI::customer_selector(bool selector) {
    ret_val = customer_menu.menuUI(0);

    if(ret_val == 99) {
        print_login_selector(0);
        ///Returns to User selector

    } else if(ret_val == 1) {
        cout << "New order" << endl;
        system("PAUSE");
        customer_selector(0);
        ///New order menu

    } else if(ret_val == 2) {
        cout << "See current order status" << endl;
        system("PAUSE");
        customer_selector(0);
        ///To topping menu

    } else if(ret_val == 3) {
        cout << "Pizza list" << endl;
        system("PAUSE");
        customer_selector(0);
        ///To order completion menu

    } else if(ret_val == 4) {
        cout << "Toppings list" << endl;
        system("PAUSE");
        customer_selector(0);
        ///To size menu
    }
}

