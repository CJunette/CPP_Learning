// 4.4_Constructor_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Clock
{   
    public:   
    //定义构造函数
    //构造函数要求与类名相同；不能定义返回值类型，也没有return语句；可以内联；可以重载；可以带默认参数。

    //如果程序中已经存在了一个带参数的构造函数了，但我们还希望它有一个默认构造函数，则可以写成以下这种写法。    
    Clock(int newH, int newM, int newS);
    Clock() = default;
    //默认的构造函数写法还有“Clock()”，如果类内没有定义构造器，编译器就会自动生成默认的构造函数。
    //默认初始化会使类内的基本成员初始值不确定（垃圾数据），类内的其他类成员的初始值有对应类的初始化决定。


    //要注意，如果上述的带参数的构造函数所有的形参都有默认值的话，他就自然地变成了一个默认构造函数。这时如果再在后面写“Clock()=default”，就会让编译器产生混淆，导致报错。
    //即，如下写法是错误的。
    /*
    Clock(int newH = 0, int newM = 0, int newS = 0);
    Clock() = default;
    */

    void setTime(int newH, int newM, int newS);
    void showTime()
    {
        cout << hour << ":" << minute << ":" << second;
    }

    private:
    int hour, minute, second;

};

int main()
{
    
    int hour, minute, second;
    cout << "Please input hour: ";
    cin >> hour;
    cout << "Please input minute: ";
    cin >> minute;
    cout << "Please input second: ";
    cin >> second;
    Clock myClock(hour, minute, second);
    myClock.showTime();

}

void Clock::setTime(int newH, int newM, int newS)
{
    hour = newH;
    minute = newM;
    second = newS;
}

//这是一种简单的初始化方式。这种简单的赋值语句可以替换在函数体中写“hour = newH;”这样的语句，且效率更高。
//这种初始化方式似乎只能用在构造器上，不能用在其他的函数上。
Clock::Clock(int newH, int newM, int newS) :
    hour(newH), minute(newM), second(newS)
{};