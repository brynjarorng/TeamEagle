#ifndef UITEMPLATE_H
#define UITEMPLATE_H

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




class UITemplate
{
    public:
        UITemplate();

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

#endif // UITEMPLATE_H
