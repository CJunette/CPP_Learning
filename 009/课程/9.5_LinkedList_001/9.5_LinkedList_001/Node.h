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
    //这里deleteAfter()的返回对象是那个被删除的链表结点。之所以这么设计而非将这个函数的返回值设为void并在函数体中直接删除结点是因为希望给删除节点提供更多灵活性。
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
    //如果当前对象就是链表的最后一个结点，就不用删除。
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