#pragma once

#include <cassert>

template<class T, int SIZE = 50>
class Queue
{
	private:
	int front, rear, count;
	T queue[SIZE];

	public:
	Queue();
	void insert(const T &item);
	T remove();
	void clear();
	const T &getFront() const;
	int getLength() const;
	bool isEmpty() const;
	bool isFull() const;
};

template<class T, int SIZE>
Queue<T, SIZE>::Queue():
	front(0), rear(0), count(0)
{}

template<class T, int SIZE>
void Queue<T, SIZE>::insert(const T& item)
{
	assert(!isFull());
	//1.先向队尾存入对象，再将队尾+1。
	queue[rear] = item;
	//1.通过对SIZE取余来实现循环。
	rear = (rear + 1) % SIZE;
	count++;
}

template<class T, int SIZE>
T Queue<T, SIZE>::remove()
{
	assert(!isEmpty());
	//2.这里我自己写的时候是直接让temp成为T类型的，并复制queue[front]的对象。
	//2.但从程序设计的角度看，因为queue内的成员并没有被马上删除，且T的类型不确定，因此还是采用保存front的数值，然后在返回时返回queue[temp]的做法，能尽量减少复制对象带来的计算。
	int temp = front;
	//2.注意，因为是循环，所以队头也必须进行取余操作。
	front = (front + 1) % 50;
	count--;
	return queue[temp];
}

template<class T, int SIZE>
void Queue<T, SIZE>::clear()
{
	front = 0;
	rear = 0;
	count = 0;
}

template<class T, int SIZE>
const T &Queue<T, SIZE>::getFront() const
{
	return queue[front];
}

template<class T, int SIZE>
int Queue<T, SIZE>::getLength() const
{
	return count;
}

template<class T, int SIZE>
bool Queue<T, SIZE>::isEmpty() const
{
	return count == 0;
}

template<class T, int SIZE>
bool Queue<T, SIZE>::isFull() const
{
	return count ==SIZE;
}