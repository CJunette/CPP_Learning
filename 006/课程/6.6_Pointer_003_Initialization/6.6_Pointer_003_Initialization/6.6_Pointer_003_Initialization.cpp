// 6.6_Pointer_003_Initialization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这是课上举的例子。

#include <iostream>
using namespace std;

int main()
{
    int i;
    int *ptr = &i;
    i = 10;
    cout << "i = " << i << endl;
    cout << "*ptr = " << *ptr << endl;

    cout << endl;

    //注意，不能定义void类型的变量，只能定义void类型的指针。
    /*
    void object
    */
    void *pv;
    int j = 5;
    pv = &j;
    //注意，void类型的指针是不能直接寻址访问的，必须通过类型转换变成明确类型的指针才可以实现寻址访问。
    cout << "*pv after cast: " << *static_cast<int *>(pv) << endl;
    //如果在转换指针时弄错数据类型，虽然程序不会报错，但是得到的值会出现错误。
    cout << "*pv after cast: " << *static_cast<double *>(pv) << endl;

}
