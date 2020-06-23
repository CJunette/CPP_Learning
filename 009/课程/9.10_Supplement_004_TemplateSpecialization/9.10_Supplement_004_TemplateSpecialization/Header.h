#pragma once
#include <iostream>
using namespace std;

template<class T>
struct MyClass1
{
    void f();
};
template<class T>
void MyClass1<T>::f()
{
    cout << "MyClass1.f()" << endl;
}

/*----------------------------------------------------------------------------*/

template<class T>
struct MyClass2
{
    void f();
};

template<class T>
void MyClass2<T>::f()
{
    cout << "MyClass2.f()" << endl;
}

/*----------------------------------------------------------------------------*/

template<class T>
struct MyClass4
{
    static int num;
};

/*
template<class T>
int MyClass4<T>::num(2);
*/
/*
template<>
int MyClass4<double>::num(20);
*/
