// 10_Homework_10-17-2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/bind.hpp>
#include <vector>
using namespace std;

int main()
{
    int intArr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
    const int N = sizeof(intArr) / sizeof(int);
    vector<int> a(intArr, intArr + N);
    vector<int>::iterator iter = find_if(a.begin(), a.end(), bind(greater<int>(), _1, 40));
    if(iter == a.end())
    {
        cout << "No element greater than 40." << endl;
    }
    else
    {
        cout << "First element greater than 40 is " << *iter << endl;
    }
}