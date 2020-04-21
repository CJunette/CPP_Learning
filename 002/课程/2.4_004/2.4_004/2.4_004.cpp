// 2.4_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int n, residual;
	
	cout << "Please input a number:" << endl;
	cin >> n;
	cout << "The reverse number is:" << endl;

	//This is an easier way to output if the input is an positive number.
	/*
	do
	{
		residual = n % 10;
		cout << residual;
		n /= 10;

	} while ( n != 0 );
	*/
	
	
	int newnum = 0;
	do
	{
		residual = n % 10;
		newnum *= 10;
		newnum += residual;
		n /= 10;
	} while ( n != 0 );
	cout << newnum << endl;
	
	
	cout << endl;
}

