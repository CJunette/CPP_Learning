// 2.4_008.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>
using namespace std;


enum WeekDay {Dimanche = 7, Lundi = 1, Mardi, Mercredi, Jeudi, Vendredi, Samedi};

int main()
{
    //“typedef”与“using”的试用。
    typedef double Area;
    Area a = 10;
    double b = 10;

    using Length = double;
    Length c = 10;       

    //enum类型的变量可以直接作为整数使用。
    for ( int i = Lundi; i < Dimanche; i++ )
    {
        cout << i << endl;
    }
    cout << endl;

    int d;
    d = Lundi;
    cout << d << endl;
    cout << endl;

    //整数值不能直接赋给枚举变量，必须经过强制类型转换。
    WeekDay someday = (WeekDay)1;

    //测试“auto”的变量类型在初始化时有不同类型的多个变量时会是什么。
    int e = 1;
    auto f = e + a;
    cout << typeid(f).name() << endl;
    cout << endl;

    //“decltype”的使用。
    decltype(a) g = 2;
    cout << typeid(g).name() << ' ' << g << endl;
    cout << endl;
}

