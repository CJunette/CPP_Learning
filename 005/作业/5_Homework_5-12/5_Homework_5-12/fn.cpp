#include <iostream>
using namespace std;

extern int n;

void fn()
{
	static int n;
	n++;
	cout << n << endl;
}