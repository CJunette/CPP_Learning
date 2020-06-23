// 9.10_Supplement_008_TemplatesWithDifferentArguments.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这个是在试图写函数模板的偏特化的错误例子时发现的问题。

#include <iostream>
using namespace std;

//1.当两个函数模板的模板参数不同时，这两个函数模板会被视作是重载。
//1.参数N只用作区分不同的模板。
template<class T, unsigned N>
string fun(T t)
{
    return typeid(t).name();
}
template<class T>
string fun(T t)
{
    return "void";
}
//1.被特化的函数模板并不与违背特化的函数模板构成重载。它是单独的一个独立的函数。
template<>
string fun<int, 0>(int t)
{
    return  "bingo";
}

//2.而当两个类模板的模板参数不同时，这两个类模板只有第一个会被视为是有效的。
template<class T, unsigned N>
struct Myclass
{
    int a = 1;
};
//2.第二个类模板会被视为是模板参数不足的错误模板。
/*
template<bool B>
struct Myclass
{
    int a = 2;
};
*/

int main()
{
    {
        int a = 1;
        double b = 2;
        //1.通过模板参数的不同可以调用不同的函数模板的实例。
        cout << fun<int, 1>(a) << endl;
        cout << fun<bool>(b) << endl;
        cout << fun<int, 0>(a) << endl;
        cout << endl;
    }

    {
        Myclass<int, 1> mc1;
        cout << mc1.a << endl;
        /*
        Myclass<true> mc2;
        cout << mc2.a << endl;
        */
    }
}