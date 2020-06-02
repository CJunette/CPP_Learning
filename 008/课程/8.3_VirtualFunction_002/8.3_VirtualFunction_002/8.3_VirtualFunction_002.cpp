// 8.3_VirtualFunction_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这里我想确认一下基类及派生类中同名函数返回值的差异对虚函数的影响。
//课上提到对返回值定义的要求是，返回值类型相同，或满足复制兼容规则的指针、引用。

#include <iostream>
#include <typeinfo>
using namespace std;

class Base1
{
    public:    
    virtual Base1 *func();
    int a = 1;
};
Base1 *Base1::func()
{
    cout << "func() in Base1" << endl;
    return new Base1();
}
//-----------------------------------------------------
class Base2: public Base1
{
    public:
    virtual Base2 *func();
    int a = 2;
};
Base2 *Base2::func()
{
    cout << "func() in Base2" << endl;
    return new Base2();
}
//-----------------------------------------------------
class Derived1: public Base2
{
    public:
    virtual Derived1 *func();
    int a = 3;
};
Derived1 *Derived1::func()
{
    cout << "func() in Derived1" << endl;
    return new Derived1();
}
//-----------------------------------------------------
class Derived2: public Base2
{
    public:
    //2.当派生类中重新定义基类中的虚函数，当返回值类型并不符合要求时，编译器会直接报错提示。
    //2.如果像我这样通过修改函数参数列表强行创建一个同名函数，则当用基类指针调用虚函数时，会调用基类中的函数；当用对象调用函数时，会调用该类中定义的函数。
    void func(int = 0);
};
void Derived2::func(int)
{
    cout << "func() in Derived2" << endl;
}
//-----------------------------------------------------
class Derived3: public Derived2
{
    public:    
    //3.如果对之前的派生类进行进一步派生，在创建同名函数时，会再次根据函数名、参数表、返回值，判断函数是否为直接基类或间接基类的虚函数的覆盖。
    //3.即使其直接基类（Derived2）中通过创建了一个参数表不同的同名函数隐藏了虚函数，只要间接基类（Base2）中存在虚函数，这里对同名函数的满足要求的定义就会再次被视为是对虚函数的覆盖。
    Derived3 *func();
};
Derived3 *Derived3::func()
{
    cout << "func() in Derived3" << endl;
    return new Derived3();
}

//4.派生类中对虚函数覆盖时的返回值的要求似乎就是指返回值的类型必须是同一类族中的类。
//4.我尝试返回一个可以满足通过构造函数实现对本类类型转换的类的动态对象，但编译器依旧以返回值不符合要求为由报错。
/*
class A
{
};
class Derived4: Base2
{
    public:
    Derived4()
    {
    }
    Derived4(A const&)
    {
    }
    A *func();
};
A *Derived4::func()
{
    cout << "func() in Derived3" << endl;
    return new A();
}
*/

void func1(Base1 *obj)
{
    //1.这里有一点问题，由于auto并不是真正在程序运行时确定标识符类型的（C++并没有真正的反射机制），因此在这里不论传入指针调用函数的返回值是什么，o的类型都是Base1*。
    //1.这也就导致所有的o->a的值都是1。（如何实现对不同指针能访问到不同的数据成员？用对象成员指针？）
    //1.所以我只能通过在函数func()内添加语句来区分调用的是哪一个函数。
    auto o = obj->func();
    cout << o->a << endl;
    delete o;
}

int main()
{
    Base1 b1;
    Base2 b2;
    Derived1 d1;    
    //1.虽然Base1、Base2、Derived1三个对象所属的类的func()函数返回值各不相同，但都属于同一类族之内，因此Base2和Derived1中的func()函数都算对Base1中虚函数的覆盖。
    func1(&b1);
    func1(&b2);
    func1(&d1);
    cout << endl;

    //2.而当派生类中重新定义了与虚函数同名的函数，且返回值不符合要求时，编译器就会直接报错。（奇怪的是当用正确的返回类型，但形参列表不同时，不会报错，但函数会覆盖之前的虚函数）
    //2.此时如果用同名函数，不同的返回值和不同的参数列表，则会覆盖之前的虚函数。函数func1()会调用最近一级基类中可用的虚函数，而直接用对象调用则会调用本类中新创建的函数。
    Derived2 d2;
    func1(&d2);
    d2.func();
    cout << endl;
    //3.进一步的，在先前那个用一般函数覆盖虚函数的类Derived2的基础上再派生出新的派生类Derived3。
    //3.此时虽然直接派生类中没有虚函数，但由于间接派生类中还是存在虚函数，因此只要形式满足要求，这里仍然能正确覆盖之前的虚函数。
    Derived3 d3;
    func1(&d3);
    cout << endl;

    //5.虚函数在通过对象和指针访问时会表现出很大的差异。
    //5.当用基类指针指向一个派生类的成员，并访问其中的成员函数时，访问到的是派生类中的成员函数。
    //5.而当用一个派生类对象去初始化基类对象，在用基类对象访问成员函数时，访问到的是基类中的成员函数。
    Base1 *pbd1 = &d1;
    pbd1->func();
    Base1 bd1 = d1;
    bd1.func();
    cout << endl;
}