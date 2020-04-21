// 3.10_FunctionWithDefaultParameter_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Add(int a = 1, int b = 2)
{
    return a + b;
}

//1.有默认值的参数必须被统一、集中地放在参数列表的最右侧，不能写(int a = 1, int b)，也不能写(int a = 1, int b, int c = 2)。
//2.如果函数定义在主函数前，则直接在定义时声明默认值。
//如果函数声明在主函数前，定义在主函数后，则需要在声明时就声明默认值。在定义时不能再次声明，否则会被认为重新定义了参数，导致编译错误。
//定义时也不能给之前没有默认参数的参数添加默认参数。
int Mul(int a, int b = 2);

int main()
{
    cout << Add(3, 4) << endl;
    cout << Add(2) << endl;
    cout << Add() << endl;

    cout << Mul(1);
}

int Mul(int a, int b)
{
    return a * b;
}