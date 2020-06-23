// 9.10_Supplement_006_PartialTemplateSpecialization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//偏特化。

#include <iostream>
#include <cassert>
using namespace std;

template<class T, class S>
struct MyClass1
{
    MyClass1(const T &t = 0, const S &s = 1);
    bool equal() const;
    T t;
    S s;
};
template<class T, class S>
MyClass1<T, S>::MyClass1(const T &t, const S &s):
    t(t), s(s)
{}
template<class T, class S>
bool MyClass1<T, S>::equal() const
{
    return ((T)s == t) && ((S)t == s);
}

//1.类模板的偏特化也只能对已存在的类模板进行。即便已有的类模板只是进行了声明，而没有进行详细地定义(去掉上面函数声明的代码)，也可以进行偏特化。
//1.偏特化在多文件结构下的表现与特化中的类模板一致。
//1.虽然偏特化的结果仍然是模板，而非具体的类，但偏特化的类允许将成员函数的定义放在其他源文件中。
template<class T>
struct MyClass1<T, int>
{
    MyClass1(const T &t = 0, const int d = 1);
    bool equal() const;
    T t;
    double d;
};
template<class T>
MyClass1<T, int>::MyClass1(const T& t, const int d):
    t(t), d(d)
{}
template<class T>
bool MyClass1<T, int>::equal() const
{
    return ((int)t == d) && ((T)d == t);
}

/*----------------------------------------------------------------------------*/

template<class T>
struct MyClass2
{
    MyClass2(T&t);
};
template<class T>
MyClass2<T>::MyClass2(T&t){}
//2.偏特化除了可以实现对部分模板参数的具体化以外，还可以将某个模板参数所表示的范围缩小。
//2.下面这个偏特化就将添加了一个模板参数为指针的模板。（虽然我也不知道这样的做法有什么实际用处。）
template<class T>
struct MyClass2<T *>
{
    MyClass2(T *t);
};
template<class T>
MyClass2<T *>::MyClass2(T *t) {}
//3.进一步地，将偏特化参数设置为const，会使得这个偏特化模板变得更为特殊。
template<class T>
struct MyClass2<const T*>
{
    MyClass2(const T *t);
};
template<class T>
MyClass2<const T *>::MyClass2(const T *t) {}

/*----------------------------------------------------------------------------*/

//4.对于缩小范围使模板变得更为特殊这一点，函数模板也可以通过函数模板重载实现。
//4.注意，这里是函数模板重载！而不是简单的函数重载！
template<class T>
T MyMax(T a, T b)
{
    return (a > b) ? a : b;
}
//4.由于指针类型需要先求址才能进行大小比较（否则比较的就是地址大小），所以指针类型一定会要重写函数体。
template<class T>
T MyMax(T *a, T *b)
{
    return (*a > * b) ? *a : *b;
}

/*----------------------------------------------------------------------------*/

//5.但虽然参数范围缩小的偏特化操作在函数模板上能够用函数重载来实现，但对部分模板参数进行具体化的偏特化操作依然无法适用于函数模板。

//5.这里先定义两个之后要用到的函数。
void positive(const char *str, int N)
{
    cout << str;
    int n = strlen(str);
    if(N > n)
    {
        for(int i = n; i < N; i++)
        {
            cout << 0;
        }
    }
    cout << endl;
}
void reverse(const char *str)
{
    int n = strlen(str);
    for(int i = n - 1; i >= 0; i--)
    {
        cout << str[i];
    }
    cout << endl;
}
//5.在这里，当我希望偏特化N = 0的情况时，编译器会显示当前函数已被定义的错误。
template<class T, int N>
void f()
{
    positive(typeid(T).name(), 10);
}
//5.设计目的是希望，一般情况下，正常输出类型模板参数的类型名，并以0补全字符；当N = 0时，将类型模板参数的类型名倒过来输出。
/*
template<class T, int N>
void f<T, 0>()
{
    reverse(typeid(T).name());
}
*/
//5.想要达成这个目的，只能把函数模板的模板参数拆开，定义类模板；然后在类模板中再定义成员函数模板，并添加模板参数全部确定的特化模板。
template<class T>
struct MyClass3
{
    template<int N>
    void f()
    {
        positive(typeid(T).name(), N);
    }
    template<>
    void f<1>()
    {
        reverse(typeid(T).name());
    }
};

/*----------------------------------------------------------------------------*/

int main()
{
    {        
        cout << "Part 1" << endl;
        //1.确定部分模板参数的偏特化。
        MyClass1<double, float> mc1(1, 1.2f);
        cout << mc1.equal() << endl;
        MyClass1<double, int> mc2(1.0, 1);
        cout << mc2.equal() << endl;        
        cout << endl;
    }

    {
        cout << "Part 2" << endl;
        int a = 1;
        int *pa = &a;
        const int *cpa = &a;
        //2.缩小模板参数标识范围的，更“特殊”化的偏特化。
        MyClass2<int> mc1(a);
        MyClass2<int *> mc2(pa);
        //3.实参会根据自身的特征，寻找与其最为接近的偏特化形式。
        MyClass2<const int *> mc3(cpa);
        cout << endl;
    }

    {
        cout << "Part 3" << endl;
        //4.通过函数重载实现缩小模板参数范围。
        double a = 1, b = 2;
        double *pa = &a, *pb = &b;
        cout << MyMax(a, b) << endl;
        cout << MyMax(pa, pb) << endl;
        cout << endl;
    }

    {
        //5.利用类模板和成员函数模板的特化来解决函数模板无法偏特化的问题。
        cout << "Part 4" << endl;
        f<int, 10>();
        f<double, 1>();
        cout << endl;
        MyClass3<int> mc1;
        MyClass3<double> mc2;
        mc1.f<10>();
        mc2.f<1>();
        cout << endl;
    }
}
