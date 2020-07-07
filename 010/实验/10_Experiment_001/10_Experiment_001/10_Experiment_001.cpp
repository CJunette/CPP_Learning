// 10_Experiment_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    deque<int> q;
	for(int i = 0; i < 5; i++)
	{
		q.push_back(i);
	}
	while(!q.empty())
	{
		cout << q.front() << " ";
		q.pop_front();
	}
}