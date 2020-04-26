// 4.8_Struct_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

//结构体与类基本相同。唯一的区别是结构体的默认访问控制属性为public，而类的默认访问控制属性为private。
struct Student
{
    int num;
    string name;
    char sex;
    int age;
};

int main()
{
    //结构体与类的初始化方式略有不同。结构体用“{}”，类用“()”。
    Student stu = { 97001, "Lin Lin", 'F', 19 };
    cout << "Num: " << stu.num << endl;
    cout << "Name: " << stu.name << endl;
    cout << "Sex: " << stu.sex << endl;
    cout << "Age: " << stu.age << endl;
}

