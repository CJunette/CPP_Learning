// 6.4_ArrayOfObject_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Point
{
    public:
    int z = 0;
    Point(int xx = 0, int yy = 0) :
        x(xx), y(yy)
    {
        cout << "Calling constructor." << endl;
    }
    //2.因此，这里的形参还是要用能接受右值引用的const形式。
    Point(const Point &pnt) :
        x(pnt.x), y(pnt.y)
    {
        cout << "Calling copy constructor." << endl;
    }
    ~Point()
    {
        cout << "Calling destructor." << endl;
    }

    private:
    int x, y;
};

int main()
{
    //1.如果类中没有默认构造函数，那么这种写法就会报错。
    Point a[2];
    //2.用下面这种方式进行初始化，虽然并不调用复制构造函数，但如果复制构造函数的形参不能接受右值引用的话，还是会报错。
    //2.究其原因其实是，我们之前提到过的，这里的这种将构造函数返回的临时对象直接放到标识符所在内存的做法实际是编译器经过优化的结果。
    //2.而如果没有经过优化的话，需要经历的是“构造器生成临时对象-调用复制构造器将临时对象拷贝到标识符所在的内存上”这样的过程。
    //2.在程序编写阶段，显然编译器的优化还未进行，因此编译器会认为这里应该有一个用复制构造函数复制右值的过程。如果复制构造函数的形参不能接受右值引用的话，自然就无法接受构造其生成的临时对象。
    //2.因此就出现了这里的这个问题。看似与复制构造函数无关，但却会因为复制构造函数而报错。
    Point b[] = { Point(1, 2), Point(1, 3) };

    cout << endl;
}
