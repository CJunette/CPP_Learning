#pragma once
#include <cassert>

template<class T, int SIZE = 50>
class Stack
{
	public:
	Stack();
	void push(const T &item);
	T pop();
	const T &peek();
	void clear();
	bool isEmpty();
	bool isFull();

	private:
	T list[SIZE];
	int top;
};

template<class T, int SIZE>
Stack<T, SIZE>::Stack():
	top(-1)
{}

template<class T, int SIZE>
void Stack<T, SIZE>::push(const T &item)
{
	assert(!isFull());
	list[++top] = item;
}

template<class T, int SIZE>
T Stack<T, SIZE>::pop()
{
	assert(!isEmpty());
	return list[top--];
}

template<class T, int SIZE>
const T &Stack<T, SIZE>::peek()
{
	assert(!isEmpty());
	return list[top];
}

template<class T, int SIZE>
void Stack<T, SIZE>::clear()
{
	top = -1;
}

template<class T, int SIZE>
bool Stack<T, SIZE>::isEmpty()
{
	return top == -1;
}

template<class T, int SIZE>
bool Stack<T, SIZE>::isFull()
{
	return top == SIZE;
}