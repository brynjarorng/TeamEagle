#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	vector<int> test;
	for (int i = 0; i < 10; i++) {
		test.push_back(i);
	}
	for (int i = 0; i < test.size();i++) {
		cout << test.at(i);
	}
	test.erase (test.begin()+ 2);
	cout << "----------------" << endl;
	for (int i = 0; i < test.size();i++) {
		cout << test.at(i);
	}
	test.erase (test.begin()+ 2);
	cout << "----------------" << endl;
	for (int i = 0; i < test.size();i++) {
		cout << test.at(i);
	}
}
