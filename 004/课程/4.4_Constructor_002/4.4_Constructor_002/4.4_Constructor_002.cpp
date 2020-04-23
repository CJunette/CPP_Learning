// 4.4_Constructor_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Clock
{
    public:
    Clock(int newH, int newM, int newS) :
        hour(newH), minute(newM), second(newS)
    {}
    
    //在有一个带参数的构造函数的情况下，再写一个默认的构造函数，当初始化没有提供参数时，会调用这个函数。如果不写这个默认构造函数，则在初始化对象时会要求必须提供3个参数。
    //这种构造函数其实就是一个构造函数的函数重载。
    Clock();

    //注意，下面的两种写法是不同的。
    
    //这种写法是在一个有参数构造函数的基础上，又写了一个无参数的构造函数。在定义无参数构造函数时，需要初始化hour、minute、second这些参数。
    /*
    Clock(int newH, int newM, int newS)；
    Clock();
    */

    //而这种写法是在一个有参数构造函数的基础上，又写了一个默认的构造函数。这个默认构造函数无需定义，且hour、minute、second的值都是垃圾值。
    //一般情况下，当程序中写明了构造函数时，编译器就不会再生成默认构造函数了，对象初始化也会全部按已写明的构造函数来进行。如果创建对象时没有提供参数就会报错。
    //这样的写法保证了创建对象时没有提供参数的情况下，也能有一个构造器去进行初始化。
    /*
    Clock(int newH, int newM, int newS) :
    Clock() = default;
    */


    void setTime(int newH, int newM, int newS)
    {
        hour = newH;
        minute = newM;
        second = newS;
    }
    void showTime()
    {
        cout << hour << ":" << minute << ":" << second << endl;
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
    Clock myClock1(hour, minute, second);
    myClock1.showTime();
    Clock myClock2;
    myClock2.showTime();
}


Clock::Clock() :
    hour(0), minute(0), second(0)
{}