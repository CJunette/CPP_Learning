#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

//0.�����ϣ�������һ�������ŵĽ������ɵġ�
//0.����������һ�����������ƶ��Ķ�ȡ����
template<class T>
class LinkedList
{
    private:
    Node<T> *front, *rear;
    Node<T> *prevPtr, *currPtr;
    int size, position;

    Node<T> *newNode(const T &item, Node<T> *ptrNext = 0);
    void freeNode(Node<T> *p);
    //8.Ĭ�Ͻ�����������l���Ƹ�һ���յ�����
    //8.���������ܲ�Ϊ�գ�����ִ��copy()ǰ��ִ��һ��clear()��
    void copy(const LinkedList<T> &l);

    public:
    LinkedList();
    LinkedList(const LinkedList<T> &l);
    ~LinkedList();
    LinkedList<T> &operator = (const LinkedList &l);

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

    //13.������ͦ�����ΪʲôdeleteFront()�з���ֵ����deleteCurrent()û�з���ֵ�ġ�
    //13.ԭ���ǣ�����ķ���ֵֻ��ԭֵ�Ŀ�������deleteFront()��ʵ���ϵ�����deleteCurrent()��
    T deleteFront();
    void deleteCurrent();

    T &data();
    const T &data() const;

    void clear();
};

template<class T>
Node<T> *LinkedList<T>::newNode(const T &item, Node<T> *ptrNext)
{
    Node<T> *p = new Node<T>(item, ptrNext);
    if(p == NULL)
    {
        cout << "Memory allocation failure!" << endl;
        exit(1);
    }
    return p;
}

template<class T>
void LinkedList<T>::freeNode(Node<T> *p)
{
    //1.��֮ǰ���������ʱ���ڵ��ģ����delete�Ķ����Ƕ�̬�������Ҫ��ô�죬�������п��ܱ���ġ�
    //1.���������е�Node������newNode()��new�ķ������������Ķ�̬�������newNode()�еĲ���item�Ƕ�̬�ڴ���������Ҳ�ᱻһ��delete�������һ����������ڿռ�ᱻ�����ͷš�
    //1.���Բ�����ɾ�������Ƕ�̬�����ڴ��������⡣
    delete p;
}

template<class T>
void LinkedList<T>::copy(const LinkedList<T> &l)
{
    Node<T> *p = l.front;
    //8.�������������lΪ�գ���ֱ�ӷ��ء�
    if(p == NULL)
    {
        return;
    }
    //8.�������������Ϊ�գ����ڵ�ǰ����β����ͣ������½�㣬ֱ�����ﱻ���������β����㡣
    while(p != NULL)
    {
        insertRear(p->data);
        p = p->nextNode();
    }
    //8.��currPtr��prevPtrָ��positionʱ��ָ���λ�á�
    //8.������һ����ʾ�������и��ģ����Ҹо��������岻����Ϊ��β����������positionӦ�þ���������λ�á�
    /*
    prevPtr = NULL;
    currPtr = front;
    for(int pos = 0; pos < position; pos++)
    {
        prevPtr = currPtr;
        currPtr = currPtr->nextNode();
    }
    */
}

template<class T>
LinkedList<T>::LinkedList<T>() :
    front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(-1)
{}

template<class T>
LinkedList<T>::LinkedList<T>(const LinkedList<T> &l) :
    front(NULL), rear(NULL), prevPtr(NULL), currPtr(NULL), size(0), position(-1)
{
    //9.�ڸ��ƹ��캯���У�������ݳ�Ա�ĳ�ʼ����ֱ�ӵ���copy()������
    copy(l);
}

template<class T>
LinkedList<T>::~LinkedList()
{
    //11.�����������У�ֱ�ӵ���clear()������
    clear();
}

template<class T>
LinkedList<T> &LinkedList<T>::operator =(const LinkedList<T> &l)
{
    //12.��������ƵĶ������������ֱ�ӷ�������
    if(&l == this)
    {
        return *this;
    }
    //12.�ڡ�=��������У���ִ��clear()����ִ��copy()��
    clear();
    copy(l);
    return *this;
}

template<class T>
int LinkedList<T>::getSize() const
{
    return size;
}

template<class T>
bool LinkedList<T>::isEmpty() const
{
    return size == 0;
}

template<class T>
void LinkedList<T>::reset(int pos)
{
    //4.����Ϊ���򷵻ء�
    if(front == NULL)
    {
        return;
    }
    if(pos < 0 || pos > size - 1)
    {
        cerr << "Reset: Invalid list position: " << pos << endl;
        return;
    }
    //4.��ָ��ŵ�front��λ�á�
    prevPtr = NULL;
    currPtr = front;
    position = 0;
    //4.���Ҫ��λ����0����frontλ�ã�ֱ�ӷ��ء�
    if(pos == 0)
    {
        return;
    }
    else
    {
        //4.����һֱ������������������Ҫλ�á�
        for(position = 0; position < pos; position++)
        {
            prevPtr = currPtr;
            currPtr = currPtr->nextNode();
        }
    }
}

template<class T>
void LinkedList<T>::next()
{
    //6.����Ѿ�������β�����ָ���λ�ã������ټ������¡�
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
    //7.���д������䣬�������������ݡ�
    return currPtr == NULL;
}

template<class T>
int LinkedList<T>::currentPosition() const
{
    return position;
}

template<class T>
void LinkedList<T>::insertFront(const T &item)
{
    //5.�������ײ���ӽ�㡣
    //5.�������Ϊ�գ������ò���������reset()���й��㡣
    if(front != NULL)
    {
        reset();
    }
    insertBefore(item);
}

template<class T>
void LinkedList<T>::insertRear(const T &item)
{
    //5.������β����ӽ�㡣
    Node<T> *nNode = newNode(item);
    prevPtr = rear;
    if(rear == 0)
    {
        front = nNode;
    }
    else
    {
        prevPtr->insertAfter(nNode);
    }
    rear = nNode;
    currPtr = nNode;
    position = size;
    size++;
}

template<class T>
void LinkedList<T>::insertBefore(const T &l)
{
    Node<T> *nNode;

    //3.���prevPtrΪ�յĻ�����������Ϊ�գ������������������ͷ��λ�á�
    if(prevPtr == NULL)
    {
        nNode = newNode(l, front);
        front = nNode;
        //3.ʾ������ûд��һ�У����������������н��в���Ļ�������Ӧ������һ�У�����position = -1��
        position = 0;
    }
    else
    {
        nNode = newNode(l, currPtr);
        prevPtr->insertAfter(nNode);
    }
    //3.��currPtrΪNULLʱ��˵�������ڱ�βλ�á���ʱ�ڵ�ǰλ��֮ǰ�����㣬���൱����������������㡣�����Ҫ�ı�position��rear��
    if(currPtr == NULL)
    {
        position = size;
        rear = nNode;
    }
    currPtr = nNode;
    size++;
}

template<class T>
void LinkedList<T>::insertAfter(const T &l)
{
    Node<T> *p = new Node<T>(l);
    //2.��frontΪNULLʱ���൱�ڲ��������
    if(front == NULL)
    {
        front = p;
        rear = p;
        currPtr = p;
        position = 0;
    }
    else
    {
        //2.���з���ʱ��������currPtr�������һ����Ŀ��ָ��ĵ�ַ��NULL���ġ�
        //2.����������£�ʵ���Ͼ��������һ����Ŀ�ĺ������һ������
        if(currPtr == NULL)
        {
            currPtr = prevPtr;
        }
        //2.�ڶ����һ����Ŀִ��.insertAfter()ʱ����Ҫ��rearָ��Ķ�����е�����
        if(currPtr == rear)
        {
            rear = p;
            //2.��ʱ����Ҫ��position��������ǰ���һ��Ŀ���λ�ü�һ��size-1+1���ĵط���
            position = size;
        }
        //2.�����������ʱ��ֻ��Ҫ��position++���ɡ�
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
    //14.���frontΪNULL��˵����ǰ����Ϊ��������˲��ܽ���ɾ����
    if(front == NULL)
    {
        cerr << "Invalid deletion!" << endl;
        exit(1);
    }
    //14.�������Ϊ�գ�����reset()������ԭ��frontλ�á�
    T item = front->data;
    reset();
    deleteCurrent();
    return item;
}

template<class T>
void LinkedList<T>::deleteCurrent()
{
    Node<T> *p;
    //13.�����ǰcurrPtr������β�����ָ��ĵ�ַ��λ�ã����޷�ɾ����
    if(currPtr == NULL)
    {
        cerr << "Invalid deletion!" << endl;
        exit(0);
    }
    //13.����ڱ�ͷ��㣬��pָ���ͷ��㣬frontָ���ͷ������һ����㡣
    if(prevPtr == NULL)
    {
        p = front;
        front = front->nextNode();
    }
    //13.�����м䣬��ִ��Node<T>��deleteAfter()��
    else
    {
        p = prevPtr->deleteAfter();
    }
    //13.���ɾ������β��㣬����Ҫ����rear��ָ��
    if(p == rear)
    {
        rear = prevPtr;
        //13.ʾ���������滹��һ����position--;�������Ƕ���currPtr���ʵ�β����next�������position��sizeӦ����һ���ģ���˴�ʱû�б�Ҫȥ��position��
        /*
        position--;
        */
    }
    currPtr = p->nextNode();
    freeNode(p);
    size--;
}

template<class T>
void LinkedList<T>::clear()
{
    //10.clear()Ҫִ�еľ�������ɾ�������е�ÿ����㡣
    Node<T> *p = front;
    while(p != NULL)
    {
        Node<T> *next = p->nextNode();
        freeNode(p);
        p = next;
    }
    currPtr = prevPtr = NULL;
    front = rear = NULL;
    position = -1;
    size = 0;
}

template<class T>
T &LinkedList<T>::data()
{
    //15.�������Ϊ�գ�������currPtr������β�������޷����ء�
    if(currPtr == NULL)
    {
        cerr << "Data: invalid reference!" << endl;
        exit(1);
    }
    return currPtr->data;
}
template<class T>
const T &LinkedList<T>::data() const
{
    //15.���ϵĴ�����û��const�汾��data()�ģ������˲��䡣
    //15.const�ͷ�const��ͬ�������ĺ������ǲ��ܻ�������ġ�
    if(currPtr == NULL)
    {
        cerr << "Data: invalid reference!" << endl;
        exit(1);
    }
    return currPtr->data;
}