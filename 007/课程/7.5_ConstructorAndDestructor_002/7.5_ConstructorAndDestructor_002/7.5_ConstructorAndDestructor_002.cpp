// 7.5_ConstructorAndDestructor_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//派生类的复制构造函数

#include <iostream>
using namespace std;

class Base
{
    public:
    Base(int b = 0)
    {
        base = b;
        cout << "Calling Base constructor..." << endl;
    }
    Base(const Base &b):
        base(b.base)
    {
        cout << "Calling Base copy constructor..." << endl;
    }
    ~Base()
    {
        cout << "Calling Base destructor..." << endl;
    }
    private:
    int base;
};

class Member
{
    public:
    Member(int m = 2)
    {
        member = m;
        cout << "Calling Member constructor..." << endl;
    }
    Member(const Member &m):
        member(m.member)
    {
        cout << "Calling Member copy constructor..." << endl;
    }
    ~Member()
    {
        cout << "Calling Member destructor..." << endl;
    }

    private:
    int member;
};

class Derived: public Base
{
    public:
    Derived(int d = 1, int b = 0, int m = 2):
        derived(d), Base(b), member(Member(m))
    {
        cout << "Calling Derived constructor..." << endl;
    }
    Derived(const Derived &drv):
        //此处如果删掉下面初始化列表中的Base(drv)，则不会调用基类的复制构造函数，转而调用基类的构造函数。
        //另外，注意这里其实使用派生类的对象做基类复制构造函数的参数。
        derived(drv.derived), Base(drv), member(drv.member)
    {
        cout << "Calling Derived copy constructor..." << endl;
    }
    ~Derived()
    {
        cout << "Calling Derived destructor..." << endl;
    }

    private:
    int derived;
    Member member;
};

int main()
{
    Derived d1(1, 0, 2);
    cout << endl;
    Derived d2(d1);
}
