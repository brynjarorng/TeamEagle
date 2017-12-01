#include "MainUI.h"
#include <iostream>
#include "ManagerUI.h"

using namespace std;

    ManagerUI manager("Menu:", "Pizza information", "Toppings", "Pizza size", "Make a new pizza");
    ManagerUI topping_menu("Toppings:", "Add toppings", "Remove toppings", "See all toppings");
    ManagerUI info_menu("Info:", "Toppings", "Pizzas", "Pizza sizes");
    ManagerUI new_pizza_menu("Create a new pizza:", "Create pizza", "Remove pizza", "See all pizas");
    //global decl. of UI elements

MainUI::MainUI()
{
    run = 0;
}

void MainUI::print_selector(bool run) {
    system("CLS");

    char selector = ' ';

    cout << "Welcome to pizza & co." << endl << endl;

    cout << "----LOGIN SELECTOR----" << endl;
    cout << "(m) Manager" << endl;
    cout << "(b) Baker" << endl;
    cout << "(t) Telephone operator" << endl;
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
        system("CLS");
        cout << "Work in progress: BAKER!" << endl;
        system("PAUSE");
        print_selector(0);
        break;
    case 't':
        system("CLS");
        cout << "Work in progress: TELEPHONE!" << endl;
        system("PAUSE");
        print_selector(0);
        break;
    case 's':
        system("CLS");
        cout << "Work in progress: SALES!" << endl;
        print_selector(0);
        system("PAUSE");
        break;
    case 'q':
        terminate();
        break;
    default:
        system("CLS");
        print_selector(1);
        break;
    }

}

char MainUI::lower(char instring) {
    StdInput s;
    instring = s.to_lower_case(instring);
    return instring;
}

void MainUI::terminate(){
    system("CLS");
    char cont;

    cout << "Are you sure you want to quit (y/n)? ";
        cin >> cont;
        cont = lower(cont);

    if(cont == 'y'){
        cout << "Good Bye!" << endl;
        exit(0);
    }
    print_selector(0);
    //Double check if user wants to quit, else runs the
    //manager UI again
}

void MainUI::manager_selector(bool selector) {
ret_val = manager.menuUI(0);
        if(ret_val == 99) {
            print_selector(0);
            ///Returns to User selector

        } else if(ret_val == 1) {
            ret_val = info_menu.menuUI(0);
            info_creator(ret_val);
            ///To pizza info menu

        } else if(ret_val == 2) {
            ret_val = topping_menu.menuUI(0);
            topping_creator(ret_val);
            ///To topping menu

        } else if(ret_val == 3) {
            ///To size menu

        } else if(ret_val == 4) {
            ///To create a new pizza menu
        }


}

void MainUI::info_creator(int ret_val) {
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

void MainUI::topping_creator(int ret_val) {
    if(ret_val == 99) {
        manager_selector(0);
        //Go one level up, to manager menu
    } else if(ret_val == 1) {
        cout << "Add toppings" << endl;
        handler.create_topping();
        manager_selector(0);
        //Add toppings
    } else if(ret_val == 2) {
        system("CLS");
        cout << "remove toppings";
        system("PAUSE");
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

void MainUI::pizza_creator(int ret_val) {
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
        handler.print_toppings();
        system("PAUSE");
        manager_selector(0);
        //see all toppings
    }
}
