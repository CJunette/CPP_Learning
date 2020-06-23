#include "Header.h"
#include <iostream>
using namespace std;

template<class T>
struct MyClass1<T, double>
{
    MyClass1(const T &t = 0, const double d = 1);
    bool equal() const;
    T t;
    double d;
};
template<class T>
MyClass1<T, double>::MyClass1(const T &t, const double d):
    t(t), d(d)
{}
template<class T>
bool MyClass1<T, double>::equal() const
{
    return ((double)t == d) && ((T)d == t);
}


template<>
struct MyClass2<double>
{
    void f();
};
void MyClass2<double>::f()
{
    cout << "MyClass2<double>.f()" << endl;
}