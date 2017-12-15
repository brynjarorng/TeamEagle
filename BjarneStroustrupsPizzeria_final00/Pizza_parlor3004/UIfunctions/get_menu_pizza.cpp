#include "get_menu_pizza.h"

#include "add_toppings.h"

using namespace std;


Pizza get_menu_selection(char& s) {

    Pizza selection;

    p_print_while_not_digits(selection, s);

    return selection;

}

void p_print_while_not_digits(Pizza& selection, char& s) {

    Pizza pizza;
    sort_by sort = alph_asc;
    string input;
    Print print;

    print.set(4, price, head_and_index, pizz);
    print.prompt_user(true);
    Pizza temp;
    bool exit = false;
    while (exit == false) {

        clear();
        print.get(current_screen);

        cout << "\nEnter the number of pizza to be selected (b to go back): ";
        getline(cin, input, '\n');

        if(input[0] == 'b') {
            break;
        }
        if (isdigit(input[0])) {

            sort = print.get_sort_order();
            selection = get_selected_pizza(char_to_int(input[0]), sort);
            break;
        }
        if (input[0] == 'n')
            print.get(next_screen);
        if (input[0] == 'a')
            print.get(a_to_z);
        if (input[0] == 'd')
            print.get(z_to_a);
        if (input[0] == 'p')
            print.get(previous_screen);
        if (input[0] == 'l')
            print.get(price_from_low);
        if (input[0] == 'h')
            print.get(price_from_high);

            clear();
           print.get(current_screen);
    }
    s = input[0];
}


void print_pizza_selection(vector<Pizza>& selection) {
    Print print;

    print.print_input(selection);

}
Pizza get_selected_pizza(int index, sort_by order) {

    Pizza pizza = get_sorted_pizza_at( (index), order );
    return pizza;
}

bool p_pizza_on_list(Pizza pizza, vector<Pizza> pizz) {

    for (int i = 0; i < pizz.size(); i++) {
        if (pizza.get_name() == pizz[i].get_name()) {
            return true;
        }
    }
    return false;
}
void remove_pizza(vector <Pizza>& pizza) {

    int range = pizza.size();

    string input;
    clear();
    Print print;
    print.set(5, alph_asc, price, indexed, pizz);
    print.pizza_settings(true, false);
    print.print_input(pizza);

    cout << "Which pizza do you wish to remove? ";
    cin >> ws;

    getline(cin, input, '\n');

    while (!isdigit(input[0]) || input[0] < 0 || input[0] > pizza.size() ) {

            cout << "Not on list!, try again: ";
            print.print_input(pizza);
            cin >> ws;
            getline(cin, input, '\n');

            cout << "Remove?: " << pizza[input[0]].get_name()
            << " (y/n) or c to cancel \n> ";

            cin >> input;
            if (input[0] == 'c') {
                break;
            }
    }
    pizza.erase(pizza.begin() +(input[0] - 1));

    if (pizza.size() > 0) {
        cout << "These are the selected pizza: \n";
        print.print_input(pizza);
    }
    else {
        cout << "No pizza selected for current pizza" << endl;
    }
}

vector<Pizza> new_pizza_list(const vector<int>& digits, const vector<Pizza> pizza) {

    vector<Pizza> temp;
    int true_count = 0;

    for (int i = 0; i < pizza.size(); i++) {
        for (int j = 0; j < digits.size(); j++) {
            if (i != digits[j]) {
                true_count++;
            }
        }
        if (true_count == digits.size()) {
            temp.push_back(pizza[i]);
        }
        true_count = 0;
    }
    return temp;
}
