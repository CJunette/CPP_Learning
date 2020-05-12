// 6.10_DeepCopy_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cassert>
using namespace std;

class Point
{
    public:
    Point(int x, int y) :
        x(x), y(y)
    {
        cout << "Calling constructor..." << endl;
    }
    Point() :
        x(0), y(0)
    {
        cout << "Calling default constructor..." << endl;
    }
    ~Point()
    {
        cout << "Calling destructor..." << endl;
    }
    int getX() const { return x; }
    int getY() const { return y; }
    void move(int newX, int newY)
    {
        cout << "Moving to (" << newX << ", " << newY << ")" << endl;
        x = newX;
        y = newY;
    }

    private:
    int x, y;
};

class PointArray
{
    public:
    PointArray(int s) :
        size(s)
    {
        points = new Point[size];
    }
    //在这里，如果没有特别写复制构造函数，那么默认构造函数执行的会是浅拷贝。
    //也就是说，对于指针points，虽然默认的复制构造函数会在复制的对象里复制一个指针，但那个指针指向的动态内存分配对象还是先前那个被复制对象中的动态内存分配对象。
    //造成的结果就是，所有对被复制对象的动态内存分配对象的操作都会影响被复制对象。而且，在程序结束时，由于存在两个对象指向同一个动态内存分配对象，在执行第二次析构函数时，相当于是在对一块已经执行过delete的空间再进行一次delete，造成程序在运行时无法停止或卡死。
    //对此的解决办法是，手动编写一个复制构造函数，然后在复制构造函数中重新声明一个新的动态内存分配对象，让指针指向这个新的对象。然后用循环语句将之前那个动态内存分配对象（这里是数组）的值全都拷贝到这个新对象中。
    PointArray(const PointArray &pa)
    {
        size = pa.size;
        points = new Point[size];
        for (int i = 0; i < size; i++)
        {
            points[i] = pa.points[i];
        }
    }
    ~PointArray()
    {
        cout << "Deleting..." << endl;
        delete[] points;
    }
    Point &element(int index)
    {
        assert(index >= 0 && index < size);
        return points[index];
    }

    private:
    int size;
    Point *points;
};

int main()
{   
    //第一次写的时候我写成了下面这种形式。出于好奇，我运行了一下，想知道“PointArray *pa2(pa1);”这行代码会产生什么结果。
    //结果运行的时候直接跳过了这一行。
    /*
    PointArray *pa1 = new PointArray(2);
    pa1->element(0).move(5, 10);
    pa1->element(1).move(15, 20);
    PointArray *pa2(pa1);
    */

    PointArray pa1(2);
    pa1.element(0).move(5, 10);
    pa1.element(1).move(15, 20);
    PointArray pa2(pa1);
    cout << "Point 0 of pa2: (" << pa2.element(0).getX() << ", " << pa2.element(0).getY() << ")" << endl;
    cout << "Point 1 of pa2: (" << pa2.element(1).getX() << ", " << pa2.element(1).getY() << ")" << endl;
    pa1.element(0).move(25, 30);
    pa1.element(1).move(35, 40);
    cout << "After moving pa1..." << endl;
    cout << "Point 0 of pa2: (" << pa2.element(0).getX() << ", " << pa2.element(0).getY() << ")" << endl;
    cout << "Point 1 of pa2: (" << pa2.element(1).getX() << ", " << pa2.element(1).getY() << ")" << endl;
}