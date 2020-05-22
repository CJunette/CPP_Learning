// 7.6_AccessToBaseClassMember_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//派生类对基类的访问及二义性问题

#include <iostream>
using namespace std;

class Base1
{
    public:
    void func() { cout << "From Base1" << endl; }
};

class Base2
{
    public:
    void func() { cout << "From Base2" << endl; }
};

class Derived1: public Base1, public Base2
{};

class Derived2: public Base1, public Base2
{
    public:
    void func() { cout << "From Derived2" << endl; }
};

class Base3
{
    public:
    int base = 0;
};
class Base4: public Base3
{};
class Base5: public Base3
{};
class Derived3: public Base4, public Base5
{};

int main()
{
    //1.当派生类的两个基类中存在同名成员时（且派生类中没有新定义与之同名的成员），在派生类的对象中调用这些同名成员会导致报错。这就是“二义性”问题。
    Derived1 d1;    
    /*    
    d1.func();
    */
    //1.解决二义性问题的方法是用类名进行限定。通过“类名::成员名”的方式进行明确地访问。
    d1.Base1::func();
    d1.Base2::func();
    cout << endl;

    //2.而如果派生类中覆盖了这些同名成员的话，在派生类的对象中调用这些成员会调用派生类覆盖的成员。
    Derived2 d2;
    d2.func();
    //2.如果需要访问基类中的同名成员，则也像之前一样，需要通过“类名::成员名”的方式进行访问。
    d2.Base1::func();
    //2.如果是用指针访问，也是同理。
    Derived2 *pd2 = &d2;
    pd2->Base2::func();
    cout << endl;

    //3.虽然二义性可以通过限定类名来解决，但像下面这种情况中的base实际是Base4和Base5从Base3中继承而来的，然后分别继承给了Derived3。
    //3.同样的成员被复制了两份，造成了冗余。带了的问题包括：空间的浪费；本该表示特定意义的成员有了两个拷贝，且两个拷贝的值可能不同，导致引发歧义。
    //3.因此，在实际写程序时，必须尽量避免这种冗余。
    Derived3 d3;
    cout << d3.Base4::base << endl;
    cout << d3.Base5::base << endl;
    //4.当存在多层的继承关系时，也可以像下面这样用嵌套的方式逐层访问派生类的基类的基类。
    cout << d3.Base4::Base3::base << endl;
}
