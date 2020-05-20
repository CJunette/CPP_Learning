// 7.4_TypeConvert_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//基类与派生类的类型转换（书上的类型兼容规则）

#include <iostream>
using namespace std;

class Base1
{
    public:
    void display() { cout << "Base1::display()" << endl; }
};
class Base2 : public Base1
{
    public:
    //不要重新定义继承而来的非虚函数。
    void display() { cout << "Base2::display()" << endl; }
};
class Derived : public Base2
{
    public:
    //不要重新定义继承而来的非虚函数。
    void display() { cout << "Derived::display()" << endl; }
};

void func(Base1 *ptr)
{
    ptr->display();
}

int main()
{
    //此处虽然派生类的对象的地址也可以作为要求形参为基类指针的函数的实参。
    //但在函数运行时，函数本身还是会调用基类的成员，而非根据传入的指针类型来确定具体的调用成员。
    func(&Base1());
    func(&Base2());
    func(&Derived());
}

