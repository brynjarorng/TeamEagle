#ifndef STORECLERK_H
#define STORECLERK_H


class StoreClerk
{
    public:
        StoreClerk();
        void store_menu(bool run);
        char lower(char instr);
        void terminate();

    private:
        LoginUI lUI;
        bool select;
        ToppingsHandler handler;
};

#endif // STORECLERK_H
