// 3.4_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Factorial(int a)
{	
	if ( a > 1 )
	{		
		a *= Factorial(a - 1);
	}
	
	return a;

}

int main()
{
	cout << "Please input a number: ";
	int a;
	cin >> a;
	cout << "The factorial is " << Factorial(a) << " .\n";
}
