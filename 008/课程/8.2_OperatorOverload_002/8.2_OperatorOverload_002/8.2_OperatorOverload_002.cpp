// 8.2_OperatorOverload_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//将单目运算符重载为类的成员函数。
//由于单目运算符的区别在于运算符在操作数的左侧还是右侧，而这一点是无法直接在成员函数中表现的。
//因此，需要通过重载运算符时的参数来区分单目运算符是左侧还是右侧。

#include <iostream>
using namespace std;

class Clock
{
    public:
    Clock(int h, int m, int s)
    {
        if(h > 0 && h < 24 && m > 0 && m < 60 && s > 0 && s < 60)
        {
            hour = h;
            minute = m;
            second = s;
        }
        else
        {
            cout << "Time Error!" << endl;
        }
    }

    void showTime() const
    {
        cout << hour << ":" << minute << ":" << second << endl;
    }
    //这是前置++的重载，此时不需要有形参。
    Clock& operator ++()
    {
        //注意秒数加一后要看时间是否需要需要进位。
        second++;
        if(second == 60)
        {
            second -= 60;
            minute++;
            if(minute == 60)
            {
                minute -= 60;
                hour = (hour + 1) % 24;
            }
        }
        return *this;
    }
    //这是后置++的重载。由于前置++和后置++的函数名是一样的，不能但从返回类型来区分重载，因此必须为后置++的重载添加一个参数，以作区分。在函数体中，不应该使用这个参数。
    //在这里我们可以看到后置++的实现是将计算前的值先做了一份拷贝，然后进行计算，最后返回拷贝对象。
    //返回值体现了前置和后置++的又一个区别。前置++返回的是对象自身的引用，对其进行操作会影响对象自身的值；而后置++返回的是一个拷贝，对其进行操作不会影响对象自身的值。
    //前置++返回的是左值，后置++返回的是右值（因为是右值，所以不能返回引用）。
    Clock operator ++(int)
    {
        Clock old = *this;
        //在这里直接利用前置++的运算，避免代码重复。
        ++(*this);
        return old;
    }

    private:
    int hour, minute, second;
};

int main()
{
    Clock myClock(23, 59, 59);
    cout << "First time output: ";
    myClock.showTime();
    cout << "Show myClock++: ";
    (myClock++).showTime();
    cout << "Show ++myClock: ";
    (++myClock).showTime();

    cout << "Show ++(++(myClock++)): ";
    //此处就可以看出，后置++返回的是一个拷贝对象，而非对象本身。
    //myClock++返回未++前的拷贝对象（返回的同时对象本身执行了++操作，值为0:0:2），根据前后代码可以知道此时返回的值为0:0:1。
    //再对这个拷贝对象执行两次前置++操作，可知此时拷贝对象的值为0:0:3。
    (++(++(myClock++))).showTime();
    cout << "Show myClock: ";
    myClock.showTime();
} 