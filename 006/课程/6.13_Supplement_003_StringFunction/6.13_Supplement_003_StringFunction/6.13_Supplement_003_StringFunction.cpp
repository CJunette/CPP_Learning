// 6.13_Supplement_003_StringFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这里补充一下书上p232的关于string成员函数的内容。这部分内容课上没有讲到。

#include <iostream>

using namespace std;

int main()
{
    string s1 = "abcd";

    //string append(const char *s); 将s所指的字符串添加在当前字符串尾。
    s1.append("efg");

    //string assign(const char *s); 赋值，将s所指的字符串的值赋给当前字符串。
    s1.assign("A");

    //int compare(const string & str) const; 比较当前字符串和str字符串，如果大于则返回1，小于则返回-1，等于则返回0。
    cout << s1.compare("a") << endl;

    //string &insert(unsigned int p0, const char *s); 将s所指的字符串插入当前字符串p0之前的位置。函数名前的&代表返回值是一个引用。
    s1.insert(0, "abcd");
    cout << s1 << endl;

    //string substr(unsigned int pos, unsigned int n) const; 取当前字符串从pos开始的n个字符，构成新的string类对象作为返回值。
    string s2 = s1.substr(0, 1);

    //unsigned int find(const basic_string &str) const; 查找并返回字符串str在当前字符串首次出现的位置。
    int p = s1.find("b");

    //unsigned int length() const; 返回当前字符串的长度。
    int l = s1.length();

    //void swap(string &str); 将当前字符串与str中的字符串进行交换。
    s1.swap(s2);
}
