#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

//0.本质上，链表是一个个连着的结点类组成的。
//0.链表类像是一个在链表上移动的读取器。
template<class T>
class LinkedList
{
    private:
    Node<T> *front, *rear;
    Node<T> *prevPtr, *currPtr;
    int size, position;

    Node<T> *newNode(const T &item, Node<T> *ptrNext = 0);
    void freeNode(Node<T> *p);
    //8.默认将被复制链表l复制给一个空的链表。
    //8.如果链表可能不为空，则在执行copy()前先执行一次clear()。
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

    //13.这里我挺不理解为什么deleteFront()有返回值，而deleteCurrent()没有返回值的。
    //13.原因是，这里的返回值只是原值的拷贝，在deleteFront()中实际上调用了deleteCurrent()。
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
    //1.我之前看到这里的时候在担心，如果delete的对象不是动态分配对象要怎么办，那样是有可能报错的。
    //1.但这里所有的Node都是由newNode()用new的方法创建出来的动态对象。如果newNode()中的参数item是动态内存分配对象，则也会被一并delete；如果是一般对象，则所在空间会被正常释放。
    //1.所以不存在删除对象不是动态分配内存对象的问题。
    delete p;
}

template<class T>
void LinkedList<T>::copy(const LinkedList<T> &l)
{
    Node<T> *p = l.front;
    //8.如果被复制链表l为空，则直接返回。
    if(p == NULL)
    {
        return;
    }
    //8.如果被复制链表不为空，则在当前链表尾部不停地添加新结点，直到到达被复制链表的尾部结点。
    while(p != NULL)
    {
        insertRear(p->data);
        p = p->nextNode();
    }
    //8.让currPtr和prevPtr指向position时该指向的位置。
    //8.下面这一步是示范代码中给的，但我感觉好像意义不大，因为在尾部添加完结点后，position应该就是在最后的位置。
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
    //9.在复制构造函数中，完成数据成员的初始化后直接调用copy()函数。
    copy(l);
}

template<class T>
LinkedList<T>::~LinkedList()
{
    //11.在析构函数中，直接调用clear()函数。
    clear();
}

template<class T>
LinkedList<T> &LinkedList<T>::operator =(const LinkedList<T> &l)
{
    //12.如果被复制的对象就是自身，则直接返回自身。
    if(&l == this)
    {
        return *this;
    }
    //12.在“=”运算符中，先执行clear()，再执行copy()。
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
    //4.链表为空则返回。
    if(front == NULL)
    {
        return;
    }
    if(pos < 0 || pos > size - 1)
    {
        cerr << "Reset: Invalid list position: " << pos << endl;
        return;
    }
    //4.将指针放到front的位置。
    prevPtr = NULL;
    currPtr = front;
    position = 0;
    //4.如果要求位置是0，即front位置，直接返回。
    if(pos == 0)
    {
        return;
    }
    else
    {
        //4.否则一直按链表向下搜索至需要位置。
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
    //6.如果已经在链表尾结点所指向的位置，则不能再继续向下。
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
    //7.相比写条件语句，这样的输出更快捷。
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
    //5.在链表首部添加结点。
    //5.如果链表不为空，则先用不带参数的reset()进行归零。
    if(front != NULL)
    {
        reset();
    }
    insertBefore(item);
}

template<class T>
void LinkedList<T>::insertRear(const T &item)
{
    //5.在链表尾部添加结点。
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

    //3.如果prevPtr为空的话，不是链表还为空，就是现在正在链表表头的位置。
    if(prevPtr == NULL)
    {
        nNode = newNode(l, front);
        front = nNode;
        //3.示范代码没写这一行，但如果是想空链表中进行插入的话，还是应该有这一行，避免position = -1。
        position = 0;
    }
    else
    {
        nNode = newNode(l, currPtr);
        prevPtr->insertAfter(nNode);
    }
    //3.当currPtr为NULL时，说明现在在表尾位置。此时在当前位置之前插入结点，就相当于在链表的最后插入结点。因此需要改变position和rear。
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
    //2.当front为NULL时，相当于插入空链表。
    if(front == NULL)
    {
        front = p;
        rear = p;
        currPtr = p;
        position = 0;
    }
    else
    {
        //2.进行访问时，是允许currPtr访问最后一个项目所指向的地址（NULL）的。
        //2.而这种情况下，实际上就是在最后一个项目的后面添加一个对象。
        if(currPtr == NULL)
        {
            currPtr = prevPtr;
        }
        //2.在对最后一个项目执行.insertAfter()时，需要把rear指向的对象进行调整。
        if(currPtr == rear)
        {
            rear = p;
            //2.此时还需要将position调整到当前最后一个目标的位置加一（size-1+1）的地方。
            position = size;
        }
        //2.正常进行添加时，只需要将position++即可。
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
    //14.如果front为NULL，说明当前链表为空链表，因此不能进行删除。
    if(front == NULL)
    {
        cerr << "Invalid deletion!" << endl;
        exit(1);
    }
    //14.如果链表不为空，则将用reset()将链表还原到front位置。
    T item = front->data;
    reset();
    deleteCurrent();
    return item;
}

template<class T>
void LinkedList<T>::deleteCurrent()
{
    Node<T> *p;
    //13.如果当前currPtr在链表尾结点所指向的地址的位置，则无法删除。
    if(currPtr == NULL)
    {
        cerr << "Invalid deletion!" << endl;
        exit(0);
    }
    //13.如果在表头结点，则将p指向表头结点，front指向表头结点的下一个结点。
    if(prevPtr == NULL)
    {
        p = front;
        front = front->nextNode();
    }
    //13.若在中间，则执行Node<T>的deleteAfter()。
    else
    {
        p = prevPtr->deleteAfter();
    }
    //13.如果删除的是尾结点，则还需要调整rear的指向。
    if(p == rear)
    {
        rear = prevPtr;
        //13.示范代码下面还有一个“position--;”，但是对于currPtr访问到尾部的next的情况，position和size应该是一样的，因此此时没有必要去减position。
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
    //10.clear()要执行的就是依次删除链表中的每个结点。
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
    //15.如果链表为空，或现在currPtr在链表尾部，则无法返回。
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
    //15.网上的代码是没有const版本的data()的，我做了补充。
    //15.const和非const的同名函数的函数体是不能互相替代的。
    if(currPtr == NULL)
    {
        cerr << "Data: invalid reference!" << endl;
        exit(1);
    }
    return currPtr->data;
}