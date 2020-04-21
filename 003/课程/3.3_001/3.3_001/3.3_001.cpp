// 3.3_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

double Power(double a, int n);

int main()
{
	cout << Power(4, 3) << endl;
}

double Power(double a, int n)
{
	double result = 1;
	for ( int i = 0; i < n; i++ )
	{
		result *= a;
	}

	return result;
}