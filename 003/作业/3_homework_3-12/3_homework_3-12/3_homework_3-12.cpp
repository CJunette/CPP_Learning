// 3_homework_3-12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int sumToZero(int n)
{
	if (n == 0)
	{
		cout << n;
		return n;
	}
	else
	{
		cout << n << " + ";
		return n + sumToZero(n - 1);
	}
}

int main()
{
	cout << "Please input an integer number: ";
	int n;
	cin >> n;
	int sum = sumToZero(n);
	cout << " = " << sum << endl;
}

