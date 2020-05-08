// 6.3_ArrayAsParameter_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

//注意，将数组作为形参时，实参需要直接传入数组名。
//也就是说，实参会直接传数组的首地址给函数。
//由于是直接对地址的访问，因此函数中对数组成员的变化操作都会直接作用到实参的数组成员中。

void arrayFun(int a[])
{
    a[0]++;
}

void constArrayFun(const int a[])
{
    //1.当形参为const时，函数不能改变数组内成员的值。（暂时不考虑指针数组）
    cout << a[0] << endl;
}

int main()
{
    int a[] = { 1, 2, 3 };
    const int b[] = { 1, 2, 3 };
    
    arrayFun(a);
    //2.常数组不能作为形参不是常数组的函数的实参。
    /*
    arrayFun(b);
    */

    //3.一般数组可以作为形参是常数组的函数的实参。
    constArrayFun(b);
    constArrayFun(a);
}
