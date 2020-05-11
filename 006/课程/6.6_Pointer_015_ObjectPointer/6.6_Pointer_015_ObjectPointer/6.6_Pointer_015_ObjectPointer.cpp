// 6.6_Pointer_015_ObjectPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//对象指针，顾名思义，就是指向对象的指针。

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(int xx = 0, int yy = 0) :
        x(xx), y(yy)
    {
    }
    int getX() const { return x; }
    int getY() const { return y; }    

    private:
    int x, y;    
};

int main()
{
    Point a(5, 10);
    //指向对象的指针的创建方式和一般的指针相同。
    Point *ptr = &a;

    //通过指针访问成员名。
    cout << ptr->getX() << endl;
    //上述方法实际上等同于下面的这个方法，但上述方法看起来更简洁。
    cout << (*ptr).getX() << endl;
    cout << a.getX() << endl;       
}

