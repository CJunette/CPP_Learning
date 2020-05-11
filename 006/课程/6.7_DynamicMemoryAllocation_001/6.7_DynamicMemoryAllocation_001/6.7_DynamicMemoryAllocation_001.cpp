// 6.7_DynamicMemoryAllocation_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//动态内存分配存在的原因是程序员在写程序时不清楚数据的规模，必须到程序运行时才能确定数据规模大小，因此设计了一个具有动态存储能力的机制。
//动态内存分配实现了在程序执行期间，申请用于存放某类数据的内存空间的功能。
//比如，我们在之前是不能用一个变量来确定数组的大小的，而如果要实现这种做法，就要使用动态内存分配。

//之前我们讲指针的时候，其实没有体现出指针的独特性，大部分指针能做到的事直接用变量名也能做到。
//但学过动态内存分配以后，由于动态内存分配只能返回地址，因此指针的独特性和重要性就体现出来了。

#include <iostream>
using namespace std;

class Point
{
    public:
    //在执行new操作符时，调用构造函数。
    Point(int x, int y):
        x(x), y(y)
    {
        cout << "Calling constructor..." << endl;
    }
    Point() :
        x(0), y(0)
    {
        cout << "Calling default constructor..." << endl;
    }
    //在执行delete操作符时，调用析构函数。
    ~Point()
    {
        cout << "Calling destructor..." << endl;
    }
    int getX() const { return x; }
    int getY() const { return y; }

    private:
    int x, y;
};

int main()
{
    cout << "Step 1: " << endl;
    //动态内存分配返回的是一个指针，因此必须用同类型的指针进行接收。
    //如果分配成功，则返回一个指针；如果不成功（如剩余的内存空间不足），则抛出异常。
    //动态内存分配是一种运算，new是一个运算符。
    Point *ptr = new Point();
    //注意，虽然这里进行delete时，代码上看是删除ptr，但实际上是删除ptr所指的那个动态内存分配对象。
    //可以看到，在更下面的代码中又一次调用了ptr这个指针。
    delete ptr;

    //另外，不是什么对象都能拿来delete的。
    //这里如果执行以下代码的话，不会有任何报错，但是程序执行时会直接卡死。
    /*
    int a = 0;
    int *p = &a;
    delete p;
    */

    cout << "Step 2: " << endl;
    ptr = new Point(4, 5);

    //注意，这里如果在动态分配对象被删除之后再对其进行操作就会造成程序运行时的卡死（尤其是删除对象后还执行原对象的函数调用操作）。
    cout << ptr->getX() << endl;
    delete ptr;
    //可以看到，下面的这行代码中，ptr就被标出是未初始化的内存空间。但这里没有像以前那样直接报错。可能是因为之前已经对ptr进行过多次操作，而之前那种报错只发生在第一次试图访问ptr时。
    cout << ptr << endl;
    //另外，如果到程序最后也没有执行动态内存分配空间的删除，程序也不会自动执行删除操作。那部分空间只会随着程序一起被收系统回。
    //在实际程序中绝对不要出现这种情况！
}
