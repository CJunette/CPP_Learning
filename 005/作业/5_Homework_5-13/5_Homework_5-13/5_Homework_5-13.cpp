// 5_Homework_5-13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "head.h"
using namespace std;

int main()
{
    X x;
    Y y;
    Z z;
    cout << x.getI() << endl;;
    y.g(&x);
    cout << x.getI() << endl;;
    z.f(&x);
    cout << x.getI() << endl;;
    h(&x);
    cout << x.getI() << endl;;
}
