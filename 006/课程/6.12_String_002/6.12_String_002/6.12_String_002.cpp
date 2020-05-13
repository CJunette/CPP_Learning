// 6.12_String_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//C++风格的字符串，string类。

#include <iostream>
using namespace std;

int main()
{
    //1.“string”类的默认构造函数创建的是长度为0的字符串。但如果之后对字符串进行重新赋值，string的长度会随之发生改变。
    string s0;
    s0 = "abc";

    //2.“string”类可以用一个常量字符串对新的字符串进行初始化。string(const char *s);
    string s1("cde");
    //2.上述写法也等同于下面这种写法。
    string s1_1 = "CDE";

    //3.“string”类可以用一个现有string变量来初始化新的字符串（复制构造函数）。string(const string &s);
    string s2(s1);

    //4.“string”类的运算。其实本质是在string类中对这些运算符进行了重载。
    //4.加法运算用于拼接两个字符串。
    cout << s0 + s1 << endl;
    //4.“==”用于判断两个字符串是否相等。对大小写敏感。
    cout << (s1_1 == s1) << endl;

    //4.“=”用于用一个字符串给另一个字符串赋值。
    cout << s2 << endl;
    s2 = s0;
    cout << s2 << endl;
    
    //4.关系运算用于逐个比较字符串中的字符的ascii码大小，只要不相等就返回。
    cout << (s1_1 > s1) << endl;

    //4.字符串也可以用下标加方括号的方式进行访问。
    cout << s2[0] << endl;
}
