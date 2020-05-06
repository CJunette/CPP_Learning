// 5_Homework_5-12.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int n;

void fn1();

int main()
{
    n = 0;
	for (int i = 0; i < 10; i++)
	{
		fn1();
	}
    cout << n << endl;
}

