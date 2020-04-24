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
    Point(const Point &pnt):
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
    Line(Point &&a, Point &&b) :
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
    Line(const Line &l):
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
    Point myp1(4, 7), myp2(2, 5);
    Line l1(func1(myp1), func1(myp2));
}

