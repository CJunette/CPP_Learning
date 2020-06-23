#pragma once

#include <iostream>
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
