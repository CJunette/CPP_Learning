// 5.4_StaticMemberInClass_002_StaticMethod.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(int xx, int yy)
    {
        x = xx;
        y = yy;
        count++;
        cout << "Calling Constructor." << endl;
    }
    Point() :
        Point(0, 0)
    {}
    Point(Point &pnt)
    {
        x = pnt.x;
        y = pnt.y;
        count++;
        cout << "Calling Copy Constructor." << endl;
    }
    ~Point()
    {
        count--;
        cout << "Calling Destructor." << endl;
    }
    int getX() { return x; }
    int getY() { return y; }

    //想要实现在没有对象的情况下也能访问类的静态成员，就必须定义一个静态函数成员。
    //注意，这里定义了静态函数成员，就不能在写一个面向对象的showPoint()函数了。静态函数成员与函数成员间无法实现重载，会报错。
    static void showCount()
    {
        cout << "Point number: " << count << endl;
    }

    private:
    int x, y;
    static int count;
};

int Point::count = 0;

int main()
{
    Point::showCount();
    Point a(1, 5);
    Point::showCount();
    Point b(a);
    Point::showCount();
    //这里可以再次看出，这种类名创建的临时对象会在这行语句结束之后立刻就调用析构函数被销毁。
    Point(1, 3);
    Point::showCount();    
}
