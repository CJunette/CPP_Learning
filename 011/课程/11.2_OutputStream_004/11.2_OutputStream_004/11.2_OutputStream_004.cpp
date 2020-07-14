// 11.2_OutputStream_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例11-6，用ostringstream将数值转化为字符串。

#include <iostream>
#include <sstream>
using namespace std;

template<class T>
inline string toString(const T &t)
{
    //向ostringstream输出流中插入数据与向标准输出流中插入数据是一样的。
    ostringstream os;
    //插入的内容实际流向了ostringstream对象中的字符串。
    os << t;
    //通过str()成员函数可以将输出流生成的字符串返回。
    return os.str();
}

int main()
{
    string str1 = toString(5);
    cout << str1 << endl;
    string str2 = toString(1.2);
    cout << str2 << endl;
}