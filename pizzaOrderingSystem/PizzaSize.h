#ifndef PIZZASIZE_H
#define PIZZASIZE_H



class PizzaSize
{
    public:
        PizzaSize();
        PizzaSize(int pizza_size, int price);
        void set_price(int price);

    private:
        int pizza_size();
        int price;
};

#endif // PIZZASIZE_H
