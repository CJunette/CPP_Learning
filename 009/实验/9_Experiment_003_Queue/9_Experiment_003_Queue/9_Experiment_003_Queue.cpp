// 9_Experiment_003_Queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Queue.h"

int main()
{
    Queue<int> que;
	for(int i = 0; i < 5; i++)
	{
		que.insert(i);
	}
	for(int i = 0; i < 5; i++)
	{
		cout << que.remove() << " ";
	}
	cout << endl;
}
