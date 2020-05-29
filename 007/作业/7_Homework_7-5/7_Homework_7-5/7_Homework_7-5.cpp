// 7_Homework_7-5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const double PI = 3.1415926535898;

class Shape
{
    public:
    Shape(double x = 0, double y = 0):
        x(x), y(y)
    {
    }
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double sx) { x = sx; }
    void setY(double sy) { y = sy; }

    private:
    double x, y;
};

class Rectangle: public Shape
{
    public:
    Rectangle(double x = 0, double y = 0, double width = 0, double height = 0):
        Shape(x, y), width(width), height(height)
    {
    }
    Rectangle(Rectangle const &r):
        Shape(r.getX(), r.getY()), width(r.width), height(r.height)
    {
    }
    double getW() { return width; }
    double getH() { return height; }
    void setW(double w) { width = w; }
    void setH(double h) { height = h; }
    double getArea() { return width * height; }

    private:
    double width, height;
};

class Square: public Rectangle
{
    public:
    Square(double x = 0, double y = 0, double width = 0):
        Rectangle(x, y, width, width)
    {

    }

    private:

};

class Circle: public Shape
{
    public:
    Circle(double x = 0, double y = 0, double radius = 0):
        Shape(x, y), radius(radius)
    {

    }
    Circle(Circle const &c):
        Shape(c.getX(), c.getY()), radius(c.radius)
    {

    }
    double getR() { return radius; }
    void setR(double r) { radius = r; }
    double getArea() { return radius * radius * PI; }

    private:
    double radius;
};



int main()
{
    Rectangle rct(0, 0, 2, 3);
    Circle c(0, 0, 3);
    Square s(0, 0, 4);

    cout << rct.getArea() << endl;
    cout << c.getArea() << endl;
    cout << s.getArea() << endl;
}

