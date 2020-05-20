// 7.3_InheritanceMethod_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//私有继承

#include <iostream>
using namespace std;

class Point
{
    public:
    void initPoint(float ix, float iy)
    {
        x = ix;
        y = iy;
    }
    void move(float offx, float offy)
    {
        x += offx;
        y += offy;
    }
    float getX() const { return x; }
    float getY() const { return y; }

    private:
    float x, y;
};

class Rectangle : private Point
{
    public:
    void initRectangle(float ix, float iy, float iw, float ih)
    {
        initPoint(ix, iy);
        w = iw;
        h = ih;
    }
    float getW() const { return w; }
    float getH() const { return h; }
    //在使用private方式继承后，基类中的所有成员都不再可见。因此不能像之前那样在对象中调用Point类中的getX()，getY()，move()了，需要自己重新定义这些函数。
    //此处，由于是以同名的方式创建getX()，getY()，move()的，因此会覆盖之前基类中的同名成员。想要在调用基类成员就必须使用“类名::成员名”的方式。
    float getX() const { return Point::getX(); }
    float getY() const { return Point::getY(); }
    void move(float offx, float offy) { Point::move(offx, offy); }

    private:
    float w, h;
};

int main()
{
    Rectangle rect;
    rect.initRectangle(2, 3, 20, 10);
    rect.move(3, 2);
    cout << "The data of rectangle:" << endl;
    cout << rect.getX() << ", " << rect.getY() << ", " << rect.getW() << ", " << rect.getH() << endl;
}