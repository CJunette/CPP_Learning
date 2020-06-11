// 8_Homework_8-8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class BaseClass
{
    public:
    virtual void fn1() const { cout << "Base::fn1()" << endl; }
    void fn2() const { cout << "Base::fn2()" << endl; }
};

class DerivedClass: public BaseClass
{
    public:
    virtual void fn1() const override { cout << "Derived::fn1()" << endl; }
    void fn2() const { cout << "Derived::fn2()" << endl; }
};

int main()
{
    DerivedClass d;
    BaseClass *pb = &d;
    DerivedClass *pd = &d;
    pb->fn1();
    pb->fn2();
    pd->fn1();
    pd->fn2();
}
