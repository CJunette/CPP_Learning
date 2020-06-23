// 9.10_Supplement_007_PartialTemplateSpecialization.cpp : This file contains the 'main' function. Program execution begins and ends there.
//书上P391的偏特化例子。

#include <iostream>
#include <cassert>
#include "Stack.h"
using namespace std;

template<int SIZE>
class Stack<bool, SIZE>
{
    private:
    //这里通过匿名枚举实现定义常量的目的。因为枚举值在编译时会进行计算，得到值。
    //同样的目的也可以通过定义一般的静态成员常量来实现。书上p391给出的理由是，以前编译器对静态成员常量的编译时求值支持的不好，所以人们习惯用枚举。
    enum { UNIT_BIT = sizeof(unsigned) * 8, ARRAY_SIZE = (SIZE - 1) / UNIT_BIT + 1 };
    int top;
    unsigned list[ARRAY_SIZE];

    public:
    Stack();
    void push(const bool &item);
    bool pop();
    const bool &peek();
    void clear();
    bool isEmpty();
    bool isFull();
};

template<int SIZE>
Stack<bool, SIZE>::Stack():
    top(-1)
{
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        list[i] = 0;
    }
}

template<int SIZE>
void Stack<bool, SIZE>::push(const bool &item)
{
    assert(!isFull());
    top++;
    //注意，这里使用的是UNIT_BIT，而不是ARRAY_SIZE。
    list[top / UNIT_BIT] <<= 1;
    list[top / UNIT_BIT] |= item;
}

template<int SIZE>
bool Stack<bool, SIZE>::pop()
{
    assert(!isEmpty());
    bool value = list[top / UNIT_BIT] & 1;
    list[top / UNIT_BIT] >>= 1;
    top--;
    return value;
}

template<int SIZE>
const bool &Stack<bool, SIZE>::peek()
{
    assert(!isEmpty());
    return list[top / UNIT_BIT] & 1;
}

template<int SIZE>
void Stack<bool, SIZE>::clear()
{
    top = -1;
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        list[i] = 0;
    }
}

template<int SIZE>
bool Stack<bool, SIZE>::isEmpty()
{
    return top == -1;
}

template<int SIZE>
bool Stack<bool, SIZE>::isFull()
{
    return top == SIZE - 1;
}

int main()
{
    Stack<bool, 64> s;
    const int length = 4;
    for(int i = 0; i < length; i++)
    {
        s.push(i % 2);
    }
    for(int i = 0; i < length; i++)
    {
        cout << s.peek() << '\t';
        cout << s.pop() << '\t';
        cout << endl;
    }
}
