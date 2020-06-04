// 8.3_VirtualFunction_006.cpp : This file contains the 'main' function. Program execution begins and ends there.
//讨论虚表中虚函数的显示数量和顺序。
//这里主要是要查看debug时的对象组成。

#include <iostream>

class Base
{
    public:
    //3.必要时可以注释这里的虚函数代码，来查看删除Base中虚函数的情况。    

    virtual void f() {}
    virtual void f(int) {}
    virtual void g() {}
    virtual void f(int, int) {}
    
    private:
    int i;
};
class Derived1: public Base
{
    public:
    virtual void f() {}
    virtual void h() {}
    private:
    int j;
};
class Derived2: public Derived1
{
    public:
    virtual void i() {}
    private:
    int k;
};

int main()
{
    //1.对于同名的虚函数重载而言，后声明的排在前，先声明的排在后。
    //1.对于不同名的虚函数而言，根据名称声明的先后（如果存在多个重载，则看第一个被声明的重载所在的位置），先声明的排在前，后声明的排在后。
    Base b;
    //2.debug时派生类中虚表显示的虚函数数量是根据第一次出现虚函数的基类的虚函数数量确定的。也就是说派生类中新添加的虚函数在debug时是始终无法被看到的（但可以通过命令行查看类构造看到）。
    Derived1 d1;
    //3.如果最远基类（Base）中不存在虚函数，而最远基类派生出的当前派生类的直接基类(Derived1)创建了虚函数时（也就是把Base中的虚函数都删掉的情况），
    //3.直接基类中的虚表还是会显示虚函数数量个地址，但从第二个地址开始才指向自定义的虚函数。
    //3.第一个地址会指向一个名为“_empty_global_delete”的函数。我也不确定那是什么？
    //3.另外，这种最远基类没有虚函数，中间基类创建虚函数的情况会使debug时查看到的对象构造变得十分凌乱（但如果通过命令行查看类构造则不存在问题，也不会在虚表中看到之前那个“_empty_global_delete”函数）。

    //2.创建这个派生类的目的是为了确定虚表显示的数量是根据直接基类中的虚函数数量确定还是根据第一次出现虚函数的基类中的虚函数数量确定。
    Derived2 d2;
    return 0;
}