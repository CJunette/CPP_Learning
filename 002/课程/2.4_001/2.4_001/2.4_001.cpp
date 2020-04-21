// 2.4_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int x, y;
    cout << "Please input the value of x." << endl;
    cin >> x;
    cout << "Please input the value of y." << endl;
    cin >> y;

    if (x > y)
    {
        cout << "x > y\n";
    }
    else if (x < y)
    {
        cout << "y > x\n";
    }
    else
    {
        cout << "x = y\n";
    }
}

