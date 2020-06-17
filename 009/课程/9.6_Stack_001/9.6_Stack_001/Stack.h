#pragma once

#include <cassert>

template<class T, int SIZE = 50>
class Stack
{
	private:
	T list[SIZE];
	//0.top����ջ����
	int top;
	public:
	Stack();
	//0.puch(const T &item)��ʾѹ�����item��
	void push(const T &item);
	//0.pop()��ʾ����ջ������
	T pop();
	//0.peek()��ʾ�鿴ջ�����󣨵�������ջ�����󣩡�
	const T &peek() const;
	bool isEmpty() const;
	bool isFull() const;
	//0.clear()�������ջ�����ǴӶ��忴�������ǽ�ջ��ԭ����ջ״̬����
	void clear();	
};

template<class T, int SIZE>
Stack<T, SIZE>::Stack<T, SIZE>():
	top(-1)
{}

template<class T, int SIZE>
void Stack<T, SIZE>::push(const T &item)
{
	//1.����ѹ��ʱ�����ж�ջ�Ƿ�Ϊ����Ȼ���ٽ�ջ��top����һλ��������Ҫѹ��Ķ���item���롣
	assert(!isFull());
	list[++top] = item;
}

template<class T, int SIZE>
T Stack<T, SIZE>::pop()
{
	//2.���ⵯ��ʱ�����жϵ�ǰջ�Ƿ�Ϊ�գ�Ȼ�󵯳�ջ��top���ڵĶ��󣬲���ջ��top����һλ��
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
	//3.���ջ���ǰ�ջ����ԭ��-1λ�á�
	top = -1;
}