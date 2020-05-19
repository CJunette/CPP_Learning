// 6_Homework_6-23.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const int N = 8;

int main()
{
    cout << "Please input " << N << " scores: " << endl;
	float sum = 0;
	int j;
	for (int i = 0; i < N; i++)
	{		
		cout << "Enter grade #" << i + 1 << ":";
		cin >> j;
		sum += j;
	}
	cout << "The average is " << sum / N << endl;
}
