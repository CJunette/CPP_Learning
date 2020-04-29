// 5.6_ProtectionOfSharedData_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//这个程序主要是对之前提到的用引用做形参带来双向传递问题的解决。
//同时在完善的过程中，我想了解一下常函数在的不能改变成员的值的这一条规律对指针所指向的成员的值起不起效。
//起效与否取决于指针是否是常指针。如果是常指针，则不能改变常指针所指向对象的值；如果不是，则就算改变了常函数也认为是没有改变。

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
    }    
    int getX() { return x; }
    int getY() { return y; }    

    int testForLine = 1;

    //1.之前提到的由于双向传递造成可能的参数改变的情况，所以避免直接用引用做friend形参。那个问题就是用const修饰引用，建立常引用来解决的。
    //2.注意，这里不能把下面这个友元函数加const变成常函数成员。因为这个函数不是Point类的成员函数。不能将一个非函数成员变成一个带const修饰的函数。（会有这样做的想法是因为我想看看const能否区分出对引用的改变也可能改变成员值）
    friend double dist(const Point &p1, const Point &p2);

    private:
    int x, y;    
};

class Line
{
    public:
    Line(Point *pp):
        p(pp), q(pp)
    {}
    void changePointValue() const
    {
        //3.注意，下面这行代码会报错。对于常指针，我们不能修改它指向的对象的值。
        /*
        (*q).testForLine++;
        */

        //4.而下面这行代码是可以通过编译的。也就是说常函数成员只会避免函数修改本类的成员的值（在这里就是指针指向的地址），而不会管指针所指向的对象的值是否在函数体内被改变。（前提是函数中没有涉及常指针成员）
        (*p).testForLine++;
        cout << (*p).testForLine << endl;
    }
    private:
    Point *p;    
    const Point *q;
};

double dist(const Point &p1, const Point &p2)
{
    double x = (double)(p1.x - p2.x);
    double y = (double)(p1.y - p2.y);
    return sqrt(x * x + y * y);
}

int main()
{
    Point p1(1, 2);
    Point p2(2, 2);
    cout << dist(p1, p2) << endl;
        
    Line l1(&p1);
    l1.changePointValue();
}
