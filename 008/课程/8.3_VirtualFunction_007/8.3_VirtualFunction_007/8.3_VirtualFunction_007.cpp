// 8.3_VirtualFunction_007.cpp : This file contains the 'main' function. Program execution begins and ends there.
//虚析构函数。

#include <iostream>
using namespace std;

class Base1
{
    public:
    Base1()
    {
        p1 = new int(0);
        cout << "Base1 constructor" << endl;
    }
    ~Base1()
    {
        delete p1;
        cout << "Base1 descturcotr" << endl;
    }
    int *p1;    
};

class Derived1: public Base1
{
    public:
    Derived1()
    {
        cout << "Derived1 constructor" << endl;
        p2 = new int(1);
    }
    ~Derived1()
    {
        cout << "Derived1 destructor" << endl;
        delete p2;
    }    
    int *p2;    
};

class Base2
{
    public:
    Base2()
    {
        p1 = new int(0);
        cout << "Base2 constructor" << endl;
    }
    virtual ~Base2()
    {
        delete p1;
        cout << "Base2 descturcotr" << endl;
    }
    int *p1;
};

class Derived2: public Base2
{
    public:
    Derived2()
    {
        cout << "Derived2 constructor" << endl;
        p2 = new int(1);
    }
    virtual ~Derived2()
    {
        cout << "Derived2 destructor" << endl;
        delete p2;
    }
    int *p2;
};

int main()
{
    //1.在析构函数不是虚函数的情况下，用基类指针指向派生类动态对象，然后delete基类指针，只会执行基类的析构函数。
    //1.此时派生类的动态对象并没有被完全删除，而派生类中又存在一个指向动态对象的指针，因此就造成了内存泄漏。
    Base1 *pb1 = new Derived1;    
    Derived1 *pd1 = static_cast<Derived1 *>(pb1);
    //3.复制一下动态对象中的两个指针所指向的地址，在delete之后再访问一下这个地址，看看是否真的实现了析构。
    int *pp1 = pb1->p1;
    int *pp2 = pd1->p2;
    cout << "执行delete之前" << endl;
    cout << "p1指向的值: " << *pb1->p1 << endl;
    cout << "p2指向的值: " << *pd1->p2 << endl;

    //2.如果在delete的地方debug一下会发现，在删除pb1时，pd1所指向的对象中的p2也被删除了（地址发生了改变，指向地址中存放的值变为了0xDDDDDDDD）。按道理只执行基类的析构函数是做不到这一点的，这是为什么？
    //2.可能是因为对于派生类对象而言，析构函数的调用顺序是先调用派生类的析构函数，再调用基类的析构函数，因此在调用基类的析构函数前，隐式地调用了系统生成的默认的派生类的析构函数，将派生类对象的参数都进行了删除。
    //2.但如果这个想法正确，就引发出了另一个问题，既然要调用派生类中的析构函数，为什么不调用已经定义好的析构函数？
    //2.[回答]根据知乎上提问的回答，这里并不是我所猜测的那样。这里的delete操作有两个步骤，一是执行析构函数，二是释放内存。虽然析构函数执行的是基类的析构函数，但释放内存的操作会使派生类的成员被“删除”。
    delete pb1;
    cout << "执行delete之后" << endl;
    cout << "p1: " << pd1->p1 << endl;
    cout << "p2: " << pd1->p2 << endl;
    //3.在这里可以发现，对于基类中的指针，其地址所指向的值已经被清空；而对于派生类中的指针，其地址所指向的值还是之前的值，未被删除。
    //3.也就是说之前的delete操作只是将对象中的指针给析构了，并没有真正地将派生类指针所指向的内容给delete。但这依然没有解释为什么调用基类析构函数会对派生类成员产生影响。
    cout << "访问p1之前的地址所得到的值：" << *pp1 << endl;
    cout << "访问p2之前的地址所得到的值：" << *pp2 << endl;
    cout << endl;

    //4.当使用虚析构函数后，在用基类指针指向派生类对象，然后再删除基类指针时，就会在调用基类构造函数之前调用派生类构造函数。
    //4.进而避免了内存泄漏的发生。
    Base2 *pb2 = new Derived2;
    Derived2 *pd2 = static_cast<Derived2 *>(pb2);
    pp1 = pb2->p1;
    pp2 = pd2->p2;
    cout << "执行delete之前" << endl;
    cout << "p1指向的值: " << *pb2->p1 << endl;
    cout << "p2指向的值: " << *pd2->p2 << endl;
    delete pb2;
    cout << "执行delete之后" << endl;
    cout << "p1: " << pd2->p1 << endl;
    cout << "p2: " << pd2->p2 << endl;
    //4.对比上下两次的输出，可以看到这里派生类的指针所指向的动态分配对象也被删除了。
    cout << "访问p1之前的地址所得到的值：" << *pp1 << endl;
    cout << "访问p2之前的地址所得到的值：" << *pp2 << endl;
}