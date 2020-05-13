// 6.12_String_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//课上给出的一个对string运算符的测试的示例。

#include <iostream>
using namespace std;

inline void test(string s, bool b)
{
    cout << s << " returns " << (b ? "True" : "False") << endl;
}

int main()
{
    string s1 = "DEF";
    cout << "s1 is " << s1 << endl;
    
    string s2;
    cout << "Please enter s2: ";
    cin >> s2;
    cout << "Length of s2: " << s2.length() << endl;

    test("s1 <= \"ABC\"", s1 <= "ABC");
    test("\"DEF\" <= s1", "DEF" <= s1);

    s2 += s1;
    cout << "s2 = s2 + s1: " << s2 << endl;
    cout << "Length of s2: " << s2.length() << endl;
}
