// 6.6_Pointer_011_PointerFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这是课上举的一个指针函数返回动态分配地址的例子。因为举这个例子的时候还没学过动态分配，所以不用太过较真。

#include <iostream>
using namespace std;

int *newIntVar()
{
    //1.这里的new int()就是一个动态内存分配的过程。    
    int *p = new int();
    return p;
}

int main()
{
    int *intptr;
    {        
        //3.但动态内存分配是一个很容易造成内存泄漏的东西。
        //3.如果我把“*intptr”声明在这个块内，那么当离开这个块时，*intptr这个变量就会失效，而动态内存分配的地址因为失去了对应的标识符就无法被主动释放，造成内存泄漏。
        //3.因此在使用动态内存分配是要谨慎，同时也必须设计好分配内存和释放内存的功能。
        intptr = newIntVar();
        *intptr = 5;
    }
    cout << *intptr << endl;
    //2.动态内存分配返回的地址在离开对应变量的作用域后并不会被自动释放，必须通过delete来主动释放。
    delete intptr;
}
