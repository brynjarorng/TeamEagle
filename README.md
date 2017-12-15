# Team Eagle

The Team Eagle project is a project that mimics the functionality of a basic pizza ordering system. Project was created for the 3 week course Verklegt námskeið 1 in Reykjavík University.

The program is a 5 faced system, for a manager, storeclerk, telephone operator, costumer and baker. 

# Getting Started
 - CodeBlocks must be installed to open project file
 - c++ compiler with the C++11 ISO standar flag (for stoi() to work)
 - If you are using the mingw compiler you need to update some files to make stoi() work correctly: http://tehsausage.com/mingw-to-string
 
# Functionality
- Manager
    - See list of toppings
    - See all menu pizzas
    - See all pizza bottoms (sizes)
    - See all locations
    - Add/remove toppings
    - Add/remove pizza bottms (sizes)
    - Add/remove locations
    - Add new menu pizza
    - Archive orders from the selected location
    - Read arhcived orders from the selected location
- Baker
    - Select a location (his actions are relative to that location)
    - Gets list of pizzas ordered pizzas and can change their process status.
- Telephone operator
    - Make new order for location of choice
    - See all orders in progress for location of choice
    - See all pizzas on menu
    - See all toppings
    - Get all orders (unarchived)
- Sales clerk
    - Select a location (his actions are relative to that location)
    - Make a new order
    - See all orders in progress
    - See all pizzas in menu
    - See all toppings
    - Find an order by ordernumber and mark it paid/delivered
    - Browse through active orders and mark them paid/delivered
    - See all orders (unarchived)
- Costumer
    - Select a location (his actions are relative to that location)
    - Make new order
    - See all pizzas on menu
    - See available toppings
    - See order status by order number

# Fulfilled requirements
- Base bare requirements
    - Menu listing possible operations
    - Register a price for a base pizza (When you add new bottom/size)
    - Register new toppings and their prices.
    - Register ordered pizzas and show total price. (Pizzas are registered in orders, where total price can be seen).
    - Flag pizza as paid for (Order can be flagged paid)
    - View an ordered pizza (Able to view orders by browse and search)
    - Flag as processing (baking)
    - Flag as ready (Pizzas can be flagged individually and orders are automatically flagged ready when all it's pizzas are ready)
    - Flag as delivered (Order is flagged as delivered)
    - All information stays correct when system is shut off
- Divided system 
    - System is divided to Manager, Sales, Telephone, Baker and Costumer, where each subsystem is is relative to it's location where appropriate (f.x. manager can make changes affecting all locations, wheras sales-clerk can only make changes affecting it's location).
    - Administration
        - Can register different sizes of pizza bottoms and their price (base price for pizza) and remove them.
        - Can register toppings and their prices and remove them.
        - Register specific combinations of toppings for pizza by name for menu
        - Register locations and remove them.
    - Sales (telephone operator and store clerk)
        - Register an order
        - Add pizzas to order (either menu pizza or special order)
            - Add base (size)
            - Add toppings
            - See total price per pizza
        - View total price for order
        - Register pick-up or delivery
        - Flag order as paid for (sales clerk)
        - Flag pizza for specific location (telephone operator)
        - Register comments for each order
    - Pizzaiolos (baker)
        - User picks their location 
        - Get's list of ordered pizza, only for this location
        - Only information relative to baker is printed
        - Can flag pizza in oven
        - Can flag pizza ready
    - Pick-up and delivery (store clerk)
        - User picks their location
        - View list of orders, only for this location
        - Flag order as paid for
        - Flag order as delivered
- Additions and extra functionality
    - Binary files used for all saved data
    - Binary files are read in in one operation and dumped as whole into a vector.
    - Service classes only fetch data from repo when needed, when they do they take their own copy and always make the same changes to it as the repo, so it only need to read the repo once, which should really speed the system up when it comes to the orders. (note. does not apply to sorting functions since they only deal with toppings and pizzas is lighter in progress).
    - The interface was designed with ease and comfort of the user in mind:
       - Easy navigation where the user can go back and forth and cancel operation 
         without losing his placement in the system.
        - The list of pizzas and toppings displayed are listed n at a time, where the user              can navigate the list back and forth.
            - order the list lexiograhically by ascending and descending order
            - order the list from price low to high and low to high
    - The clear screen console function is operating system dependant so our system checks what operating system user is running, and uses the corresponding clear screen argument.
    - When adding topping to an order, up to 20 topping can be added in single line from a list, making the process faster (shorthand syntax).
    - When adding a order, changes can be made to the pizza without leaving the current order. (add more toppings or remove toppings)
    - Each order must be verified before sent in.
    - When manager creates pizza for menu it prints out what the topping cost is according to price list and allows him to input another price to be added to the base price instead of the sum of toppings price. (A form of discount).
    - Manager can choose a location and archive it's move all the orders from it's (filed) list order list to a legacy file.
    - Manager can choose a location and read all it's archived orders.
    
 
# Group members
- Brynjar Örn Grétarsson
- Ívar Marrow Arnþórsson
- Viktor Sveinsson

# Credits
 - SelectionSort algorithm used in in the sorting functions in the logic layer was inspired by an algorithm found in the book Foundations of computer science (1995) by Alfred V. Aho ad Jeffrey D. Ullman (page. 33).
 - 



  