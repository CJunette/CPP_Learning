// 6.8_SmartPointer_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//主要是对智能指针的概括和补充。

#include <iostream>
using namespace std;

class A
{
    public:
    A(int x = 0):
        x(x)
    {
        cout << "A Constructor..." << endl;
    }
    ~A()
    {
        cout << "A Destructor..." << endl;
    }
    int x;
};

class C;

class B
{
    public:
    shared_ptr<C> sPtr_c;
    ~B()
    {
        cout << "B Destructor..." << endl;
    }
};

class C
{
    public:
    shared_ptr<B> sPtr_b;
    ~C()
    {
        cout << "C Destructor..." << endl;
    }
};

void func1()
{
    shared_ptr<B> spb(new B());
    shared_ptr<C> spc(new C());
    //6.这里使用share_ptr创建循环引用会造成不可避免的内存泄漏。但正常情况下，如果是普通的指针出现相互引用是不会导致循环引用的。
    //6.在完成下面两个指针的建立后，对象B和对象C的use_count值都应该为2。
    //6.这里发生的内存泄漏其实是，当智能指针spb被析构时，由于它所指向的那个动态内存分配对象B还有另一个指针指向自己（动态内存分配对象C的指针成员sPtr_c），所以导致此时use_count的值为1。
    //6.而对于share_ptr而言，只有指向的对象的use_count为0时，才会进行删除。因此此时对象B就被保留了下来。但指针spb却已经被析构了。
    //6.对于智能指针spc也是同理，在spc被析构的同时，由于动态内存分配对象C还有动态内存分配对象B中的指针指向自己，因此use_count不为0，所以不会被删除。
    //6.而当两个智能指针都被析构时，也就失去了能够删除那两个动态内存分配对象的接口。所以导致了内存分配。
    spb->sPtr_c = spc;
    spc->sPtr_b = spb;
    //6.可以看到，即使我在这里对spb和spc进行了析构处理，他们所指向的B和C仍然有use_count。
    spb.~shared_ptr();
    spc.~shared_ptr();
    cout << spc.use_count() << endl;
    cout << spb.use_count() << endl;        
    //6.要想解决这个问题，要么将类中的shared_ptr改为weak_ptr，要么在程序末尾主动用.reset()清除所有指向对象的智能指针。
    spb.reset();
}

//------------------------------------------------------
class E;

class D
{
    public:
    weak_ptr<E> sPtr_e;
    ~D()
    {
        cout << "D Destructor..." << endl;
    }
};

class E
{
    public:
    weak_ptr<D> sPtr_d;
    ~E()
    {
        cout << "E Destructor..." << endl;
    }
};

void func2()
{
    //7.weak_ptr可以通过复制shared_ptr或另一个weak_ptr来建立。其构造和释放对资源不产生影响。
    shared_ptr<D> spd(new D());
    shared_ptr<E> spe(new E());
    //7.这里之所以weak_ptr有用的原因，是因为weak_ptr本身就算与对象建立了联系也不会增加对象的use_count。
    //7.所以在完成了下面两行指针的建立后，use_count还是1。
    //7.因此，在对对象进行析构的时候，当spd被析构，对象D的use_count就为0，会被顺利删除。对象E也是同理。
    spd->sPtr_e = spe;
    spe->sPtr_d = spd;
    cout << spd.use_count() << endl;
    cout << spe.use_count() << endl;
}

//------------------------------------------------------

int main()
{
    //1.一般的指针允许不同的指针指向同一个对象。
    int *ptr_1 = new int(1);
    int *ptr_2 = ptr_1;
    //1.unique_ptr不允许自身以外的指针指向自己所指向的对象。它本身似乎也不能在指向其他对象（也有可能是我没发现能执行这样操作的指令）。
    //1.另外，unique_ptr似乎只能指向动态内存分配生成的对象。
    unique_ptr<int> uPtr_1(new int(5));
    //2.unique_ptr能通过系统的move()函数将其自身所指向的对象转一个另一个指针，转移的同时自身变为空指针。
    unique_ptr<int> uPtr_2 = move(uPtr_1);
    unique_ptr<int> uPtr_3(move(uPtr_2));    

    cout << ((uPtr_1 == nullptr) ? "True" : "False") << endl;
    cout << uPtr_1 << endl;
    cout << ((uPtr_2 == nullptr) ? "True" : "False") << endl;    
    cout << *uPtr_3 << endl;

    //3.unique_ptr不允许自身以外的指针指向自己指向的对象，也就意味着unique_ptr是不能用另一个unique_ptr来对自己进行初始化的。
    //3.但有一个例外，unique_ptr是可以用一个作为右值的unique_ptr来初始化自己的。
    //3.下面这个代码就是错误的，因为uPtr_4是个左值。
    /*
    unique_ptr<int> uPtr_4(new int(4));
    unique_ptr<int> uPtr_5 = uPtr_4;
    */
    //3.而下面这个代码就是可行的，因为用来赋值的unique_ptr是个右值。
    unique_ptr<int> uPtr_4 = unique_ptr<int>(new int(4));

    //4.shared_ptr可以创建允许有其他指针指向自己所指向的对象的指针。
    //4.shared_ptr似乎也是只能指向动态内存分配的对象。
    shared_ptr<int> sPtr_1(new int(3));
    shared_ptr<int> sPtr_2(sPtr_1);

    //5.智能指针会自动在程序结束时对自己进行delete操作。
    unique_ptr<A> u_PA(new A(1));
    shared_ptr<A> s_PA1(new A(2));
    //5.当多个智能指针指向同一个目标时，由于只创建了一个动态内存分配对象，因此动态内存分配对象只会delete一次。
    shared_ptr<A> s_PA2(s_PA1);
    //5.使用use_count()可以查看智能指针所指向的对象被引用的次数。
    cout << s_PA1.use_count() << endl;

    //5.虽然只会被delete一次，但必须保证所有指向那个对象的shared_ptr都被销毁（或所有权被放弃），动态内存分配对象才会被delete。
    s_PA1.reset();
    //5.只要有一个智能指针调用了reset()方法，那么指向那个对象的所有指针都会被取消。
    cout << s_PA1.use_count() << endl;
    s_PA2.~shared_ptr();
    cout << "----------" << endl;
    //5.删除后，被reset()的智能指针地址会被归0，而调用~shared_ptr()的指针地址还是原址（说实话我有点搞不清这个~shared_ptr()的作用，外形看似析构函数，但在对象调用它之后对象本身为什么没有失效？）。
    //5.这里，reset()是清除某个对象的所有智能指针，而~shared_ptr()只是放弃当前智能指针对所指向的对象的所有权。这点在6.中会体现的很明显。
    cout << s_PA1 << endl;
    cout << s_PA2 << endl;
    //5.而此时如果想访问其中的对象的话，虽然不会报错，但程序运行时会卡住。
    /*
    cout << s_PA1->x << endl;
    cout << s_PA2->x << endl;
    */

    cout << endl;

    //6.这里展现了一个用shared_ptr造成的循环引用的问题。
    func1();
    cout << endl;

    //7.这里是用weak_ptr解决之前提到的shared_ptr造成的循环引用的问题。
    func2();
}

