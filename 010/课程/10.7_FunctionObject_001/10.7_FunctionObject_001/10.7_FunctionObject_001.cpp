// 10.7_FunctionObject_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//用一般函数充当函数对象。

#include <iostream>
#include <numeric>
using namespace std;

template<class T>
T mult(T x, T y)
{
    return x * y;
}

int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int N = sizeof(a) / sizeof(int);
    //这里的mult<int>也可以写为&mult。
    cout << "The result by multipling all elements in a is " << accumulate(a, a + N, 1, mult<int>) << "." << endl;
}