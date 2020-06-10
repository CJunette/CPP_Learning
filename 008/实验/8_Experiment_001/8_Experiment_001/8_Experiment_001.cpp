// 8_Experiment_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(int x = 0, int y = 0):
        _x(x), _y(y)
    {}

    Point &operator ++();
    Point operator ++(int);
    Point &operator --();
    Point operator --(int);

    friend ostream &operator << (ostream &out, Point const &p);

    private:
    int _x, _y;
};
Point &Point::operator++()
{
    _x++;
    _y++;
    return *this;
}
Point Point::operator++(int)
{
    Point p = *this;
    ++ *this;
    return p;
}
Point &Point::operator--()
{
    _x--;
    _y--;
    return *this;
}
Point Point::operator--(int)
{
    Point p = *this;
    -- *this;
    return p;
}

ostream &operator<<(ostream &out, Point const &p)
{
    out << "Point(" << p._x << ", " << p._y << ")";
    return out;
}

int main()
{
    Point p(1, 2);
    cout << p << endl;
    cout << p++ << endl;
    cout << ++p << endl;
    cout << p-- << endl;
    cout << --p << endl;
}
