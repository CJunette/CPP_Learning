// 9.10_Supplement_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//模板实例化的时间应该是在程序的编译期间。
//之前讲到虚函数的时候有提到，虚函数的动态绑定机制使其可能出现访问到派生类中私有虚函数的情况。
//这里类模板存在实例化过程，在代码实际运行前类函数也是不确定的。我就想看一下类模板的实例化过程是否也是一个动态的过程。

#include <iostream>
using namespace std;

class A
{
    void g() { cout << "A" << endl; }
};

template<class T>
void f(T a)
{
    //结果是，这里尝试访问对象的私有成员会出错。
    //因为函数实例化的过程在程序运行前就完成了，并不像虚函数那样进行动态绑定。
    /*
    a.g();
    */
}

int main()
{
    A a;
    f(a);
}