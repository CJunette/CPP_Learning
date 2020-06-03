// 8.3_VirtualFunction_005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这里主要讨论虚函数无视访问权限的情况。

#include <iostream>
using namespace std;

class Base1
{
    public:
    virtual void func() { cout << "Base" << endl; }
};

class Base2: public Base1
{
    private:
    virtual void func() { cout << "Base2" << endl; }
};

class Derived: public Base2
{
    public:
    virtual void func() { cout << "Derived" << endl; }
};

int main()
{
    Base2 b2;
    //如果基类与派生类的关系是private或protected，则不能用派生类来初始化基类对象（或指针、引用）。
    Base1 *b1 = &b2;
    //这里可以看到，虽然在派生类Base2中，同名的虚函数是private的，但由于基类Base1中的虚函数是public，所以依然能够实现访问。
    //这里更具体的原因是，对于访问权限的判定是在编译阶段完成的。对于编译器而言，下面这行代码要做的是用一个基类Base1的指针访问基类的虚函数，而基类虚函数又是public的，因此不会存在访问问题。因此编译器不会报错。
    //而当实际运行时，程序不会在检查访问权限的问题。在运行时，这里需要根据派生类Base2的虚表指针调用派生类的虚函数，程序跳转到虚函数所在代码位置。因此就出现了访问private成员函数的现象。
    b1->func();
    
    //这里可以看到，即使直接基类Base2中对虚函数进行了私有化的处理，派生类Derived类中仍然可以对虚函数进行覆盖。
    //因为这种覆盖实际上就是新定义的函数在通过了虚函数的判定标准后，创建了新的虚函数表（其中虚函数有了新的地址），并用新的虚函数表地址更新虚表指针的操作。
    Derived d;
    b1 = &d;
    b1->func();
}