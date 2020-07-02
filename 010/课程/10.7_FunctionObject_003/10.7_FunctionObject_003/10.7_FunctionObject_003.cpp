// 10.7_FunctionObject_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//用STL库的标准对象multiplies来充当函数对象。

#include <iostream>
#include <numeric>
#include <functional>
using namespace std;

int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int N = sizeof(a) / sizeof(int);
    //multiplies是一个标准库中的、重载了“()”的类。
    cout << accumulate(a, a + N, 1, multiplies<int>()) << endl;
}
