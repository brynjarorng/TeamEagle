#include "sorting_function.h"

vector <Toppings> toppings_sorted(sort_by a) {

    switch(a) {

        case alph_asc:
            return toppings_alph_sort_asc();
            break;

        case alph_desc:
            return toppings_alph_sort_desc();
            break;

        case price_asc:
            return toppings_price_sort_asc();
            break;
        case price_desc:
            return toppings_price_sort_desc();
            break;
        default:
            Toppings top;
            top.set_name("Default");
            vector<Toppings> default_v;
            return default_v;
            break;
    }
}

 Pizza get_sorted_pizza_at(int index, sort_by a) {

    if ( index > pizza_sorted(a).size() || index <= 0 ) {
        throw InvalidSize();
    }
    return pizza_sorted(a)[index];
 }



vector <Toppings> toppings_price_sort_desc() {

    ToppingsRepo repo;
    vector<Toppings> sort = repo.read();
    int max;
    Toppings temp;
    max = 0;
    for (unsigned int i = 0; i < sort.size() - 1; i++) {
        for (unsigned int j = i + 1; j < sort.size() + 1; j++) {
            if (sort[j].get_price() > sort[max].get_price()) {
                max = j;
            }
            temp = sort[max];
            sort[max] = sort[i];
            sort[i] = temp;
        }
    }
    return sort;


}
string to_lower(string in) {


    for (unsigned int i = 0; i < in.size(); i++) {
        if ( isupper(in[i])) {
            in[i] = tolower(in[i]);
        }
    }
    return in;
}

int string_comp (string one, string two) {//returns 1 if one, 2 if 2, 0 if same.

    one = to_lower(one);
    two = to_lower(two);
    int n = one.size();
    if (one < two) {
        n = two.size();
    }
    int i = 0;
    int j = 0;
    char one_c = one[i], two_c = two[i];
    for (j = 0; j < n; j++) {
        while (one[i] == two[i] && i <= n) {
            i++;
            one_c = one[i];
            two_c = two[i];
        }
        if (one_c < two_c && i < n) {
            return 1;
        }
        else if (i < n) {
            return 2;
        }
    }
    return 0;
}

vector <Toppings> toppings_price_sort_asc() {

    ToppingsRepo repo;
    vector<Toppings> sort = repo.read();
    int min;
    Toppings temp;

    for (unsigned int i = 0; i < sort.size() - 1; i++) {
        min = i;
        for (unsigned int j = i + 1; j < sort.size(); j++) {
            if (sort[j].get_price() < sort[min].get_price()) {
                min = j;
            }
            temp = sort[min];
            sort[min] = sort[i];
            sort[i] = temp;
        }
    }
    return sort;
}

bool one_is_greater(string one, string two) {

    if ( string_comp(one, two) == 1) {
        return true;
    }
    return false;
}

vector <Toppings> toppings_alph_sort_asc() {


    ToppingsRepo repo;
    vector<Toppings> sort = repo.read();
    Toppings temp;

    for (unsigned int i = 1; i < sort.size(); i++) {
        for (unsigned int j = 0; j < sort.size() - i; j++) {
            if ( !one_is_greater(sort[j].get_name(), sort[j + 1].get_name())) {
                temp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
            }
        }
    }
    return sort;
}

vector <Toppings> toppings_alph_sort_desc() {

    ToppingsRepo repo;
    vector<Toppings> sort = repo.read();
    Toppings temp;

    for (unsigned int i = 1; i < sort.size(); i++) {
        for (unsigned int j = 0; j < sort.size() - i; j++) {
            if ( one_is_greater(sort[j].get_name(), sort[j + 1].get_name())) {
                temp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
            }
        }
    }
    return sort;
}
vector <Pizza> pizza_sorted(sort_by a) {

        switch(a) {

        case alph_asc:
            return pizza_alph_sort_asc();
            break;

        case alph_desc:
            return pizza_alph_sort_desc();
            break;

        case price_asc:
            return pizza_price_sort_asc();
            break;
        case price_desc:
            return pizza_price_sort_desc();
            break;
        default:
            Pizza pizza;
            pizza.set_name("Default");
            vector<Pizza> default_v;
            return default_v;
            break;
    }
}
vector <Pizza> pizza_price_sort_desc() {
    PizzaRepo repo;
    vector<Pizza> sort = repo.read();
    int min;
    Pizza temp;

    for (unsigned int i = 0; i < sort.size() - 1; i++) {
        min = i;
        for (unsigned int j = i + 1; j < sort.size(); j++) {
            if (sort[j].get_price() < sort[min].get_price()) {
                min = j;
            }
            temp = sort[min];
            sort[min] = sort[i];
            sort[i] = temp;
        }
    }
    return sort;
}
vector <Pizza> pizza_price_sort_asc() {

    PizzaRepo repo;
    vector<Pizza> sort = repo.read();
    int max;
    Pizza temp;
    max = 0;
    for (unsigned int i = 0; i < sort.size() - 1; i++) {
        for (unsigned int j = i + 1; j < sort.size(); j++) {
            if (sort[j].get_price() > sort[max].get_price()) {
                max = j;
            }
            temp = sort[max];
            sort[max] = sort[i];
            sort[i] = temp;
        }
    }
    return sort;
}


vector <Pizza> pizza_alph_sort_desc() {

    PizzaRepo repo;
    vector<Pizza> sort = repo.read();
    Pizza temp;

    for (unsigned int i = 1; i < sort.size(); i++) {
        for (unsigned int j = 0; j < sort.size() - i; j++) {
            if ( one_is_greater(sort[j].get_name(), sort[j + 1].get_name())) {
                temp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
            }
        }
    }
    return sort;
}
vector <Pizza> pizza_alph_sort_asc() {

    PizzaRepo repo;
    vector<Pizza> sort = repo.read();
    Pizza temp;

    for (unsigned int i = 1; i < sort.size(); i++) {
        for (unsigned int j = 0; j < sort.size() - i; j++) {
            if ( !one_is_greater(sort[j].get_name(), sort[j + 1].get_name())) {
                temp = sort[j];
                sort[j] = sort[j + 1];
                sort[j + 1] = temp;
            }
        }
    }
    return sort;
}
