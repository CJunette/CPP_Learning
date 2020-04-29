// 5.5_Friend_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class A
{
    public:
    int getX() { return x; }
    private:
    int x = 0;
};

class B
{
    public:
    A a;
    private:
};

class C
{
    friend class D;
    public:
    private:
    int y = 0;
};

class D
{
    public:
    C c;
    int getY() { return c.y; }
    private:
    int i = c.y;
};


int main()
{
    //1.不论两个类之间是否存在友元关系，都不能写b.a.x或d.c.y这样的访问语句。全部会被认为无法直接访问。
    B b;
    b.a.getX();
    //2.有无友元关系的区别在于，存在友元关系，则可以像D类那样，在类的函数成员中访问授权类的private成员；而不存在友元关系，就只能向B类对象那样，调用A类中public的方法实现访问。    
    D d;
    d.getY();
    //3.友元类的作用范围值局限于类体（定义范围）之内，类的成员可以对授权类进行随意的访问。当类被实例化之后，就不能在用对象对类中授权类成员的private成员进行随意访问了。
    //这个也是理所应当的特性，因为作为private权限的成员，本身在类体之外就不能被同类对象直接访问，更不要说是作为其他类的对象中的成员了。

}
