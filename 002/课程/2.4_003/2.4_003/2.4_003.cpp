// 2.4_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int i = 1;
	int sum = 0;
	while ( i <= 10 )
	{
		sum += i++;
	}
	cout << "The sum is " << sum << "." << endl;
}

