// 4.9_EnumClass_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//使用枚举类型相较于使用枚举，有以下好处。
//1.强作用域，即任何情况下使用enum类的值都必须加类名，如下面的TypeInt::LIGHT。如过是普通enum的话，直接使用LIGHT即可，但那样做可能会造成不同名称的冲突。
//2.转换限制，即现在不能隐式地将枚举类型转换成整数。
//3.可以指定底层类型。

//枚举类定义还可以定义底层类型名（基类），默认的底层类型是int。
enum class TypeInt {GENERAL, LIGHT, MEDIUM, HEAVY};
//如果用char为底层类型，在没有给默认初始值的情况下，应该是从ascii表的第0位开始的。（如果有8个元素，第8个元素就会对应输出ascii第8位的“响铃”）
enum class TypeChar : char {GENERAL = 'A', LIGHT, MEDIUM, HEAVY};

enum class Side{LEFT, RIGHT};
enum class Judge{WRONG, RIGHT};
int main()
{
    TypeInt tpit(TypeInt::LIGHT);
    TypeChar tpch(TypeChar::MEDIUM);

    //注意这里要进行一下类型转换才能正常输出。
    cout << static_cast<int>(tpit) << endl;
    cout << static_cast<char>(tpch) << endl;

    Side s = Side::RIGHT;
    Judge j = Judge::RIGHT;
    //由于枚举类型不能隐式地转换成整型，因此下面这行代码会因为将两个不同类型的对象进行比较而直接报错。
    /*
    cout << (s == j) << endl;
    */
}

