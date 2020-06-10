// 8_Homework_8-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const double Pi = 3.1415926535898;

class Shape
{
    public:
    virtual double getArea() = 0;
    virtual double getPerim() = 0;
};

class Rectangle: public Shape
{
    public:
    Rectangle(double x, double y):
        x(x), y(y)
    {}
    virtual double getArea();
    virtual double getPerim();
    private:
    double x, y;
};
double Rectangle::getArea()
{
    return x * y;
}
double Rectangle::getPerim()
{
    return 2 * (x + y);
}

class Circle: public Shape
{
    public:
    Circle(double r):
        r(r)
    {}
    virtual double getArea();
    virtual double getPerim();
    private:
    double r;
};
double Circle::getArea()
{
    return Pi * r * r;
}
double Circle::getPerim()
{
    return Pi * r * 2;
}

int main()
{
    Rectangle r(1, 2);
    Circle c(1);
    
    cout << "Rectangle area: " << r.getArea() << endl;
    cout << "Rectangle perimeter: " << r.getPerim() << endl;

    cout << "Circle area: " << c.getArea() << endl;
    cout << "Circle perimeter: " << c.getPerim() << endl;
}
