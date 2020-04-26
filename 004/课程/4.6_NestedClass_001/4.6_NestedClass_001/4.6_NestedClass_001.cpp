// 4.6_NestedClass_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(int a, int b) :
        x(a), y(b)
    {
        cout << "Calling Point constructor.\n";
    }
    //1.由于Point类被Line类当做成员使用，因此如果Point类没有默认构造器，在Line类内尝试创建默认的Point对象时就会报错。   
    Point() :
        Point(0, 0)
    {}    

    Point(const Point &pnt)
    {
        x = pnt.x;
        y = pnt.y;
        cout << "Calling point copy constructor.\n";
    }

    int getX()
    {
        return x;
    }
    int getY()
    {
        return y;
    }

    private:
    int x, y;
};

class Line
{
    public:
    //6.在这里，如果把下面的构造函数改写成如下形式，则会少调用两次Point的复制构造函数。
    //但是由于这里会要调用类中的函数，因此不能添加const修饰符，也就导致了无法以只读形式访问引用，带来了数据双向传递的风险。所以我也不确定这样写到底对不对。
    /*
    Line(Point &a, Point &b) :
    */
    Line(Point a, Point b) :
        //2.如果这里未对成员对象p1、p2进行初始化，则这两个对象会按照Point类默认的构造函数进行初始化。
        //此时如果Point类没有默认构造函数，就会直接报错。
        p1(a), p2(b)
    {
        double x = (double)(a.getX() - b.getX());
        double y = (double)(a.getY() - b.getY());
        length = sqrt(x * x + y * y);
        cout << "Calling line constructor.\n";
    }
    
    //2.在这里也是一样。如果Line默认的初始化构造函数就是“Line(){}”，且Point类没有默认构造函数的话，编译器就会因为p1、p2无法找到用于初始化的默认构造函数而报错。
    //这里注意，即是是要写一个空的默认构造函数，也要写Line(){}，不要只写Line()，会报错。对于上面Point()类的默认构造函数也是这样。
    Line()
    {
        //2.而因为Point类有了默认的构造函数，因此下面被注释的代码即使被省略，p1、p2也会调用默认构造函数进行初始化。
        /*
        Point a, b;
        p1 = a;
        p2 = b;
        */
        length = 0;
        cout << "Calling line constructor.\n";
    }
    
    Line(const Line &line) :
        p1(line.p1), p2(line.p2), length(line.length)
    {
        cout << "Calling line copy constructor.\n";
    }

    double getLength()
    {
        return length;
    }

    private:
    //3.组合类对象的初始化顺序是按照对象的定义顺序来决定的。在这里，就是p1，p2，length这样的次序。
    Point p1, p2;
    double length;
};

int main()
{
    Point myp1(1, 1), myp2(4, 5);        
    //4.在此可以看到，参数的形式结合，赋值是从形参的右侧开始的。（对应关系的建立是从左往右的）
    Line l1(myp1, myp2);
    Line l2(l1);
    cout << "The length of l1 is " << l1.getLength() << ".\n";
    cout << "The length of l2 is " << l2.getLength() << ".\n"; 

    //5.注意，下面这样的语句是错误的。编译器不会报错，会直接跳过这行语句。
    Line l3(Point a, Point b);
    Line l4();
}

