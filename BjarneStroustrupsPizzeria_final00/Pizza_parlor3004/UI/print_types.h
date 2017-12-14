#ifndef PRINT_TYPES_H_INCLUDED
#define PRINT_TYPES_H_INCLUDED

enum print_action{next_screen, previous_screen, current_screen,
                  a_to_z, z_to_a, price_from_high, price_from_low};

enum print_item{top, pizz, ord, none};
enum print_style{header, indexed, head_and_index, none_};
enum Price :bool {price = true, no_price = false};


#endif // PRINT_TYPES_H_INCLUDED
