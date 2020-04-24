// 4.6_NestedClass_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    public:
    Point(int a, int b) :
        x(a), y(b)
    {
        cout << "Calling point constructor.\n";
    }
    Point():
        Point(0, 0)
    {
        cout << "Calling point constructor.\n";
    }
    Point(Point &pnt):
        x(pnt.x), y(pnt.y)
    {
        cout << "Calling point copy constructor.\n";
    }
    int getX() { return x; };
    int getY() { return y; };

    private:
    int x, y;
};

class Line
{
    public:
    //这里甚至可以用右值引用。
    Line(Point &&a, Point &&b) :
        //？但这里就出现问题了，为什么作为右值的a和b可以被传入要求参数是左值引用的Point的复制构造函数呢？
        p1(a), p2(b)
    {
        double x = (double)(p1.getX() - p2.getX());
        double y = (double)(p1.getY() - p2.getY());
        length = sqrt(x * x + y * y);
        cout << "Calling line constructor.\n";        
    }
    Line()
    {
        length = 0;
        cout << "Calling line constructor.\n";
    }
    Line(Line &l):
        p1(l.p1), p2(l.p2), length(l.length)
    {}

    private:
    Point p1, p2;
    double length;
};

Point func1(Point a)
{
    return a;
}

int main()
{
    //这个做法是以减少调用复制构造函数次数为目的做的，但是结果却是因为func1()本身的参数传入和输出反而增加了调用复制构造函数的次数。
    Point myp1(4, 7), myp2(2, 5);
    Line l1(func1(myp1), func1(myp2));
}

