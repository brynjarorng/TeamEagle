#include <iostream>
#include "fstreamClass.h"
using namespace std;

int main()
{
	FstreamClass test;

	test.write_toppings();

	test.read_toppings();

	test.print_list();
	

    return 0;
}
