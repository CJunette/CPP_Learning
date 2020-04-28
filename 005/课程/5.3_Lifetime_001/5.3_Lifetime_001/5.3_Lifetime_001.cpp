// 5.3_Lifetime_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//静态生存期，指生存期与函数运行时间相同。
//在文件作用域中声明的对象（全局变量、类）或在函数内部用static修饰的对象，其生存期都是静态生存期。
int i = 1;
//下面这个类只是举例，没有用到。
class test{};

void other()
{
    //静态生存期，局有全局寿命，只在第一次进入函数时会被声明及初始化。
    static int a = 2;
    //静态变量即使没有初始化赋值，也会有默认值。这里b的默认值是0，char类型静态变量的默认值是ascii表的第0位。这与动态变量默认值是垃圾值不同。
    static int b;
    
    //动态生存期，开始于声明点，结束于作用域结束处。每次进入函数都会进行一次初始化。
    int c = 10;
    a += 2;
    i += 32;
    c += 5;
    cout << "---OTHER---\n";
    cout << "i: " << i << ", a: " << a << ", b: " << b << ", c: " << c << ".\n";
    b = a;
    //这一步不会影响下一次调用other()时c的值，因为c是动态生存期的变量，每次进入other()函数都会重新被初始化。
    c += 5;
}

int main()
{
    //这里声明了a、b、c，也就是说当主函数调用other()时，other()中的a、b、c作为内层声明的变量，会导致外层声明的a、b、c（此处的a、b、c）不可见。
    //静态生存期的变量和动态生存期的变量的存储位置是不同的。
    static int a;
    int b = -10;
    int c = 0;

    cout << "---MAIN---" << endl;
    cout << "i: " << i << ", a: " << a << ", b: " << b << ", c: " << c << ".\n";
    c += 8;

    other();

    cout << "---MAIN---" << endl;
    cout << "i: " << i << ", a: " << a << ", b: " << b << ", c: " << c << ".\n";
    i += 10;

    //这一次在调用other()时，其中的a与b不会再被重新声明一次，因此那两行语句声明语句会被直接跳过。
    //而c因为是局部变量，是动态生存期而非静态生存期，因此每次进入函数都会进行一次初始化。
    other();
    
    //这里可以看到，char类型静态变量的默认值是ascii表的第0位
    static char A;
    cout << static_cast<char>(A + 7) << endl;
}

