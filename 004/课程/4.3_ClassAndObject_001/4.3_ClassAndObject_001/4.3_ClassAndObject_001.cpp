// 4.3_ClassAndObject_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//类体必须写在主函数前，不然主函数中无法识别类。
class Clock
{
    //在类体的最开头定义私有成员的话，会默认访问级别为private。

    //任何外部函数都可以访问public成员。
    public:

    //类函数允许声明带重载或带默认参数的函数。
    void setTime(int newH, int newM, int newS);

    //类函数可以直接写在函数体内，变成内联函数。
    //内联函数不要有复杂结构。
    void showTime()
    {
        cout << hour << ":" << minute << ":" << second;
    }

    //只有类内的成员才能访问private成员。（第5章会讲到友元是例外，可以实现授权外部函数访问私有成员。）
    private:
    //类内初始值。当构造函数没有对这些成员进行初始化，就会用类内初始值作为这些成员的初始值。
    //如果没有类内初始值，构造函数也没有对成员初始化，那么成员的初始值就是垃圾值。
    int hour = 0, minute = 0, second = 0;

};

int main()
{
    Clock myClock;
    int hour, minute, second;
    cout << "Please input hour: ";
    cin >> hour;
    cout << "Please input minute: ";
    cin >> minute;
    cout << "Please input second: ";
    cin >> second;
    myClock.setTime(hour, minute, second);
    myClock.showTime();

}

//类函数也可以在函数外实现，但要保证函数名前加上了“类名::”。
//这里也可以在前面加“inline”使其变成内联函数。
void Clock::setTime(int newH, int newM, int newS)
{
    hour = newH;
    minute = newM;
    second = newS;
}
