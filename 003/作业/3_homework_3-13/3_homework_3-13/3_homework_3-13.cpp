// 3_homework_3-13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Fib(int n)
{
	if (n == 1 || n == 2)
	{			
		return 1;
	}
	else
	{
		cout << "Fib(" << n << ") calls Fib(" << n-1 << ") and Fib(" << n-2 << ")\n";
		cout << "---------------------\n";
		int a = Fib(n - 1);
		int b = Fib(n - 2);
		cout << "Fib(" << n - 1 << ") returns " << a << endl;
		cout << "Fib(" << n - 2 << ") returns " << b << endl;
		cout << "Fib(" << n << ") returns " << a + b << endl;
		cout << "---------------------\n";
		return a + b;
	}
}

int main()
{
	cout << "Please input an integer number: ";
	int n;
	cin >> n;
	cout << "The Fibonacci sum is " << Fib(n) << endl;
}

