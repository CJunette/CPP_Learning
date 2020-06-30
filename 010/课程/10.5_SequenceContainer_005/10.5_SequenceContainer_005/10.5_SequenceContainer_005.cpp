// 10.5_SequenceContainer_005.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这个是课上给出的后插迭代器的一个例子，但课上的代码有一点问题，我这里做了一下修改。

#include <iostream>
#include <list>
#include <iterator>
using namespace std;

int main()
{
    list<int> s;
    //课上代码中，这一行为“back_inserter iter(s);”。那其实是错误的，因为back_inserter()是一个函数，而非一个类。
    back_insert_iterator<list<int>> iter(s);
    //正确的back_inserter用法应该是。
    *back_inserter(s) = 0;

    //这里的输出迭代器的++操作与我们一般理解的++操作有些不同。一般认为右置++返回的是一个右值，是不应该拿来再进行赋值的。
    //但书上p406提到，“*iter++ = t”等同于{*iter = t; iter++;}
    *iter++ = 1;
    *iter++ = 2;
    *iter++ = 3;
    
    copy(s.begin(), s.end(), ostream_iterator<int>(cout, " "));    
}