#include <stdio.h>      /* printf */
#include <time.h>       /* time_t, time, ctime */
#include <iostream>
#include <fstream>
#include <typeinfo>
using namespace std;

int main ()
{
  time_t rawtime;

  time (&rawtime);
  printf(ctime (&rawtime));
  cout << ctime (&rawtime);

  ofstream fout;
  fout.open("times.dat", ios::binary);

  cout << typeid(ctime (&rawtime)).name() << endl;

  int size = sizeof(&rawtime) * sizeof(time_t);

  fout.write((char*)(ctime (&rawtime)), size+8);

  fout.close();


  return 0;
}
