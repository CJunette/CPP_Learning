// 8.3_VirtualFunction_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这里我想确认一下，在派生类中对与基类虚函数同名的函数进行调整会使其变为基类虚函数的重载。
//课上提到的算作派生类对基类虚函数重写的条件有4点：
//1.函数名称相同（名称不同自然算是不同的函数，没有必要做讨论）
//2.参数列表相同
//3.返回值相同或满足赋值兼容规则
//4.const属性相同
//另外这里简单地提到了用派生类和基类的对象访问虚函数和用指向派生类的基类指针访问虚函数的问题。在之后会展开。

#include <iostream>
using namespace std;

class Base1
{
    public:
    virtual Base1 *func()
    {
        cout << "func() in Base1" << endl;
        return new Base1;
    }
    int a = 0;
};

class Derived1: public Base1
{
    public:
    virtual Derived1 *func()
    {
        cout << "func() in Derived1" << endl;
        return new Derived1;
    }
    int a = 1;
};

class Derived2: public Base1
{
    public:
    //2.当在派生类中重写虚函数时改变了其返回值类型，如果返回值类型不符合要求，编译器会直接报错。
    /*
    virtual void *func()
    {}
    */
    int a = 2;
};

class A
{};
class Derived3: public Base1
{
    public:
    Derived3(A) {}
    //3.对虚函数重写时的返回值类型要求似乎是返回值类型是同一类族中的类。
    //3.这里，即使类A能隐式的转换为Derived3，仍然因为不是在同一类族所以报错。
    /*
    virtual A *func()
    {}
    */
    int a = 3;
};

class Derived4: public Base1
{
    public:
    //4.当在派生类中重写虚函数时改变了其参数列表，编译器不会报错。此时相当于在派生类中创建了一个与基类虚函数同名的函数重载。
    //4.根据隐藏规则，此时基类中的同名函数（此时就是虚函数）及重载都会被隐藏。
    //4.此时如果不加“virtual”，那派生类中新创建的函数就是一般成员函数；如果加上“virtual”，派生类中新创建的就是虚函数。
    virtual Derived4 *func(int i = 0)
    {
        cout << "func() in Derived4" << endl;
        return new Derived4;
    }
    int a = 4;
};

class Derived5: public Base1
{
    public:
    //5.通过改变虚函数的const属性再创建新的与虚函数同名的函数，同样相当于在派生类中创建了与基类虚函数同名的重载。
    //5.其具体表现与Derived4中的函数重载表现是一样的。
    virtual Derived5 *func() const
    {
        cout << "func() in Derived4" << endl;
        return new Derived5;
    }
    int a = 5;
};

class Derived6: public Derived5
{
    public:
    //6.当直接基类(Derived5)中隐藏了间接基类(Derived6)中的虚函数时，直接基类的派生类对间接基类的虚函数进行重写时，仍然能够成功重写。
    //6.也就是说，只要基类中存在某特定名称、参数列表、返回值类型、const属性的虚函数，即使在派生的过程中被一些派生类隐藏，
    //6.那些隐藏了虚函数的派生类派生出的派生类仍然能够通过正确的名称、参数列表、返回值类型、const属性对那个虚函数实现重写。
    virtual Derived6 *func()
    {
        cout << "func() in Derived6" << endl;
        return new Derived6;
    }
    int a = 6;
};

void f(Base1 *b1)
{
    auto o = b1->func();
    //0.这里有一个问题，auto并不是通过动态绑定确定数据类型的（C++貌似没有反射），因此就导致即使传入的指针指向的是派生类对象，o仍然是基类对象。
    //0.也就是说，对数据成员的访问并没有像虚函数这样的动态机制。
    b1->a;
    delete o;
}

int main()
{
    //1.虽然Base1和Base2的虚函数func()返回值类型各不相同，返回值类型是满足赋值兼容规则的。因此派生类中对func()的重写相当于对基类中虚函数的覆盖，而不算是对基类虚函数的重载。
    Base1 b1;
    Derived1 d1;
    f(&b1);
    f(&d1);
    cout << endl;

    //4.而此时由于基类中并不存在带参数的func(int)，因此用基类指针调用时只能访问到基类第基类的虚函数。
    //4.即使基类中存在带参数的非虚函数func(int)，且f()调用的也是那个带参数的func(int)。f()最终仍然只会调用基类中的非虚函数，而非派生类中的虚函数。
    //4.这种派生类中将基类非虚函数修改为虚函数的做法，无法用基类的指针来表现多态性。（这些内容之后会详细讲）
    Derived4 d4;
    f(&d4);
    d4.func();
    cout << endl;

    //5.Derived5的表现和Derived4的表现是十分相似的。
    Derived5 d5;
    f(&d5);
    d5.func();
    cout << endl;

    //6.从这里的输出值可以看出，Derived6中确实在Derived5隐藏了Base1的虚函数的情况下，对那个虚函数进行了重写。
    Derived6 d6;
    f(&d6);
    cout << endl;

    //7.最后想简单说一下关于指针（引用）访问和对象访问。
    //7.虚函数的多态是只能通过指针或引用来体现的。用指向基类的派生类指正访问虚函数，能够访问到派生类中的虚函数；但用派生类对象去初始化基类对象再访问虚函数，只能访问到基类的虚函数。
    Base1 *pb1 = &d1;
    Base1 b1test = d1;
    pb1->func();
    b1test.func();
}