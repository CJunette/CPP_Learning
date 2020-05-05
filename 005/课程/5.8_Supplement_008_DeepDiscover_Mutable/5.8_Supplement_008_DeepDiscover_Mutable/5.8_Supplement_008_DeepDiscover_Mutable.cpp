// 5.8_Supplement_008_DeepDiscover_Mutable.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这是书上p180-181的一个例子。

#include <iostream>
#include <cmath>
using namespace std;

class Point
{
    public:
    Point(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
    }
    Point(Point & pnt):
        x(pnt.x), y(pnt.y)
    {}

    //3.为了保证这两个函数在Line内的常函数中可以被调用，需要把这两个函数也设定为常函数。
    int getX() const { return x; }
    int getY() const { return y; }

    private:
    int x, y;
};

class Line
{
    public:
    Line(Point pnt1, Point pnt2) :
        p1(pnt1), p2(pnt2), length(-1)
    {}
    //1.书本上对length和getLength()进行了一些修改和调整。将计算length的过程放到了getLength()的方法中。从程序运行效率的角度来看这显然是有道理的，可以到需要调用length值的时候再去计算，而不是在每次生成Line的时候就计算。
    //1.但随之带来了一个问题，getLength()这个函数，从实际意义上看应该是一个const函数，但是由于我们对方法的调整，所以里面会造成对成员length的改变。
    //1.而这个对length的改变实际上只是把值从预备值变为确定值的过程，length的值实际是由两个确定的点决定的，计算length这个过程并不会在现实意义上改变length的值。
    double getLength() const
    {
        if (length < 0)
        {
            //3.因为这里是常函数，因此内部不能调用非常函数成员。
            double x = double(p1.getX() - p2.getX());
            double y = double(p1.getY() - p2.getY());
            length = sqrt(x * x + y * y);
        }
    }

    private:
    Point p1, p2;
    //2.因此，这个时候就需要在length这个变量前面添加“mutable”标记，表示这个成员在常函数中不会被视为常对象，可以进行适当的改变。
    //2.书上对“mutable”的描述是，被mutable修饰的成员对象在任何时候都不会被视为常对象。
    //2.与友元类似，因为这是破坏封装机制的功能，要谨慎使用。
    mutable double length;
};

int main()
{
    std::cout << "Hello World!\n";
}