// 9.10_Supplement_003_ExplicitInstantiation.cpp : This file contains the 'main' function. Program execution begins and ends there.
//书上p388提到，类是可以显式实例化的。

#include <iostream>
#include "Header.h"
using namespace std;

int main()
{
    //0.下面是若干显式实例化的实现。

    A<int, 1> a;
    //1.模板类中的一般的成员函数。
    a.f();
    //2.模板类中的函数模板。
    a.h<double>();
    //3.函数模板。
    g(1);
    //4.模板类中的静态数据成员。
    cout << A<int, 1>::stat << endl;

    //5.模板类。
    B<double> b;
    b.i();
}