#pragma once

#include "LinkedList.h"

template<class T>
class OrderList
{
	public:
	OrderList();
	OrderList(const OrderList &ol);
	void insert(const T &item);
	void insert(const OrderList& ol);
	T &data();
	void next();
	void reset(int pos = 0);
	int getSize() const;

	private:
	LinkedList<T> list;
};

template<class T>
OrderList<T>::OrderList()
{}


template<class T>
OrderList<T>::OrderList(const OrderList &ol):
	list(ol.list)
{}

template<class T>
void OrderList<T>::insert(const T &item)
{
	list.reset();
	while(!list.endOfList())
	{
		if(list.data() < item)
		{
			list.next();
		}
		else
		{
			break;
		}
	}
	list.insertBefore(item);	
}

template<class T>
void OrderList<T>::insert(const OrderList &ol)
{
	int n = ol.getSize();
	OrderList temp = ol;
	temp.reset();
	for(int i = 0; i < n; i++)
	{
		insert(temp.data());
		temp.next();
	}
}

template<class T>
T & OrderList<T>::data()
{
	return list.data();
}

template<class T>
void OrderList<T>::next()
{
	list.next();
}

template<class T>
void OrderList<T>::reset(int pos)
{
	list.reset(pos);
}
template<class T>
int OrderList<T>::getSize() const
{
	return list.getSize();
}
