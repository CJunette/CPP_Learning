// 3.4_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

double Square(double a)
{
    return a * a;
}
double Sum(double a, double b)
{
    return Square(a) + Square(b);
}

int main()
{
    cout << "Please input two number:\n";
    double a, b;
    cin >> a >> b;

    cout << "The square sum is " << Sum(a, b) << " .\n";
}

