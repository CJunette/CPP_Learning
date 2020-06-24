#pragma once

#include "Node.h"
#include <iostream>
using namespace std;

template<class T>
class LinkedList
{
	public:
	LinkedList();
	LinkedList(const LinkedList<T> &l);
	~LinkedList();
	LinkedList<T> &operator = (const LinkedList<T> &l);
	LinkedList<T> operator + (const LinkedList<T> &l);

	int getSize() const;
	bool isEmpty() const;

	void reset(int pos = 0);
	void next();
	bool endOfList() const;
	int currentPosition() const;

	void insertFront(const T &item);
	void insertRear(const T &item);
	void insertBefore(const T &item);
	void insertAfter(const T &item);

	T deleteFront();
	void deleteCurrent();

	T &data();
	const T &data() const;
	T &frontData();
	const T &frontData() const;

	void clear();

	private:
	Node<T> *front, *rear;
	Node<T> *currPtr, *prevPtr;
	int size, position;

	Node<T> *newNode(const T &item, Node<T> *next = 0);
	void freeNode(Node<T> *p);
	void copy(const LinkedList<T> &l);
};

template<class T>
Node<T> *LinkedList<T>::newNode(const T &item, Node<T> *next)
{
	Node<T> *p = new Node<T>(item, next);
	if(p == NULL)
	{
		cerr << "Memory allocation failed" << endl;
	}
	return p;
}

template<class T>
void LinkedList<T>::freeNode(Node<T> *p)
{
	delete p;
}

template<class T>
void LinkedList<T>::copy(const LinkedList<T> &l)
{
	Node<T> *p = l.front;
	if(p == NULL)
	{
		return;
	}
	while(p != NULL)
	{
		insertRear(p->data);
		p = p->nextNode();
	}
	//记得最后reset()一下。
	reset();
}

template<class T>
LinkedList<T>::LinkedList():
	front(NULL), rear(NULL), currPtr(NULL), prevPtr(NULL), size(0), position(-1)
{}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &l)
{
	//要注意，这里必须手动对这些值进行初始化，否则在函数返回LinkedList<T>调用复制构造函数时，会创造一个临时对象，该临时对象的这些指针都无法访问，进而导致内置的函数无法被调用。
	currPtr = prevPtr = NULL;
	front = rear = NULL;
	size = 0;
	position = -1;
	copy(l);

}

template<class T>
LinkedList<T>::~LinkedList()
{
	clear();
}

template<class T>
LinkedList<T> &LinkedList<T>::operator =(const LinkedList<T> &l)
{
	if(this == &l)
	{
		return *this;
	}
	clear();
	copy(l);
	return *this;
}

template<class T>
LinkedList<T> LinkedList<T>::operator +(const LinkedList<T> &l)
{
	LinkedList<T> temp = *this;
	if(l.isEmpty() == -1)
	{
	}
	else
	{
		Node<T> *p = l.front;
		while(p != NULL)
		{
			temp.insertRear(p->data);
			p = p->nextNode();
		}
	}
	temp.reset();
	return temp;
}

template<class T>
int LinkedList<T>::getSize() const
{
	return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
	return position == -1;
}

template<class T>
void LinkedList<T>::reset(int pos)
{
	if(front == NULL)
	{
		return;
	}
	if(pos < 0 || pos > size)
	{
		cerr << "Reset: Invalid list position: " << pos << endl;
		return;
	}

	position = 0;
	currPtr = front;
	prevPtr = NULL;

	if(pos == 0)
	{
		return;
	}
	else
	{
		while(position < pos)
		{
			next();
		}
	}

}

template<class T>
void LinkedList<T>::next()
{
	if(currPtr != NULL)
	{
		prevPtr = currPtr;
		currPtr = currPtr->nextNode();
		position++;
	}
}

template<class T>
bool LinkedList<T>::endOfList() const
{
	return currPtr == NULL;
}

template<class T>
int LinkedList<T>::currentPosition() const
{
	return position;
}

template<class T>
void LinkedList<T>::insertFront(const T &t)
{
	if(front != NULL)
	{
		reset();
	}
	insertBefore(t);
}

template<class T>
void LinkedList<T>::insertRear(const T &t)
{
	Node<T> *p = newNode(t);
	if(rear == NULL)
	{
		front = p;
	}
	else
	{
		rear->insertAfter(p);
		prevPtr = rear;
	}
	position = size;
	currPtr = rear = p;
	size++;
}

template<class T>
void LinkedList<T>::insertBefore(const T &t)
{
	Node<T> *p;
	if(prevPtr == NULL)
	{
		p = newNode(t, front);
		front = p;
		position = 0;
	}
	else
	{
		p = newNode(t, currPtr);
		prevPtr->insertAfter(p);
	}
	if(currPtr == NULL)
	{
		rear = p;
		position = size;
	}
	currPtr = p;
	size++;
}

template<class T>
void LinkedList<T>::insertAfter(const T &t)
{
	Node<T> *p = newNode(t);
	if(front == NULL)
	{
		front = rear = currPtr = p;
		position = 0;
	}
	else
	{
		if(currPtr == NULL)
		{
			currPtr = prevPtr;
		}
		if(currPtr == rear)
		{
			rear = p;
			position = size;
		}
		else
		{
			position++;
		}
		currPtr->insertAfter(p);
		prevPtr = currPtr;
		currPtr = p;
	}
	size++;
}

template<class T>
T LinkedList<T>::deleteFront()
{
	if(front == NULL)
	{
		cerr << "delete: Invalid delete!" << endl;
		exit(1);
	}
	T item = front->data;
	reset();
	deleteCurrent();
	return item;
}

template<class T>
void LinkedList<T>::deleteCurrent()
{
	Node<T> *p;
	if(currPtr == NULL)
	{
		cerr << "delete: Invalid delete!" << endl;
	}
	if(prevPtr == NULL)
	{
		p = front;
		front = front->nextNode();
	}
	else
	{
		p = prevPtr->deleteAfter();
	}
	if(currPtr == rear)
	{
		rear = prevPtr;
	}
	currPtr = p->nextNode();
	freeNode(p);
	size--;
}

template<class T>
T &LinkedList<T>::data()
{
	return const_cast<T &>(static_cast<const LinkedList<T> *>(this)->data());
}

template<class T>
const T &LinkedList<T>::data() const
{
	if(currPtr == NULL)
	{
		cerr << "data: Invalid reference!" << endl;
	}
	return currPtr->data;
}

template<class T>
T &LinkedList<T>::frontData()
{
	return const_cast<T &>(static_cast<const LinkedList<T> *>(this)->frontData());
}

template<class T>
const T &LinkedList<T>::frontData() const
{
	if(front == NULL)
	{
		cerr << "data: Invalid reference!" << endl;
	}
	return front->data;
}

template<class T>
void LinkedList<T>::clear()
{
	Node<T> *p = front;
	while(p != 0)
	{
		Node<T> *temp = p->nextNode();
		freeNode(p);
		p = temp;
	}
	currPtr = prevPtr = NULL;
	front = rear = NULL;
	size = 0;
	position = -1;
}