// 6.6_Pointer_009_PointerFunction.cpp : This file contains the 'main' function. Program execution begins and ends there.
//定义指针类型的函数时，不要把非静态的局部地址用作函数的返回值。
//因为函数执行完毕后，其中的局部变量的作用域也就结束了，它们对应的局部地址也就失效了。
//返回这样一个已经失效的地址，并让程序在之后有机会去对其进行访问时很危险的。

#include <iostream>
using namespace std;

int num = 0;

int main()
{
    //1.之前我都不知道主函数中还能做函数的的声明。
    int *danger();
    int *ptr = danger();
    //1.这种离开作用域还能访问地址的做法十分危险！
    *ptr = 5;
    //1.可以看到，在上一行代码中ptr中存储的值还是确定的；下一行代码中想要输出时，ptr中存储的值就发生了改变。
    cout << ptr << endl;
    cout << *ptr << endl;

    //2.指针函数应该返回的地址是到了主调函数中仍然合法、有效的地址。
    //2.像这样，向函数送入一个数组名，然后返回的地址就是数组范围内的地址。这样的操作就属于安全的操作。
    int *safe(int a[]);
    int a[] = { 1, 2, 3 };
    int *b = safe(a);
    cout << b << endl;
    cout << *b << endl;

    //3.虽然指针函数返回一个静态指针的做法是可行的，但这样的操作实际上没什么大意义，基本就和返回了一个静态变量是一个道理。
    int *safeGlobe();
    int *c = safeGlobe();
}

//1.指针函数返回局部地址的一个错误的实例。
int *danger()
{
    int local = 0;
    //1.这里就把局部变量的地址返回了，十分危险！
    return &local;
}

//2.指针函数应该返回合法的地址。
//2.如，在形参中要求主调函数提供一个存有合法地址的指针，返回的地址是在那个指针周围的合法地址；或，返回的地址是一个静态指针（或全局指针，只要生存期是静态生存期即可）的地址;或，由动态内存分配所取得的内存地址。
int *safe(int a[])
{
    return &a[2];
}

int *safeGlobe()
{
    static int *ptrStatic = &num;
    return ptrStatic;
}