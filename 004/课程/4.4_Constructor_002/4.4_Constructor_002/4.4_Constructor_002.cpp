// 4.4_Constructor_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Clock
{
    public:
    Clock(int newH, int newM, int newS);
    //在有一个带参数的构造函数的情况下，在写一个默认的构造函数，当初始化没有提供参数时，会调用这个函数。
    Clock();
    void setTime(int newH, int newM, int newS);


    private:
    int hour, minute, second;
    

};

int main()
{
    
}
