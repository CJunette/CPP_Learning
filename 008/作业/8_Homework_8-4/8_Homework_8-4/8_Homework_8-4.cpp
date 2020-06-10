// 8_Homework_8-4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Counter
{
    public:
    int i = 0;
    Counter &operator +(int x) 
    { 
        i += x;
        return *this;
    }
};

int main()
{
    Counter ct;
    cout << ct.i << endl;
    ct = ct + 10;
    cout << ct.i << endl;
}
