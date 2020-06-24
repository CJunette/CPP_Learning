#pragma once

#include <cassert>
#include "LinkedList.h"
#include "Node.h"

template<class T>
class Stack
{
	public:
	Stack();
	void push(const T &item);
	T pop();
	void clear();
	const T &peek() const;
	bool isEmpty();

	private:
	int count;
	LinkedList<T> list;
};

template<class T>
Stack<T>::Stack():
	count(0)
{}

template<class T>
void Stack<T>::push(const T &item)
{	
	list.insertFront(item);
	count++;
}

template<class T>
T Stack<T>::pop()
{
	assert(!isEmpty());
	count--;
	return list.deleteFront();
}

template<class T>
void Stack<T>::clear()
{
	list.clear();
	count = 0;
}

template<class T>
const T &Stack<T>::peek() const
{
	return list.frontData();
}

template<class T>
bool Stack<T>::isEmpty()
{
	return count == 0;
}