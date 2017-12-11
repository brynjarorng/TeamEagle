#ifndef TEMP_ORDER_FUNC_H_INCLUDED
#define TEMP_ORDER_FUNC_H_INCLUDED

#include "LoginUI.h"
#include "sorting_function.h"
#include <string.h>
#include "ToppingsHandler.h"
#include <vector>
vector<Toppings> add_topping_to_order();
//The user enters a menu where he can select toppings from
//a list to add to a pizza that is being ordered.
void add_selected_toppings(vector<Toppings>& add, vector<int> digits, sort_by sort_order);
//adds toppings from toppings list corresponding to digits, and order of sort.
void print_while_not_digits(vector<int>& digits, sort_by& sort_order);
//Gives the user the option to select and print from a list
//of toppings. As soon as the user inputs digits, the input is validated
//and if valid the function is exited, and the digits are contained
//in the refrence digits as characters in the same order as they were input.
void some();
//To be sorted function.
void remove_topping(vector <Toppings>& toppings);
//Precondition: toppings is not empty.
//Postcondition: The user is asked to input which toppings
//she wishes to remove from the list, and that topping is now removed.
void no_whitespace(vector<char>& in);
//Precondition: in is not empty.
//Postcondition: in does not contain any whitespace characters
void print(vector<Toppings> in, bool indexed);
//Precondition: in is not empty.
//Postcondition: in[0] through in[in.size() - 1] is now printed to the screen
//each element followed by a newline. If indexed is TRUE, then for each
//element in[n], n + 1 is printed along with it to indicate the index.
int char_to_int(char in);
//Precondition: in is a character representation of a digit.
//Postcondition: the return value is the integer correspindonding
//to in.
vector<char> string_to_char(string in);
//Postcondition: The return value is a vector of size
//in.size(), where each element is a character from in, with the same
//order as in.
void previous_screen(int& a, int& b, int nr_elements);
//Prints the previous screen, range is [a, b], and nr_elements is
//elements to be printed at a time.
void next_screen(int& a, int& b, int nr_elements);
//Prints the next screen, range is [a, b], and nr_elements is
//elements to be printed at a time.
void reset_b(int& n, int print_nr_elements);
//n is set to the nr of elements that should be printed.
//If toppings_list_count is >= print_nr_elements, then n is
//set equal to print_nr_elements, else n is set equal to
//toppings_list_count.
bool validate_number(string digits, int range);
//Precondition: digits contains character representations of digits entered
//in by the user, range is the upper bound for the check.
//Postcondition: The return value is FALSE if one of the characters in the vector
//fails to be a digit. The return value is FALSE if the digits fail to be
//of from [1, range).
void print_toppings_selection(int from, int to, sort_by& sorting_order);
//Postcondition: Toppings from the database are printed to the screen,
//where the range is [from, to], and the order is determined by
//sorting_order (sorting_order can take the following values: {alph_asc, alph_desc, price_asc, price_desc}
bool number_selected (string in, vector<int>& digits);
//Poscondition: (in) is converted to digits through the string_to_char function,
//If (in) is of incorrect format or range, then the user gets an error message and
//the return value is FALSE. If the format or range is correct, then the user is asked
//if he whises to select more toppings, where the return value is TRUE if he
//does not wish to select more toppings. Otherwise the return value is FALSE.
void all_digits_minus_one(vector<int>& digits);
//Shifts all the digits one.
vector<int> input_to_int(string in);
//Converts the input to intgers and returns them in an array in the same
//order as they were read.
bool first_without_whitespace(string& rest_of_string, string& first);
//The return value is the first string without before a whitespace
//is encountered. The refrence string becomes a substring of itself excactly
//missin the returned string and the whitespace. Returns false when there is
//no substring left.
void input_is_next_screen(int& n, int& counter, sort_by& order_by);
//Sets the varibles
vector<Toppings> new_toppings_list(const vector<int>& digits, const vector<Toppings> toppings);
//Return value is a new toppins vector containing only those elements which
//are not elements indexeded at the same index as contained in digits.

#endif // TEMP_ORDER_FUNC_H_INCLUDED
