// 3_homework_3-14.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

double p(int n, float x)
{
    switch (n)
    {
        case 0:
            return 1;
            break;
        case 1:
            return x;
            break;
        default:
            return ((2 * n - 1) * x * p(n - 1, x) - (n - 1) * p(n - 2, x)) / n;
            break;
    }
}


int main()
{
    int n;
    float x;
    cout << "Please input the value of n: ";
    cin >> n;
    cout << "Please input the value of x: ";
    cin >> x;
    cout << "The result is " << p(n, x) << ".\n";
}
