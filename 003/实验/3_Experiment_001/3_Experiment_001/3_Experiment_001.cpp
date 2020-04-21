// 3_Experiment_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

float Convert(float F)
{
    return (F - 32) * 5 / 9;
}

int Fib(int i)
{
    if (i <= 0)
    {
        cout << "Input error! Fibonacci starts from 1." << endl;
    }
    else if (i < 3)
    {
        return 1;
    }
    else
    {
        cout << "number " << i << " calls Fib(" << i - 1 << ") and Fib(" << i - 2 << ").\n";
        cout << endl;
        return Fib(i - 1) + Fib(i - 2);
    }
}

int main()
{
    cout << "Example 1\n";
    float F;
    cout << "Please input the temperature in fahrenheit: ";
    cin >> F;
    cout << "Convert the temperature in celsius: " << Convert(F) << endl;
    cout << endl;

    cout << "Example 2\n";
    cout << "Please input an integer number: ";
    int fib;
    cin >> fib;
    cout << Fib(fib) << " is the " << fib <<"th number of fibonacci.\n";
    cout << endl;
}

