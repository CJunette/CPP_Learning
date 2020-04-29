// 5.5_Friend_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

//友元是一种在效率与安全性的权衡间为了提升效率而做出的设计。
//因为它破坏了类的封装，因此要慎重地使用。
//另外要注意3点！1.友元关系不能传递！2.友元关系是单向的！3，友元关系不能被继承！

//4.注意，这里必须要用一下前向引用声明。不然在Cal类中无法在成员函数形参中使用Point。
class Point;

class Cal
{
    public:
    double dist(Point &p1, Point &p2);
};

class Point
{
    public:
    Point(int xx = 0, int yy = 0)
    {
        x = xx;
        y = yy;
        count++;        
    }    
    Point(Point & pnt)
    {
        x = pnt.x;
        y = pnt.y;
        count++;        
    }
    ~Point()
    {
        count--;        
    }
    int getX() { return x; }
    int getY() { return y; }

    //1.友元函数是针对在本类之外的函数。
    //1.这个函数非常特殊，它在类内声明，既可以在类内定义也可以在类外定义（都不会报错）；但不论是用本类对象调用，还是用静态函数调用方法调用，都无法调用友元函数。只有全局函数的调用方式能调用友元函数。
    //1.这里就引出一个问题，友元函数为什么声明在类内，可是却不是类的函数成员。
    //1.按我现在在网上找到的说法，基本都表示要在类外定义友元函数。也有说friend关键词所修饰的声明只是一个权限的声明，并不是真正意义上的声明，因此必须在类外在进行一次定义。（可能是C++版本更替对这点进行了修改和调整）
    //2.这里使用引用作为形参，进一步提高效率。但引用带来了双向传递的风险，老师说之后会给出解决。（我猜可能的做法就是加个const修饰）
    friend double dist(Point &p1, Point &p2);
    //3.友元函数同样可以访问静态成员。
    friend void showCount();

    //4.友元函数同样可以是其他类中的函数成员。
    friend double Cal::dist(Point &p1, Point &p2);
    //5.设置友元类可以使友元类中的所有成员都可以访问授权类中的private成员。
    //6.虽然这里把PointFriend类写在Point类中，但是实际上并不能通过Point的对象访问PointFriend类的成员。
    friend class PointFriend;

    private:
    int x, y;
    static int count;
};
int Point::count = 0;

//1.由于友元函数是独立于类的函数，因此如果需要访问对象中的成员，必须以那个对象作为形参。
double dist(Point &p1, Point &p2)
{
    double x = (double)(p1.x - p2.x);
    double y = (double)(p1.y - p2.y);
    return sqrt(x * x + y * y);
}

void showCount()
{
    cout << "Point count: " << Point::count << endl;
}

double Cal::dist(Point &p1, Point &p2)
{
    //4.以其他类中的函数成员作为友元函数同样可以实现对授权类对象private成员的访问。
    double x = (double)(p1.x - p2.x);
    double y = (double)(p1.y - p2.y);
    return sqrt(x * x + y * y);
}

class PointFriend
{
    public:
    double dist(Point &p1, Point &p2)
    {
        double x = (double)(p1.x - p2.x);
        double y = (double)(p1.y - p2.y);
        return sqrt(x * x + y * y);
    }
    private:
    //5.友元类中的private成员同样可以访问授权类中的private成员。
    int i = Point::count;
};


int main()
{
    Point a(1, 4);
    Point b(5, 1);
    cout <<"Dist: " << dist(a, b) << endl;
    showCount();
    cout << endl;    
    
    cout << "Dist: " << Cal().dist(a, b) << endl;
    cout << endl;

    cout << "Dist: " << PointFriend().dist(a, b) << endl;
    cout << endl;

    //7.析构函数可以主动调用。
    a.~Point();
    showCount();

    PointFriend pf;    
}