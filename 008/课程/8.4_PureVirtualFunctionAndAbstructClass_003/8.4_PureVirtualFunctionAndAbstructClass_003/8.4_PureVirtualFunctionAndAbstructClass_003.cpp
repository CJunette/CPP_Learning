// 8.4_PureVirtualFunctionAndAbstructClass_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//展示“final”

#include <iostream>
using namespace std;

class Base1 final
{};
//1.当某类被“final”修饰时，这个类之后将不再可以作为其他类的基类。
/*
class Derived1: public Base1
{};
*/

class Base2
{
    public:
    virtual void f() final { cout << "Base2 f()" << endl; }
};
class Derived2: public Base2
{
    public:
    //2.当类中的某个成员函数被“final”修饰后，派生类可以继承那个成员函数，但不能对其进行重写。
    /*
    virtual void f() {};
    */
};

class Base3
{
    public:
    //3.纯虚函数也可以用“final”修饰，只不过这样做就意味着这个类之后所有的派生类都是抽象类。
    virtual void g() final = 0;
};

int main()
{
    Derived2 d2;
    d2.f();
}