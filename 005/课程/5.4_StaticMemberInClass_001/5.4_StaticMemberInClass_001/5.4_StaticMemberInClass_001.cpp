// 5.4_StaticMemberInClass_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Point
{
    public:
    //不论是应构造函数还是复制构造函数创建新对象，都要把总数加一。
    Point(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
        count++;
    }
    Point(Point &p):
        //这里我特地看了看汇编代码，这么写和在函数体里写“x = p.x; y = p.y;”是一样的效果。
        x(p.x), y(p.y)
    {
        count++;
    }
    //注意，当对象被删除时，就要在析构函数中把总数减一。
    ~Point()
    {
        count--;
    }

    int getX() { return x; }
    int getY() { return y; }
    //任意对象调用这个函数，相同时刻得到的结果应该都是一样的。注意Point.showCount()这种写法是错误的。
    void showCount()
    {
        cout << "Point count: " << count << endl;
    }

    private:
    int x, y;
    //静态数据成员为类内所有对象共享。
    //只有有const修饰的静态数据成员可以在类内初始化，否则静态数据成员必须在类外初始化。
    static int count;
};

//静态数据成员count在内存上有特定的位置，在构造函数和复制构造函数中执行count++的操作时，都会访问这个特定位置。
int Point::count = 0;


int main()
{
    Point a(4, 5);
    cout << "Point A: (" << a.getX() << ", " << a.getY() << ")." << endl;
    a.showCount();
    Point b(a);
    cout << "Point B: (" << b.getX() << ", " << b.getY() << ")." << endl;
    b.showCount();
    //函数结束调用析构函数时，先析构b，再析构a。
    return 0;

    //这里老师留下一个问题：在没有创建任何点时，count的值应该为0，那要怎样才能看到这个count的值呢？
    //之后的例题中会给出方法。
    //其实就是静态函数成员访问count。添加一个showCount函数的静态重载，然后用Point::showCount()的方式调用。
}
