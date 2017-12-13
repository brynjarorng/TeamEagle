#include <iostream>
#include <typeinfo>
using namespace std;

class Kalli
{
public:
	string o;
private:
	string h;
};
class Salli
{
public:
	string o;
private:
	string h;
};
int main ()
{
	Kalli kalli;
	Salli joi;
	string t = typeid(joi).name();
	cout << t;
	
	return 0;
}
