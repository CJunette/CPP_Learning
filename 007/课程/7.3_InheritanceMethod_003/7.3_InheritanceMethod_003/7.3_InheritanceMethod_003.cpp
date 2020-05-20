// 7.3_InheritanceMethod_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//保护继承

#include <iostream>
using namespace std;

class A
{
    protected:
    int a = 1;
};
class B: protected A
{
    public:
    //对于类的成员而言，protected就相当于public，因此可以直接访问。
    int getA() { return a; }
};

int main()
{
    A a;
    //由于对于类外的对象而言，protected就相当于private，因此不能通过对象直接访问protected对象。
    /*
    a.x = 5;
    */
    B b;
    cout << b.getA() << endl;
}
