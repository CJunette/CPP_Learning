// 7.2_Inheritance_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//继承的语法（单继承）
//class 派生类名: 继承方式 基类名
//{ 成员声明; };
//其中的“继承方式”以后会讲到。
class Base
{};

class Derived : public Base
{
    public:
    Derived();
    ~Derived();
};

//多继承时的语法
//class 派生类名：继承方式1 基类名1, 继承方式2, 基类名2, ...
class Base1
{};
class Base2
{};
class Derived1 : public Base1, private Base2
{
    public:
    Derived1();
    ~Derived1();
};

//派生类的构成包括
//1.吸收基类的成员
//2.改造基类的成员
//3.添加新的成员

//吸收基类成员
//1.默认情况下派生类包含基类中除构造函数和析构函数以外的所有成员。也就是原封不动的继承。（不受访问权限影响？还是只有public会被继承？还是说和继承方式有关？）
//2.C++11规定可以用using语句继承基类构造函数。

//改造基类成员
//在派生类中声明一个与基类成员同名的新成员，派生的新成员就覆盖了基类的成员。

//添加新成员
//通过添加新成员，使派生类在功能上有所发展。

int main()
{
    std::cout << "Hello World!\n";
}
