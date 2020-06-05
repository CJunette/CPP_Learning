// 8.4_PureVirtualFunctionAndAbstructClass_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//展示"override"

#include <iostream>
using namespace std;

class Base
{
    public:
    virtual void f() const
    {
        cout << "Base f()" << endl;
    }
    virtual ~Base() {}
};

class Derived: public Base
{
    public:
    //“override”实现显示地覆盖，此时如果当前定义的函数在虚函数中没有对应的相同函数签名的虚函数，就会报错。
    //如果忘记了下面的“const”，就会报错。
    //之前讲过如果忘记了这里的const，f()变成虚函数重载，下面用基类指针调用f()时就不会调用这里新定义的虚函数f()，而是继续调用基类的一般成员函数f()。而程序设计时，通常并不希望出现这样的结果。
    //此时“override”就起到了将可能存在的隐式的问题显现出来的作用。
    //另外还有一点需要注意，“override”和“const”一样，要加在函数名的后方
    virtual void f() const override
    {
        cout << "Derived f()";
    }
    virtual ~Derived() {}
};

int main()
{
    Base *b;
    b = new Base;
    b->f();
    delete b;
    b = new Derived;
    b->f();
    delete b;
}