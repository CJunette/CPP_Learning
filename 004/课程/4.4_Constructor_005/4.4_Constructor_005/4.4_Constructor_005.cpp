// 4.4_Constructor_005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//关于之前复制构造器中的问题与左值、右值的问题。

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(int a, int b);
    Point();

    //-----------2-----------    
    //之前“Point a = func();”之所以会报错，是因为这个表达式等同于“Point a(func())”，而func()的返回值虽然也是Point类型的，
    //但作为范围值，它是一个右值；而我们在复制构造器中要求的参数是个左值引用变量。
    Point(Point &pnt);
    //因此，想要避免出现错误，可以再添加一个参数为右值引用的复制构造函数。
    Point(Point &&pnt);
    //而之所以const修饰的复制构造函数没有报错，就是因为const修饰的左值引用也可以用右值作为引用对象。
    Point(const Point &pnt);

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

Point::Point(int a, int b) :
    x(a), y(b)
{}

Point::Point() :
    Point(0, 0)
{}

Point::Point(Point &pnt)
{
    x = pnt.x;
    y = pnt.y;
}

Point::Point(Point &&pnt) :
    Point(pnt)
{}

//这种类似的委托构造函数结构也可以用在复制构造函数上。
Point::Point(const Point &pnt)    
{
    x = pnt.x;
    y = pnt.y;
}

Point func()
{
    Point a;
    return a;
}

int main()
{
    //-----------1-----------
    //首先要提一下左值和右值的问题。按我现在的理解，左值就是确定了有内存存储位置的值；右值就是临时对象。
    //像下面这行代码中的x就是左值，1就是右值。
    int x = 1;

    //左值引用就是我们之前了解的那种引用。在non-const的情况下它的引用对象必须也是个左值对象。
    int &lrx = x;
    //下面这种写法就会报错。因为引用的对象是个左值。
    /*
    int &lrx = 1;
    */

    //既然有了左值引用，自然也有右值引用。右值引用的对象必须是一个右值对象。
    int &&rrx = 1;
    //同理，下面这种写法会报错。因为引用的对象是个右值。
    /*
    int &rrx = x;
    */

    //右值引用可以被当做一般的变量使用。
    int y = rrx + 1;
    //当右值引用被右值复制时，它就变成了个左值对象。
    rrx = 1;

    //之前说到，non-const的左值引用，其引用对象必须也是个左值。
    //但如果是const的左值引用，那么其引用对象也可以是个右值。
    const int &cstrx = 1;

    //以上为对左值和右值的铺垫。接下来看到Point类内部。


    //-----------3-----------
    //这里就是实际函数运行的部分，也就是说之前问题发生的部位。

    //这里之所以在跳出func()之后没有再次执行复制构造函数，可能是因为本身执行复制构造函数的目的就是为了得到一个用于复制的右值对象。
    //而现在范围的对象本身就是一个右值，因此也就没有必要在这样做一次了。
    Point a = func();
    cout << a.getX() << endl;
}
