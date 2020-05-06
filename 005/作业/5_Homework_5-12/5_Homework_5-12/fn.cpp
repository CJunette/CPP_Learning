#include <iostream>
using namespace std;

void fn1()
{
	static int n = 0;
	n++;
	cout << n << endl;
}