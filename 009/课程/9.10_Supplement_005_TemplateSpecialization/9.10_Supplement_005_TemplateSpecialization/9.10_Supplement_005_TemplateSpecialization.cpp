// 9.10_Supplement_005_TemplateSpecialization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这里补充了书上p389的关于模板特化的例子。

#include <iostream>
#include <cassert>
#include "Stack.h"
using namespace std;

template<>
class Stack<bool, 32>
{
    public:
    Stack();
    void push(bool item);
    bool pop();
    bool peek();
    void clear();
    bool isEmpty();
    bool isFull();

    private:
    unsigned list;
    int top;
};
//在对特化模板进行函数定义时，不要在前面加“template<>”。
Stack<bool, 32>::Stack():
    top(-1), list(0)
{}

void Stack<bool, 32>::push(bool item)
{
    assert(!isFull());
    top++;
    //注意，这里我写的时候只写了“list << 1”。“<<”操作符是不会直接对原值进行改变的，因此必须将计算结果赋给list。
    list = list << 1;
    //“|”也和上面是一个道理。
    list = list | (item ? 1 : 0);
}

bool Stack<bool, 32>::pop()
{
    assert(!isEmpty());
    bool value = list & 1;
    top--;
    list = list >> 1;
    return value;
}

bool Stack<bool, 32>::peek()
{
    assert(!isEmpty());
    return list & 1;
}

void Stack<bool, 32>::clear()
{
    top = -1;
    list = 0;
}

bool Stack<bool, 32>::isEmpty()
{
    return top == -1;
}

bool Stack<bool, 32>::isFull()
{
    return top == 32;
}

int main()
{
    Stack<bool, 32> s;
    const int LENGTH = 4;
    for(int i = 0; i < LENGTH; i++)
    {
        bool a = i % 2;
        s.push(a);
    }
    for(int i = 0; i < LENGTH; i++)
    {
        cout << s.peek() << '\t';
        cout << s.pop() << '\t';
        cout << endl;
    }
    cout << endl;
}
