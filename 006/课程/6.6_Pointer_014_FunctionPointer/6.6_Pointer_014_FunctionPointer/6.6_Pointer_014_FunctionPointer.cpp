// 6.6_Pointer_014_FunctionPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这是老师课上给出的一个例子，我觉得这个例子虽然没有很好的展现出函数指针是怎么被定义并赋值的，但展示了一个很好的函数指针的使用情景，即函数回调。
//函数回调就是指用函数指针去调用函数。

#include <iostream>
using namespace std;

int sum(int a, int b)
{
    return a + b;
}
int min(int a, int b)
{
    return (a < b) ? a : b;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

//这里就体现出了函数指针的优势。当我希望一个函数（调用者）实现多个功能，且这些功能实际所需要的参数类型和个数都相同时，就可以用函数指针实现将这三个功能分配到其他三个独立的函数中去完成。
//调用者不需要知道被调用者具体是谁（具体使用时，写代码的人会明确谁是被调用者），只要知道被调用者符合某些特定的形式。在处理相似事件时可以灵活地使用不同的方法。
//相比于单独写三个独立的函数，这样做的优势在于它将类似的函数进行了统一。在保证了使用的简单的同时也保证了功能的明确。

//这里必须注意，在函数指针作为参数的时候，除了“*函数名”之外还必须写明其参数列表。
//顺便说一句，这里的形参列表真的没什么必要写具体的参数名。
int compute(int(*funcPtr)(int, int), int a, int b)
{
    return funcPtr(a, b);
}

int main()
{
    cout << "Please input 2 number:" << endl;
    int a, b;
    cin >> a;
    cin >> b;
    //这里在将具体的函数作为实参传入时，也只需要用函数名即可，后面不需要加形参列表；有没有“&”都可以。
    cout << "The sum of " << a << " and " << b << " is " << compute(sum, a, b) << "." << endl;
    cout << "The min of " << a << " and " << b << " is " << compute(min, a, b) << "." << endl;
    cout << "The max of " << a << " and " << b << " is " << compute(max, a, b) << "." << endl;
}
