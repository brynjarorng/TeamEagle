#ifndef PizzaBottomREPO_H
#define PizzaBottomREPO_H

#include "PizzaBottom.h"
#include <fstream>
#include <vector>


class PizzaBottomRepo {
    public:
        PizzaBottomRepo();
        vector<PizzaBottom> read();
        void write(PizzaBottom& pizza_size);
        void overwrite(vector<PizzaBottom> pizza_sizes);
        int get_list_count() const;
        //Returns the size of the list.

    private:
        PizzaBottom pizza_size;
        PizzaBottom* list;
        int list_count;

};

#endif // PizzaBottomREPO_H
