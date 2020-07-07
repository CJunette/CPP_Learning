// 10_Homework_10-17-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/lambda/lambda.hpp>
#include <vector>
using namespace std;

int main()
{
    int intArr[] = { 30, 90, 10, 40, 70, 50, 20, 80 };
    const int N = sizeof(intArr) / sizeof(int);
    vector<int> a(intArr, intArr + N);
    vector<int>::iterator iter = find_if(a.begin(), a.end(), boost::lambda::_1 > 40);
    if(iter == a.end())
    {
        cout << "No element greater than 40." << endl;
    }
    else
    {
        cout << "First element greater than 40 is " << *iter << endl;
    }
}