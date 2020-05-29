// 7_Homework_7-11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class BaseClass
{
    public:
    void fn1() { cout << "fn1() in BaseClass" << endl; }
    void fn2() { cout << "fn2() in BaseClass" << endl; }
};

class DerivedClass: public BaseClass
{
    public:
    void fn1() { cout << "fn1() in DerivedClass" << endl; }
    void fn2() { cout << "fn2() in DerivedClass" << endl; }
};

int main()
{
    DerivedClass dc;
    DerivedClass *pdc = &dc;
    BaseClass *pbc = &dc;

    pdc->fn1();
    pdc->fn2();
    pbc->fn1();
    pbc->fn2();
}

