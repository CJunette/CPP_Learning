// 7.7_Supplement_004_FriendInInheritance.cpp : This file contains the 'main' function. Program execution begins and ends there.
//继承与友元函数。

#include <iostream>
using namespace std;

class A
{
    friend void f();
    private:
    int a = 0;
};

class B: public A
{
    friend void g();
    private:
    int b = 1;
};

void f()
{
    //基类的友元函数是可以被派生类继承的。
    A a;
    cout << a.a << endl;
    //但继承而来的友元关系仅局限于基类的成员。对于派生类新增的成员，如果没有特殊声明，则仍需按照访问权限。
    B b;
    cout << b.a << endl;
    /*
    cout << b.b << endl;
    */
}

void g()
{
    //而如果是派生类中声明的友元函数，则访问权限与派生类中的成员函数一致。
    A a;
    /*
    cout << a.a << endl;
    */
    B b;
    /*
    cout << b.a << endl;
    */
    cout << b.b << endl;
}

int main()
{
    f();
}