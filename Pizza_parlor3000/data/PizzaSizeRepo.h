#ifndef PIZZASIZEREPO_H
#define PIZZASIZEREPO_H

#include "PizzaSize.h"
#include <fstream>
#include <vector>


class PizzaSizeRepo {
    public:
        PizzaSizeRepo();
        vector<PizzaSize> read();
        void write(PizzaSize& pizza_size);
        void overwrite(vector<PizzaSize> pizza_sizes);
        int get_list_count() const;
        //Returns the size of the list.

    private:
        PizzaSize pizza_size;
        PizzaSize* list;
        int list_count;

};

#endif // PIZZASIZEREPO_H
