// 10.6_AssociativeContainer_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//要求从五门学分不同的课中选出三门，计算出学分总和。

#include <iostream>
#include <map>
#include <utility>
using namespace std;

int main()
{
    map<string, int> course;
    //1.make_pair是<utility>头文件中的函数，可以用于快速地构建pair类型的对象（用构造函数的话，还需要填写模板参数，就会比较费时）。
    course.insert(make_pair("CSAPP", 3));
    course.insert(make_pair("C++", 2));
    course.insert(make_pair("CSARCH", 4));
    course.insert(make_pair("COMPILER", 4));
    course.insert(make_pair("OS", 4));
    //0.选课次数n设置为3。
    int n = 3;
    int sum = 0;
    while(n > 0)
    {
        cout << "Please input a class name: ";
        string name;
        cin >> name;
        //2.map类的成员函数find()在未找到对象时，会返回.end()迭代器。
        if(course.find(name) == course.end())
        {
            cout << name << " is not available." << endl;
            continue;
        }
        sum += (*course.find(name)).second;
        //3.注意！在完成学分累加后，要把课程从map中删除！避免第二次输入相同的名字，导致“重复选课”的发生。
        course.erase(name);
        cout << "current credit: " << sum << endl;
        n--;
    }
    cout << "total credit: " << sum << endl;
}
