// 10_Homework_10-13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <functional>
using namespace std;

int power(int x, int y)
{
	int sum = 1;
	for(int i = 0; i < y; i++)
	{
		sum *= x;
	}
	return sum;
}

int randNum()
{
	return rand() % 10;
}

int main()
{
	srand((int)time(0));
	ostream_iterator<int> out(cout, "\t");

	vector<int> v(5);
	generate(v.begin(), v.end(), randNum);
	copy(v.begin(), v.end(), out);
	cout << endl << endl;

	vector<int> root{ 5, 5, 5, 5, 5 };
	vector<int> exponential{ 7, 7, 7, 7, 7 };	

	cout << "element ^ 5:      \t";
	transform(v.begin(), v.end(), root.begin(), out, ptr_fun((power)));
	cout << endl;

	cout << "7 ^ element:      \t";
	transform(exponential.begin(), exponential.end(), v.begin(), out, ptr_fun((power)));
	cout << endl;

	cout << "element ^ element: \t";
	transform(v.begin(), v.end(), v.begin(), out, ptr_fun((power)));
	cout << endl;
}