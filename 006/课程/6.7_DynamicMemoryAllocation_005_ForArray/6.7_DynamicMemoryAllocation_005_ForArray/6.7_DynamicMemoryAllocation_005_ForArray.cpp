// 6.7_DynamicMemoryAllocation_005_ForArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//由于C++里没有数组越界报错的机制，因此考虑用一个特定的类来存放数组，并在类中设置这种越界报错的机制。

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
    //用类充当数组的做法，实际的操作就是在类中声明一个目标类的指针，然后再在构造其中创建一个目标类的数组，并让那个指针指向这个数组。
    PointArray(int s) :
        size(s)
    {
        points = new Point[size];
    }
    ~PointArray()
    {
        cout << "Deleting..." << endl;
        delete[] points;
    }
    //这里的函数返回值类型是引用类型，因为必须保证返回的对象就是动态分配创建的Point数组中的成员。
    //如果不用引用类型返回，那么返回的其实是经过Point类复制构造的一个副本。对那个副本进行操作是不会影响到对象中的数组的成员的。
    //同样的，如果在这里使用指针也可以保证返回值不是副本。只是后续的成员访问操作会需要进行一些语法上的调整。
    Point &element(int index)
    {
        //使用assert需要引入头文件<cassert>。assert的功能是当括号内的语句为false时，程序会终止并报错。
        //注意，assert只会在调试模式下使用。
        assert(index >= 0 && index < size);
        return points[index];
    }

    private:
    int size;
    Point *points;
};

int main()
{
    int count;
    cout << "Please input the number of points: ";
    cin >> count;

    //这里有一点要注意，如果这里使用“PointArray *pnt = new PointArray(count)”，那么结尾处必须进行删除，或主动调用析构函数。因为如果涉及动态内存分配，创建是对象指针，而指针是不会自动调用析构函数的。    
    PointArray *pnt = new PointArray(count);
    PointArray pnts(count);    
    pnts.element(0).move(5, 0);
    pnts.element(1).move(15, 20);
}
