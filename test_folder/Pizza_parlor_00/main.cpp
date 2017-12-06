#include <iostream>
#include "OrderHandler.h"
#include "Pizza.h"
#include "UI/Sales/order_functions.h"
#include <stdlib.h>
#include "ManagerUIFunctions.h"
using namespace std;



int main()
{
    //set_shortcut();
    create_topping();
    ToppingsRepo repo;

    vector<Toppings> top = repo.test_read_vector();


    Toppings t;

    for (int i = 0; i < top.size() ; i++) {
        t = top[i];
        cout << t.get_name()  << " " << t.hotkey() << t.hotnum() << endl;
    }

    return 0;
}

