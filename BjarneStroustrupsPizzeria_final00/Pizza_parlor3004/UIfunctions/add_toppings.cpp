#include "add_toppings.h"

using namespace std;

vector<int> input_to_int(string in) {

    vector<int> in_to_int;
    string first;
    int converted;

    bool exit = false;

    while (!exit) {

        exit = first_without_whitespace(in, first);
            if (isdigit(first[0])) {
                in_to_int.push_back(stoi(first));
                first = "";
            }
    }

    return in_to_int;
}

bool longer_than_eigth(string in) {

    string first = "";
    bool exit = false;
    while (!exit) {
        if(first_without_whitespace(in, first)) {
            return true;
        }
    }
    return false;
}

bool first_without_whitespace(string& rest_of_string, string& first) {

    while (rest_of_string[0] == ' ') {
        rest_of_string.erase(0, 1);
    }
    first = "";
    int i = 0;
    while (isdigit(rest_of_string[i])) {
        first += rest_of_string[i];
        i++;
    }
    rest_of_string.erase(0, i);
    return (rest_of_string.empty());
}

vector<Toppings> add_topping_to_order() {

    string input;

    vector<int> digits;
    vector<Toppings> toppings_sel;

    bool loop = true;
    while(loop == true) {

        sort_by sort_order = alph_asc;
        print_while_not_digits(digits, sort_order);
        //get the digits when entered.Else keeps printing.

        add_selected_toppings(toppings_sel, digits, sort_order);
        //add the toppings selected
        Pizza pizza;

        //bool max_toppings = false;
       // if (toppings_sel.size() > pizza.get_max_toppings()) {
           // max_toppings = true;
       // }
        //if (max_toppings) {
         //   cout << "Maximum toppings reached, either remove a topping, quit,\n"
              //   << "or check out with the current selection" << endl;
       // }
        if (toppings_sel.size() != 0) {
            clear();
            cout << "These are the selected toppings: " << endl;
        }
        else {
            break;
        }

        print(toppings_sel, false);

        bool change;
        do {
            cout << "Press: \(c) to change, (m) to add more,"
                 <<" or (q) if finished:"
                 << endl;

            input = "";
            cin >> input;
      //  if (max_toppings && input[0] != 'q' && input != )
            if (input[0] == 'c') {
            remove_topping(toppings_sel);
                change = true;
            }
            if (input[0] == 'm') {
                loop = true;
                change = false;
            }
            if (input[0] == 'q') {
                change = false;
                loop = false;
            }
            if (input[0] == 'p') {
                change = false;
                loop = true;
            }
        } while (change == true);
    }
    return toppings_sel;
}
bool topping_on_list(Toppings top, vector<Toppings> toppings) {

    for (int i = 0; i < toppings.size(); i++) {
        if (top.get_name() == toppings[i].get_name()) {
            return true;
        }
    }
    return false;
}
void add_selected_toppings(vector<Toppings>& add, vector<int> digits, sort_by sort_order) {

    ToppingsHandler toppingshandler;
    vector<Toppings> toppings = toppings_sorted(sort_order);
    Toppings temp;

    for (int i = 0; i < digits.size(); i++) {
        temp = toppings[ digits[i]];
        if ( !topping_on_list(temp, add) && !temp.get_name().empty() ) {
            add.push_back(temp);
        }
    }
}
void t_next_screen(int& a, int& b, int nr_elements) {

    ToppingsHandler toppingshandler;
    int toppings_list_count = toppingshandler.get_topping_list_size();

    a = b;
    b =  nr_elements + b;

    if (b > toppings_list_count) {
    b = toppings_list_count;

        if (a >= toppings_list_count) {
            t_reset_b(b, nr_elements);
            a = 0;
        }
    }
}
void t_reset_b(int& b, int print_nr_elements) {

    ToppingsHandler handler;

    int toppings_list_count = handler.get_topping_list_size();

    if (toppings_list_count >= print_nr_elements) {
        b = print_nr_elements;
    }
    else {
        b = toppings_list_count;
    }
}

void t_previous_screen(int& a, int& b, int nr_elements) {

    ToppingsHandler toppingshandler;
    int nr_toppings = toppingshandler.get_topping_list_size();

    b = a;
    a = a - nr_elements ;

    if (a < 0) {
        a = 0;
        t_reset_b(b, nr_elements);
        while (b < nr_toppings) {
            t_next_screen(a, b, nr_elements);
        }
    }
}

string which_order(sort_by& sort) {

    if (sort == alph_desc) {
        return "(a) Ascending order";
    }
    if (sort == alph_asc) {
        return "(d) Descending order";
    }
    if (sort == price_desc) {
        return "(h) highest price";
    }
    if (sort == price_asc) {
        return "(l) lowest price";
    }
}

void print_while_not_digits(vector<int>& digits, sort_by& sort_order) {

    ToppingsHandler toppingshandler;

    int nr_elements = 10;//How many toppings should be printed at a time.
    int a = 0;
    int b;
    t_reset_b(b, nr_elements);

    string input;

    bool exit = false;
    while (exit == false) {

        system("clear");

        print_toppings_selection(a, b, sort_order);
        //Print the range from a to b.
       // t_print_lines(20);
        cout << "To select toppings, insert the numbers";
        cout <<  "\ncorresponding to the toppings followed by a whitespace.\n";
        cout << "\n(n) Next page ";
        cout << "\t" << which_order(sort_order);
        cout <<  "\t(q) to quit " << endl << ">";

        cin >> ws;
        getline(cin, input, '\n');
        if(input[0] == 'q') {
            break;
        }

        if (isdigit(input[0])) {

            exit = number_selected (input, digits);//If the digits are valid,
                                                  //we will exit.
        }

        switch (input[0]) {
            case 'n': t_next_screen(a, b, nr_elements);
            break;

            case 'a':
                a = 0;
                t_reset_b(b, nr_elements);
                sort_order = alph_asc;
            break;

            case 'd':
                  a = 0;
                  t_reset_b(b, nr_elements);
                  sort_order = alph_desc;
            break;

            case 'b': t_previous_screen(a, b, nr_elements);
            break;
        }
    }
}

void print_toppings_selection(int from, int to, sort_by& sorting_order) {

    vector<Toppings> toppings = toppings_sorted(sorting_order);

   // t_print_lines(20);

    cout << "Total toppings: " << toppings.size() << endl;
    cout << "Toppings displayed: " << from + 1
         << " to " << to  << endl;

    //t_print_lines(20);

    string name;
    for (int i = from; i < to; i++) {

        cout  << "(" << i + 1 << ") " << toppings[i].get_name()
              << "  $"  << toppings[i].get_price() << endl;
    }
}

void remove_topping(vector <Toppings>& toppings) {

    int range = toppings.size();

    string input;
    system("clear");
    print(toppings, true);
    cout << "Which toppings do you wish to remove? ";
    cin >> ws;

    getline(cin, input, '\n');

    while (!validate_number(input, range)) {

        cout << "Not on list!, try again: ";
        print(toppings, true);
        cin >> ws;
        getline(cin, input, '\n');
    }
    vector<int> digits = input_to_int(input);
    all_digits_minus_one(digits);

    for (int i; i < digits.size(); i++) {

        cout << "Remove?: " << toppings[digits[i]].get_name()
            << " (y/n) or c to cancel \n> ";

        cin >> input;
        if (input[0] == 'c') {
            digits.clear();
            break;
        }
        if (input[0] == 'n') {
            digits.erase(digits.begin() + i);
        }
    }

    toppings = new_toppings_list(digits, toppings);

    if (toppings.size() > 0) {
        cout << "These are the selected toppings: \n";
        print(toppings, false);
    }
    else {
        cout << "No toppings selected for current pizza" << endl;
    }
}

vector<Toppings> new_toppings_list(const vector<int>& digits, const vector<Toppings> toppings) {

    vector<Toppings> temp;
    int true_count = 0;

    for (int i = 0; i < toppings.size(); i++) {
        for (int j = 0; j < digits.size(); j++) {
            if (i != digits[j]) {
                true_count++;
            }
        }
        if (true_count == digits.size()) {
            temp.push_back(toppings[i]);
        }
        true_count = 0;
    }
    return temp;
}

void no_whitespace(vector<char>& in) {

    vector<char> temp;

    for (int i = 0; i < in.size(); i++) {
        if (in[i] != ' ') {
            temp.push_back(in[i]);
        }
    }
    in = temp;
}

void print(vector<Toppings> in, bool indexed) {

    for (int i = 0; i < in.size(); i++) {

        if (indexed == true) {
            cout << "(" << i + 1 << ") ";
        }
        else {
            cout << "*";
        }
        cout << in[i].get_name() << endl;
    }
}

int char_to_int(char in) {

    int n = static_cast<int>(in)
          - static_cast<int>('0');
}

vector<char> string_to_char(string in) {

    vector<char> digits;
    for (int i = 0; i < in.size(); i++) {
            digits.push_back(in[i]);
        }

    no_whitespace(digits);

    return digits;
}


bool validate_number(string digits, int range) {

    //if (digits.size() > 8) {
      //  return false;
    //}
   // if(longer_than_eigth(digits)) {
     //   return false;
    //}

    for (int i = 0; i < digits.size(); i++) {


        if ( !isdigit(digits[i]) && digits[i] != ' ') {
             return false;
        }
    }

    vector <int> num = input_to_int(digits);

    for (int i = 0; i < num.size(); i++) {
         if (num[i] < 1 || num[i] > range) {

            return false;
    }

    Pizza pizza;
    if (num.size() > pizza.get_max_toppings()) {
        return false;
    }

    return true;
    }
}
bool number_selected (string in, vector<int>& digits) {

    ToppingsHandler handler;
    int range = handler.get_topping_list_size();
    if ( !validate_number(in, range) ) {

        cout << "\nWrong input!, either wrong number was input,\n too many toppings selected"
             << " or the input was not a number.\n" << endl;
        pause_screen();

        return false;
    }

    digits = input_to_int(in);
    for (int i = 0; i < digits.size(); i++) {
    }
    all_digits_minus_one(digits);

        return true;
}

void all_digits_minus_one(vector<int>& digits) {

    for (int i = 0; i < digits.size();i++) {
        digits[i]--;
    }
}


