#pragma once
#include <iostream>

template<class T>
class DNode
{
	private:
	DNode<T> *left;
	DNode<T> *right;

	public:
	T data;
	
	DNode(const T &item = 0);
	
	void insertRight(DNode<T> *p);
	void insertLeft(DNode<T> *p);
	DNode<T> *deleteNode();
	DNode<T> *nextLeftNode() const;
	DNode<T> *nextRightNode() const;
};

template<class T>
DNode<T>::DNode(const T &item)
{
	left = right = NULL;
	data = item;
}

template<class T>
void DNode<T>::insertRight(DNode<T> *p)
{
	if(p == right)
	{
		return;
	}
	p->right = right;
	p->left = this;
	if(right != NULL)
	{
		right->left = p;
	}
	right = p;
}

template<class T>
void DNode<T>::insertLeft(DNode<T> *p)
{
	if(p == left)
	{
		return;
	}
	p->left = left;
	p->right = this;
	if(left != NULL)
	{
		left->right = p;
	}
	left = p;
}

template<class T>
DNode<T> *DNode<T>::deleteNode()
{
	DNode<T> *temp = this;
	this->left->right = right;
	this->right->left = left;
	return temp;
}

template<class T>
DNode<T> *DNode<T>::nextLeftNode() const
{
	if(left != NULL)
	{
		return left;
	}
	else
	{
		std::cout << "No left" << std::endl;
		return NULL;
	}
}

template<class T>
DNode<T> *DNode<T>::nextRightNode() const
{
	if(right!= NULL)
	{
		return right;
	}
	else
	{
		std::cout << "No right" << std::endl;
		return NULL;
	}
}