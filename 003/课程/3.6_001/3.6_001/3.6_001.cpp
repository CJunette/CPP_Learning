// 3.6_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void Out(int i)
{
    cout << ++i << endl;
    cout << "The address inside funciton is " << &i << " ." << endl;
}

void AddressOut(int &i)
{
    cout << ++i << endl;
    cout << "The address inside funciton is " << (void *)i << " ." << endl;
}

int main()
{
    int i = 10;
    int &ti = i;

    //&符号所做的操作就是直接访问地址。
    //这里可以看出输出ti得到的是个具体值。
    cout << ti << endl;    
    //输出&ti和&i实际都是输出i所在的地址。
    cout << &ti << endl;
    cout << &i << endl;
    //用(void *)进行强制类型转换后才能实现对指针所在地址的输出。
    cout << (void*)ti << endl;
    cout << endl;

    //如果主调函数中的参数是一个普通的参数，则函数在运行时一定会为这个参数创建一个副本。
    //可以看到，函数内部输出的地址和函数外部输出的地址是不同的。
    Out(i);
    cout << i << endl;
    cout << "The address outside funciton is " << &i << " ." << endl;
    //如果实参是个指针，则会创建指针指向对象的副本并复制值。
    Out(ti);
    cout << ti << endl;
    cout << "The address outside funciton is " << &ti << " ." << endl;
    cout << endl;

    //重新把i的值复位。
    i = 10;

    //如果主调函数中的参数是一个引用类型的参数，则函数在运行时不会创建副本，而是直接使用这个引用参数指向的地址。
    //可以看到，函数内部输出的地址与外部输出的地址是完全相同的。
    AddressOut(i);
    cout << i << endl;
    cout << "The address outside funciton is " << (void*)i << " ." << endl;
    AddressOut(ti);
    cout << ti << endl;
    cout << "The address outside funciton is " << (void*)ti << " ." << endl;
    cout << endl;
    
}