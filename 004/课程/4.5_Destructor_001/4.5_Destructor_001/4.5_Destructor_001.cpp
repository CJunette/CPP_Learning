// 4.5_Destructor_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(int a, int b):
        x(a), y(b)
    {}

    Point():
        x(0), y(0)
    {}

    //这个就是析构函数，用来完成对象被删除前的工作。目前的学习进度暂时看不出它的用处，之后学得更深入了，会发现它的作用。(如第六章)
    //如果没有自定义析构函数，则编译器会自动生成一个空的析构函数（就像构造函数一样）。
    //析构函数没有参数表，没有返回值类型，没有return语句！
    ~Point()
    {}

    private:
    int x, y;            
};

int main()
{
    Point p;
}

