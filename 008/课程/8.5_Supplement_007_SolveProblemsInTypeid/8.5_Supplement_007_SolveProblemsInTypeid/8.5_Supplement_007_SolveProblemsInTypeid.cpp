// 8.5_Supplement_007_SolveProblemsInTypeid.cpp : This file contains the 'main' function. Program execution begins and ends there.
//在typeid中提到了一个问题，在之前的程序中，下面主函数的代码明明pb0是指向具有多态性类型的指针却没有在typeid中被求值。
//这里对问题进行了解答。

#include <iostream>
#include <typeinfo>
using namespace std;

class A0
{
    //添加了虚函数。之前就是因为B1中.f()的返回值不具备多态性，所以typeid才不进行求值的。
    virtual void f() {}
};
class A1: public A0
{
    virtual void f() {}
};

class B0
{
    public:
    virtual ~B0() {}
    virtual A0 *f()
    {
        cout << "B0::f()" << endl;
        return new A0;
    }
};
class B1: public B0
{
    public:
    virtual A1 *f()
    {
        cout << "B1::f()" << endl;
        return new A1;
    }
};

int main()
{
    B1 b;
    B0 *pb0 = &b;
    {
        //在这里，对.f()返回的指针进行求值。指针本身是不具有多态性的。
        //或者在B0和B1中将f()的返回值调整为引用。
        cout << typeid(*(*pb0).f()).name() << endl;
        cout << endl;
    }
}