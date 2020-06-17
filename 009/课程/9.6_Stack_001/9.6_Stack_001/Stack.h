#pragma once

#include <cassert>

template<class T, int SIZE = 50>
class Stack
{
	private:
	T list[SIZE];
	//0.top代表栈顶。
	int top;
	public:
	Stack();
	//0.puch(const T &item)表示压入对象item。
	void push(const T &item);
	//0.pop()表示弹出栈顶对象。
	T pop();
	//0.peek()表示查看栈顶对象（但不弹出栈顶对象）。
	const T &peek() const;
	bool isEmpty() const;
	bool isFull() const;
	//0.clear()用于清空栈（但是从定义看，更像是将栈还原到空栈状态）。
	void clear();	
};

template<class T, int SIZE>
Stack<T, SIZE>::Stack<T, SIZE>():
	top(-1)
{}

template<class T, int SIZE>
void Stack<T, SIZE>::push(const T &item)
{
	//1.向内压入时，先判断栈是否为满，然后再将栈顶top上移一位，并将需要压入的对象item放入。
	assert(!isFull());
	list[++top] = item;
}

template<class T, int SIZE>
T Stack<T, SIZE>::pop()
{
	//2.向外弹出时，先判断当前栈是否为空，然后弹出栈顶top所在的对象，并将栈顶top下移一位。
	assert(!isEmpty());
	return list[top--];
}

template<class T, int SIZE>
const T &Stack<T, SIZE>::peek() const
{
	assert(!isEmpty());
	return list[top];
}

template<class T, int SIZE>
bool Stack<T, SIZE>::isEmpty() const
{
	return top == -1;
}

template<class T, int SIZE>
bool Stack<T, SIZE>::isFull() const
{
	return top == SIZE - 1;
}

template<class T, int SIZE>
void Stack<T, SIZE>::clear()
{
	//3.清空栈就是把栈顶还原到-1位置。
	top = -1;
}