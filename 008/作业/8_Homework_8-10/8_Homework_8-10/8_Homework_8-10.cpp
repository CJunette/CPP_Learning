// 8_Homework_8-10.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(double x = 0, double y = 0):
        _x(x), _y(y)
    {}

    Point operator + (Point const & pnt)
    {
        Point newpnt;
        newpnt._x = _x + pnt._x;
        newpnt._y = _y + pnt._y;
        return newpnt;
    }
    void showX() const { cout << _x << endl; }
    void showY() const { cout << _y << endl; }

    private:
    double _x, _y;
};

int main()
{
    Point p1(1, 2);
    Point p2(3, 4);
    Point p3 = p1 + p2;
    p3.showX();
    p3.showY();
}