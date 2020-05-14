// 6.12_String_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//C++风格的字符串，string类。
//根据书上p231，string类是类模板basic_string的一个特化实例。但是使用时可以把它当做一个类。

#include <iostream>
using namespace std;

int main()
{
    //1.“string”类的默认构造函数创建的是长度为0的字符串。但如果之后对字符串进行重新赋值，string的长度会随之发生改变。
    string s0;
    s0 = "abc";

    //2.string类可以用一个常量字符串对新的字符串进行初始化。string(const char *s);
    string s1("cde");
    //2.上述写法也等同于下面这种写法。这个写法其实是隐式地将常字符数组（C++中默认的字符串常量类型为常字符数组）转换为了string类型。
    //2.可以这么做的原因是，string类有可以接受const char*的构造函数，可以将字符串常量和字符数组转换为string对象（书上p231）。
    string s1_1 = "CDE";
    //2.上述写法还有更复杂的形式。string(const char *s, unsigned int n);表示从取字符串常量s的前n个字符。
    string s1_2("cde", 2);

    //3.string类可以用一个现有string变量来初始化新的字符串（复制构造函数）。string(const string &s);
    string s2(s1);
    //3.上面的这个初始化方法还有更复杂的形式。string(const &rhs, unsigned int pos, unsigned int n);表示在字符串rhs从pos开始取n个字符，用于初始化新的string类对象。
    string s3(s2, 1, 1);

    //4.string类可以通过重复多个字符来对初始化新的string变量。string(unsigned int n, char c);
    string s4(4, 'c');

    //5.string类的运算。其实本质是在string类中对这些运算符进行了重载。
    //5.加法运算用于拼接两个字符串。
    cout << s0 + s1 << endl;
    //5.“==”用于判断两个字符串是否相等。对大小写敏感。
    cout << (s1_1 == s1) << endl;

    //5.“=”用于用一个字符串给另一个字符串赋值。
    cout << s2 << endl;
    s2 = s0;
    cout << s2 << endl;
    
    //5.关系运算用于逐个比较字符串中的字符的ascii码大小，只要不相等就返回。
    cout << (s1_1 > s1) << endl;

    //5.字符串也可以用下标加方括号的方式进行访问。
    cout << s2[0] << endl;
}
