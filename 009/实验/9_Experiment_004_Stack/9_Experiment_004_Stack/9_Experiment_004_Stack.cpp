// 9_Experiment_004_Stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Stack.h"
using namespace std;

int main()
{
    Stack<int> s;
	for(int i = 0; i < 5; i++)
	{
		s.push(i);
	}
	for(int i = 0; i < 5; i++)
	{
		cout << s.pop() << " ";
	}
	cout << endl;
}
