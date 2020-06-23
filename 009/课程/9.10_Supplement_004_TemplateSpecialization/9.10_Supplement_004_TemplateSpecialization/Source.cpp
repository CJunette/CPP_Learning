#include "Header.h"

/*
void MyClass1<double>::f()
{
    cout << "MyClass1<double>.f()" << endl;
}
*/

template<>
struct MyClass2<bool>
{
    void f();
};

void MyClass2<bool>::f()
{
    cout << "MyClass1<bool>.f()" << endl;
}

/*----------------------------------------------------------------------------*/

template<class T>
int MyClass4<T>::num(2);

template<>
int MyClass4<double>::num(20);