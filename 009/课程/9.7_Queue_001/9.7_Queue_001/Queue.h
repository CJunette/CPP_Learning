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
	//1.�����β��������ٽ���β+1��
	queue[rear] = item;
	//1.ͨ����SIZEȡ����ʵ��ѭ����
	rear = (rear + 1) % SIZE;
	count++;
}

template<class T, int SIZE>
T Queue<T, SIZE>::remove()
{
	assert(!isEmpty());
	//2.�������Լ�д��ʱ����ֱ����temp��ΪT���͵ģ�������queue[front]�Ķ���
	//2.���ӳ�����ƵĽǶȿ�����Ϊqueue�ڵĳ�Ա��û�б�����ɾ������T�����Ͳ�ȷ������˻��ǲ��ñ���front����ֵ��Ȼ���ڷ���ʱ����queue[temp]���������ܾ������ٸ��ƶ�������ļ��㡣
	int temp = front;
	//2.ע�⣬��Ϊ��ѭ�������Զ�ͷҲ�������ȡ�������
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