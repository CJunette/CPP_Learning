// 4.4_Constructor_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//复制构造函数

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(int x, int y);
    Point();

    //这个就是复制构造函数。复制构造函数要求参数是一个同类型的引用对象。
    //要注意！这里的形参是有“const”修饰的。因为如果使用引用变量的话，可能会造成对实参的改变。必须通过添加“const”来保证对实参的操作只有读取！！！！！
    Point(const Point &pnt);
    //如果没有写复制构造函数，则编译器会自动生成给一个默认的复制构造函数，将被当做初始值的类对象中的成员值赋给新建立的对象中对应的成员。

    //如果不希望编译器自动生成默认复制构造函数，则用以下的写法。
    /*
    Point(Point &pnt) = delete;
    */
    //更早的版本还有将复制构造函数放在private下，然后不给复制构造函数具体定义的做法。

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

void func1(Point p)
{
    cout << p.getX() << endl;
}

Point func2()
{
    Point a;
    return a;
}


int main()
{
    //复制构造函数有三种使用情景。

    //1.当需要用一个已有的类的对象去给新的类的对象进行初始化时。
    Point p1(1, 2);
    Point p2(p1);

    //2.当类的对象作为实参被传入值类型的形参时，会发生类的复制，此时会再次用到复制构造函数。
    func1(p1);

    //3.当类的对象作为某个函数的返回值被返回时。
    Point p3;
    //p3=func2中并没有用复制构造函数，因为两边的对象中的成员都已经有了默认值。
    //这里可能会涉及到第8章会讲到的自定义赋值运算函数。
    p3 = func2();

    //这个等式实际并不是赋值语句。因为赋值语句从右向左执行，当func2()返回一个Point类型的变量时，p4尚未进行初始化。
    //这里进行的操作其实是p4(func2())，即用func2()返回的对象，通过复制构造器初始化p4。
    //？但是比较奇怪的是，在这里看起来好像调用了两次赋值构造器（func2()一次，p4一次），但实际debug的时候值显示调用了一次复制构造器。
    Point p4 = func2();

}


Point::Point(int x, int y) :
    x(x), y(y)
{}

Point::Point() :
    Point(0, 0)
{}


Point::Point(const Point &pnt)
{
    ///？这里有一点要注意，下面的表达式不能写成“x=pnt.getX()”，会出现报错。错误原因可能和这里的形参类型是const有关。
    //？另外，为什么这里能实现在类体外访问类体内的private成员也是个问题。这里虽然构造函数在类体中，但对于传入的参数pnt而言，很显然是在其类体之外。
    x = pnt.x;
    y = pnt.y;
    cout << "Call copy constructor." << endl;
}