// 10_Homework_10-1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> s;
	int length = 40;
	for(int i = 0; i < length; i++)
	{
		s.push_back(i);
		cout << "index: " << i << "\tcapacity: " << s.capacity() << endl;
	}
}