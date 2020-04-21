// 3.8_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

const double PI = 3.14159265358979;
//“inline”是对内联函数的修饰。它是一个给编译器的提示符。
//编译器会根据这个函数的复杂程度来判断是否在编译时将这个函数作为内联函数使用。
//如果函数被作为内联函数使用，则这个函数在主程序中被使用时会用函数体里的语句来替换函数调用表达式。
//由此带来的好处是，由于没有函数调用过程，因此节省了主函数调用子函数的开销。
//（因为有些子函数长度太短，去调用一次函数甚至没有直接复制语句来的方便。）
inline double CalArea(double radius)
{
    return PI * radius * radius;
}

int main()
{   
    //与内联函数思路类似的就是Lambda表达式。C++中的Lambda表达式与C#中的Lambda表达式略有不同。
    //C++中的Lambda表达式
    auto calarea = [](double a) -> double {return PI * a * a; };  
    cout << calarea(2) << endl;

    cout << CalArea(2) << endl;   
}

