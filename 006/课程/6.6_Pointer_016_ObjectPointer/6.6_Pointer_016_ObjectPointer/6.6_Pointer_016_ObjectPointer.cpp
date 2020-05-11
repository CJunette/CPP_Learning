// 6.6_Pointer_016_ObjectPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这里主要要讲的是this这个指向对象自身的指针。它隐含于每一个非静态成员函数中。
//注意，在C++中，this是个指针！
//问题的背景是，为什么一个类可以创建那么多个对象，但是在调用非静态成员函数的时候，每个对象调用的结果都是基于自身而非基于其他对象的呢？
//之前我对这个问题的想法是，可能就像创建对象时每个对象都创建了自己的数据成员一样，非静态的函数成员在每个对象创建的同时也都创建了一个副本。
//但是反过来想一想，这样繁琐的做法是不符合程序设计逻辑的；如果求某个类或者对象的大小，那个大小只包括了非静态数据成员的大小。
//另外，在知道this的运行机制以后就会发现，这样的想法是不对的。

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(int xx = 0, int yy = 0) :
        x(xx), y(yy)
    {
    }
    //这里之所以不同对象都能返回自身的数据成员，是因为这里的“return x;”实际上是“return this->x;”的一个简写。
    //因此，在对象调用类的函数成员时，只要把自己的首地址进行传递，系统将该对象的地址赋给this，就能实现不同对象返回不同数据成员的操作。
    int getX() const { return x; }
    int getY() const { return y; }

    private:
    int x, y;
};

int main()
{
    cout << sizeof(Point) << endl;
}