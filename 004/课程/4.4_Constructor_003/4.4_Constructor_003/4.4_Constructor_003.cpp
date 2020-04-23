// 4.4_Constructor_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//委托构造函数

#include <iostream>
using namespace std;

class Clock
{
    public:
    Clock(int newH, int newM, int newS);
    Clock();

    void setTime(int newH, int newM, int newS)
    {
        hour = newH;
        minute = newM;
        second = newS;
    }

    void showTime()
    {
        cout << hour << ":" << minute << ":" << second;
    }

    private:
    int hour, minute, second;
};


int main()
{
    std::cout << "Hello World!\n";
}


Clock::Clock(int newH, int newM, int newS):
    hour(newH), minute(newM), second(newS)
{}


//这个就是委托构造函数。换言之，就是在一个构造函数中，利用另一个构造函数进行初始化。
//这里，在这个无参数的构造函数中，利用有参数的构造函数进行初始化。
//这里我还想到，是不是可以用setTime()来尝试进行初始化。但是结果是不行，编译器报错setTime()不属于非静态数据成员或类的基类成员。关于静态成员的内容还是等以后讲了以后再说吧。
Clock::Clock() :
    Clock(0, 0, 0)
{}