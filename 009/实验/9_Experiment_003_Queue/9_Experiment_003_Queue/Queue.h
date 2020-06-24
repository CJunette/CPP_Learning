#pragma once

//为了适应Queue中的功能要求，我在LinkedList类里新增了frontData()函数。
#include "LinkedList.h"
#include <cassert>

template<class T>
class Queue
{
	public:
	Queue();
	void insert(const T &item);
	T remove();
	void clear();
	const T &getFront() const;

	int getLength() const;
	bool isEmpty() const;

	private:
	LinkedList<T> list;
	int count;
};

template<class T>
Queue<T>::Queue():
	count(0)
{}

template<class T>
void Queue<T>::insert(const T &item)
{
	list.insertRear(item);	
	count++;
}

template<class T>
T Queue<T>::remove()
{
	assert(!isEmpty());
	count--;
	return list.deleteFront();
}

template<class T>
void Queue<T>::clear()
{
	list.clear();
}

template<class T>
const T &Queue<T>::getFront() const
{
	return list.frontData();
}

template<class T>
int Queue<T>::getLength() const
{
	return count;
}

template<class T>
bool Queue<T>::isEmpty() const
{
	return count == 0;
}