// 8.5_Supplement_003_DynamicCast.cpp : This file contains the 'main' function. Program execution begins and ends there.
//关于dynamic_cast。

#include <iostream>
using namespace std;

class A
{};
class B: public A
{};
class C
{
    public:
    virtual void f() {};
};
class D: public C
{};

class Base
{
    public:
    virtual void fun1();
    virtual ~Base() {};
};
void Base::fun1()
{
    cout << "Base::fun1()" << endl;
}

class Derived1: public Base
{
    public:
    virtual void fun1();
    virtual void fun2();
};
void Derived1::fun1()
{
    cout << "Derived1::fun1()" << endl;
}
void Derived1::fun2()
{
    cout << "Derived1::fun2()" << endl;
}

class Derived2: public Derived1
{
    public:
    virtual void fun1();
    virtual void fun2();
};
void Derived2::fun1()
{
    cout << "Derived2::fun1()" << endl;
}
void Derived2::fun2()
{
    cout << "Derived2::fun2()" << endl;
}

void fun(Base *b)
{
    b->fun1();
    //5.对基类对象进行类型转换，将其转为派生类对象。
    Derived1 *d = dynamic_cast<Derived1 *>(b);
    //5.如果转换成功，则指针不为空。
    if(d != 0)
    {
        d->fun2();
    }
}

int main()
{
    //1.dynamic_cast只能作用于指向多态类型的指针或引用。其中包含两重意思，一是必须有多态（也就是必须有虚函数），二是必须是指针或引用
    {
        A *a;
        /*
        B *b = dynamic_cast<B *>(a);
        */
    }
    //2.这里可以看到，必须有多态是指被转换的指针所指的对象所属的类中必须存在虚函数。而目标对象则不一定要求。目标对象甚至可以是任意不相干的类型（但不建议这么做，没什么意义，还容易出错）。
    //2.这里为了测试功能特别写了这种错误的形式。一般情况下dynamic_cast是用于将同一类族的（指向派生类对象的）基类指针或引用转化为派生类指针或引用，
    //2.因此被转换对象存在虚函数也就意味着目标类型存在虚函数。
    {
        C *c = new C;
        A *a = dynamic_cast<A *>(c);
        A *pa;
        /*
        C *pc = dynamic_cast<C *>(pa);
        */
        delete c;
    }
    //3.这里可以看到，dynamic_cast只能不能作用于对象。
    {
        B b;
        /*
        A a = dynamic_cast<A>(b);
        */
    }
    //4.dynamic_cast还可以将指针转为void *的类型。
    //4.这里执行的实际操作是，先将指针pc转为它所指向的对象的类型的指针，然后将其转为void指针。换句话说，就是得到p所指的对象的首地址。（多继承时，基类指针所指的地址不一定就是对象的首地址。）
    {
        D d;
        C *pc = &d;
        void *p = dynamic_cast<void *>(pc);
    }
    
    //5.下面看一下书上给的例子。
    Base b;
    fun(&b);
    Derived1 d1;
    fun(&d1);
    Derived2 d2;
    fun(&d2);
}