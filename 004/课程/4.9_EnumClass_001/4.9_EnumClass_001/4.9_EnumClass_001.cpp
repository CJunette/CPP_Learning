// 4.9_EnumClass_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//使用枚举类型相较于使用枚举，有以下好处。

//枚举类定义还可以定义底层类型名（基类），默认的底层类型是int。
enum class TypeInt {GENERAL, LIGHT, MEDIUM, HEAVY};
//如果用char为底层类型，在没有给默认初始值的情况下，应该是从ascii表的第0位开始的。（如果有8个元素，第8个元素就会对应输出ascii第8位的“响铃”）
enum class TypeChar : char {GENERAL = 'A', LIGHT, MEDIUM, HEAVY};

int main()
{
    TypeInt tpit(TypeInt::LIGHT);
    TypeChar tpch(TypeChar::MEDIUM);

    //注意这里要进行一下类型转换才能正常输出。
    cout << static_cast<int>(tpit) << endl;
    cout << static_cast<char>(tpch) << endl;
}

