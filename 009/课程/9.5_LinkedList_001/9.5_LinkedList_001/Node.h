#pragma once
template<class T>
class Node
{
    private:
    Node<T> *next;
    public:
    T data;
    Node<T>(const T &item, Node<T> *next = 0);
    void insertAfter(Node<T> *p);
    //����deleteAfter()�ķ��ض������Ǹ���ɾ���������㡣֮������ô��ƶ��ǽ���������ķ���ֵ��Ϊvoid���ں�������ֱ��ɾ���������Ϊϣ����ɾ���ڵ��ṩ��������ԡ�
    Node<T> *deleteAfter();
    Node<T> *nextNode();
    const Node<T> *nextNode() const;
};

template<class T>
Node<T>::Node<T>(const T &i, Node<T> *n) :
    data(i), next(n)
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
    //�����ǰ���������������һ����㣬�Ͳ���ɾ����
    if(next == 0)
    {
        return 0;
    }
    else
    {
        Node<T> *temp = next;
        next = temp->next;
        return temp;
    }
}

template<class T>
Node<T> *Node<T>::nextNode()
{
    return next;
}

template<class T>
const Node<T> *Node<T>::nextNode() const
{
    return next;
}