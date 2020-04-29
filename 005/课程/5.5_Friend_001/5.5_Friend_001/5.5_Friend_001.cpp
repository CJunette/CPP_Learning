// 5.5_Friend_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;

//友元是一种在效率与安全性的权衡间为了提升效率而做出的设计。
//因为它破坏了类的封装，因此要慎重地使用。

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

    //1.友元函数是针对在本类之外的函数。这个函数不能是其他非友元类中的函数成员。
    //2.这里使用引用作为形参，进一步提高效率。但引用带来了双向传递的风险，老师说之后会给出解决。（我猜可能的做法就是加个const修饰）
    friend double dist(Point &p1, Point &p2);    
    //3.友元函数同样可以访问静态成员。
    friend void showCount();

    //4.可以看到，即使我这里将Cal::dist设为友元函数，下面的函数定义中仍然无法访问到Point类的x与y对象。
    friend double Cal::dist(Point &p1, Point &p2);
    //5.必须要通过设置友元类，才能是其他类中的成员能访问这个类的私有成员。
    //6.虽然这里把PointFriend类写在Point类中，但是实际上并不能通过Point的对象访问PointFriend类的成员。
    friend class PointFriend;

    private:
    int x, y;
    static int count;
};
int Point::count = 0;

double Cal::dist(Point &p1, Point &p2)
{
    //4.这种类似友元函数的写法并不能真正实现访问。
    double x = (double)(p1.getX() - p2.getX());
    double y = (double)(p1.getY() - p2.getY());
    return sqrt(x * x + y * y);
}

void showCount()
{
    cout << "Point count: " << Point::count << endl;
}
//1.由于友元函数是独立于类的函数，因此如果需要访问对象中的成员，必须以那个对象作为形参。
double dist(Point &p1, Point &p2)
{
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
};


int main()
{
    Point a(1, 4);
    Point b(5, 1);
    cout <<"Dist: " << dist(a, b) << endl;
    showCount();
    cout << endl;

    cout << "Dist: " << PointFriend().dist(a, b) << endl;

    //7.析构函数可以主动调用。
    a.~Point();
    showCount();

    PointFriend pf;
    
    
}

