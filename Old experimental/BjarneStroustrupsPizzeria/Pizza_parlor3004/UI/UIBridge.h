#ifndef UIBridge_H
#define UIBridge_H

#include "OrderHandler.h"
#include "PizzaHandler.h"
#include "ToppingsHandler.h"
#include "PizzaBottomHandler.h"
#include "LocationHandler.h"
#include "SideOrdersHandler.h"
#include "print_functions.h"
#include "InvalidInputException.h"
#include "order_functions.h"
#include "baker_functions.h"




class UIBridge
{
    public:
        UIBridge();

        OrderHandler orderhandler;
        PizzaHandler pizzahandler;
        ToppingsHandler toppingshandler;
        PizzaBottomHandler bottomhandler;
        LocationHandler locationhandler;
        SideOrdersHandler sideorderhandler;
        void choose_location();

    protected:

    private:
};

#endif // UIBridge_H
