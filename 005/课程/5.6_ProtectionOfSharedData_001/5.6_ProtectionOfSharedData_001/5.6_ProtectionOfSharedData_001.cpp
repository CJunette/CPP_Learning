// 5.6_ProtectionOfSharedData_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//可以用const修饰的“东西”（课上提到的是常类型）有以下几种：
//1.常对象。必须初始化，不能被更新。
//2.常成员。包括常数据成员和常函数成员。（注意，这里没有常函数，只有常成员。因为说常函数也是特指某类中的函数成员。）
//3.常引用。被引用的对象不能被更新。
//4.常数组。数组元素不能被更新。第六章。
//5.常指针。指向常量的指针。第六章。

#include <iostream>
using namespace std;

class Point
{
    public:
    Point(int xx = 0, int yy = 0, int tt = 0):
        //3.常数据成员的初始化必须通过这种初始化函数的形式来完成，不能在函数体中完成！
        t(tt)
    {
        x = xx;
        y = yy;        
        count++;
    }
    Point(Point &pnt):
        t(pnt.t)
    {
        x = pnt.x;
        y = pnt.y;
        count++;
    }
    ~Point()
    {
        count--;
    }

    int show() { return t; }

    //2.常函数成员的写法是把const写在函数的参数列表后面。常函数和普通函数是可以构成重载关系的。    
    //2.如果声明与定义分离，则在定义时也需要带上const。
    //2.不能让一个非成员函数（全局函数）做常函数，会报错。
    int show() const {  return count; }
    //2.注意，这里如果像下面这样把const写在最开头，则代表这个函数show()的返回值是一个const int类型的值。由于这种写法只是改变了函数的返回值类型，因此不能成为show()的函数重载。
    /*
    const int show() { return count; }
    */

    private:
    int x, y;
    const int t = 0;
    static int count;
    //3.对象成员、静态成员都可以成为常数据成员。
    const static int test;
};

int Point::count = 0;
const int Point::test = 0;

int main()
{    
    //1.常对象必须在声明时就初始化！
    //2.常对象只能调用常函数成员（注意是常对象，不是说常数值成员只能用常函数处理）。换句话说，如果把之前的那个函数成员删除，只有一个无修饰的show()，则这里会报错。
    //2.常对象就是用这种方法保证自己的成员值不会被改写。
    const Point b(2, 3, 30);
    cout << b.show() << endl;

    Point a(1, 2, 20);
    //2.一般对象也可以调用常函数成员。因此，对于不会修改成员值的函数，最好统一将其设为常函数。这样，在不该发生成员值修改的函数发生修改成员值的现象时，能直接在编译阶段就出现错误。
    cout << a.show() << endl;
}
