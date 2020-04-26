// 4.6_NestedClass_004_ConstructAndDestructOrder.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(int a, int b) :
        x(a), y(b)
    {
        cout << "Creating Point " << this << endl;
    }
    Point(Point &pnt) :
        x(pnt.x), y(pnt.y)
    {
        cout << "Copying Point " << this << endl;
    }
    ~Point()
    {
        cout << "Destroying Point " << this << endl;
    }

    private:
    int x, y;
};

class Line
{
    public:
    Line(Point a, Point b) :
        pnt1(a), pnt2(b)
    {
        cout << "Creating Line " << this << endl;
    }

    //这一步在创建时形参结合会调用一次复制构造函数，初始化会调用一次复制构造函数。
    //形实结合的复制对象会在Line的复制构造函数结束后立刻调用析构函数。
    //用于初始化的复制对象则会作为类成员保留，知道类成员调用析构函数以后才调用析构函数
    Line(Line &ln) :
        pnt1(ln.pnt1), pnt2(ln.pnt2)
    {
        cout << "Copying Line " << this << endl;
    }
    ~Line()
    {
        cout << "Destroying Line " << this << endl;
    }

    private:
    Point pnt1, pnt2;
};

int main()
{
    Point a(1, 2);
    Point b(3, 4);

    //构造函数的调用上，内嵌类的顺序早与外部类。构造一个有内嵌类的类，需要先构造内嵌类，再构造外部类。
    //析构函数的调用上，内嵌类的顺序晚于外部类。析构一个由外部类的类，需要先析构外部类，在析构内嵌类。
    Line c(a, b);
}

