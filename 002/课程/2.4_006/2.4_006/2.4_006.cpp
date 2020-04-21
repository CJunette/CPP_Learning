// 2.4_006.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int posNum = 0, negNum = 0, inputNum = 0;
	do
	{
		cout << "Please input a number: ";
		cin >> inputNum;
		if ( inputNum > 0 )
		{
			posNum++;
		}
		else if ( inputNum < 0 )
		{
			negNum++;
		}
		else
		{
			continue;
		}

		if ( posNum == 1 )
		{
			cout << "There is " << posNum << " positive number\n";
		}
		else
		{
			cout << "There are " << posNum << " positive numbers\n";
		}

		if ( negNum == 1 )
		{
			cout << "There is " << negNum << " negative number\n";
		}
		else
		{
			cout << "There are " << negNum << " negative numbers\n";
		}

		cout << endl;
	} while ( inputNum != 0 );
}

