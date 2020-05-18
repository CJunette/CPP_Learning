// 6.13_Supplement_006_TypeCast.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这里是书上p247中提到关于之前例子中PointArray类的element()函数成员无法被常对象访问的相关内容。

#include <iostream>
#include <cassert>
using namespace std;

//Point类的定义和以前一样，不重要。
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
    //重点在这里。
    Point &element(int index)
    {
        //此处首先将this用static_cast变成了一个const型的PointArray指针，然后调用常函数成员element()（就是下面那个），此时返回结果是一个const型的Point类型的引用。
        //然后再将结果用const_cast转换为Point类型的普通引用。因为这个函数实际是希望普通对象调用的，因此返回的引用也应该是普通应用而非常引用。
        //这样做的好处在于，当element()函数的内容需要做调整时，可以只调整常函数成员，而不用将函数体分散在不同函数内然后分别调整。
        //我对这个程序之前的疑惑在于，当static_cast在主函数中单独使用时，实际上都是通过复制构造函数或构造函数创造了一个新的对象。那么回到类体中，如果static_cast也是构造了一个新对象的话，通过element()函数返回的就是新对象，那么所有相关的操作就都不会影响原对象。这样的话就改变了element()函数的设计目的了。
        //但通过跟踪调用我发现，这里的这个static_cast似乎并不会调用复制构造函数或构造函数创建新对象。而是直接将this转化为常量指针后调用常函数成员element()。原因似乎是因为当用static_cast将某类型的指针转换为同类的const指针时，不会调用构造函数或复制构造函数。
        return const_cast<Point &>(static_cast<const PointArray *>(this)->element(index));
    }
    //按书上的说法，如果定义了一个PointArray的常对象，element()作为普通函数就无法被调用了。这里这个返回值为常量的常成员函数就是为了那种情况下还能调用element()函数而设计的函数重载。
    const Point &element(int index) const
    {
        assert(index >= 0 && index < size);
        return points[index];
    }
    //这里为了方便我把原来的private成员变成了public。
    int size;
    Point *points;
};

int main()
{
    PointArray pa(1);
    pa.element(0).move(3, 3);
    cout << pa.points[0].getX() << endl;
    cout << pa.points[0].getY() << endl;
}
