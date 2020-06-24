#pragma once

template<class T>
class Node
{
	public:
	Node(const T &t = 0, Node<T> *nextptr = NULL);
	void insertAfter(Node<T> *p);
	Node<T> *deleteAfter();
	Node<T> *nextNode();
	const Node<T> *nextNode() const;
	T data;

	private:
	Node<T> *next;
};

template<class T>
Node<T>::Node(const T &t, Node<T> *nextptr):
	data(t), next(nextptr)
{}

template<class T>
void Node<T>::insertAfter(Node<T> *p)
{
	p->next = next;
	next = p;
}

template<class T>
Node<T> *Node<T>::deleteAfter()
{
	if(next == NULL)
	{
		return NULL;
	}
	else
	{
		Node<T> *temp = next;
		next = next->next;
		return temp;
	}
}

template<class T>
Node<T> *Node<T>::nextNode()
{
	return const_cast<Node<T> *>(static_cast<const Node<T> *>(this)->nextNode());
}

template<class T>
const Node<T> *Node<T>::nextNode() const
{
	return next;
}