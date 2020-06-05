// 8.4_PureVirtualFunctionAndAbstructClass_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//用纯虚函数对之前的程序进行调整。

#include <iostream>
using namespace std;

class Base1
{
    public:
    //1.声明纯虚函数，此时Base1类是个抽象类，不能实例化对象。
    virtual void display() const = 0;
};

class Base2: public Base1
{
    public:
    //2.用具体定义的虚函数覆盖之前的纯虚函数。
    virtual void display() const;
};
void Base2::display() const
{
    cout << "Base2::display()" << endl;
}

class Derived: public Base2
{
    public:
    //3.再次重写虚函数，覆盖之前定义的虚函数。
    //3.在这里，可以再次将display()声明为纯虚函数，将Derived类变为抽象类，但这样做似乎没有什么意义。
    virtual void display() const;
};
void Derived::display() const
{
    cout << "Derived::display()" << endl;
}

int main()
{
    Base2 b2;
    Derived d;
    //4.虽然纯虚函数不能实例化对象，但仍然可以创建指针用于指向派生类对象。
    Base1 *p1 = &b2;
    Base1 *p2 = &d;
    p1->display();
    p2->display();
}