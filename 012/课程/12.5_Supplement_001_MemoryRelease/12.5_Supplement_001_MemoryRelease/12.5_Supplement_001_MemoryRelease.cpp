// 12.5_Supplement_001_MemoryRelease.cpp : This file contains the 'main' function. Program execution begins and ends there.
//在异常处理时，对于try块中栈上的对象，异常处理会自动将其解析；但对于堆上的动态内存分配的对象，异常处理并不会执行解析操作，这就带来了内存泄漏的可能性。

#include <iostream>
#include <memory>
using namespace std;

struct Demo
{
    Demo() { cout << "Constructor of Demo" << endl; }
    ~Demo() { cout << "Destructor of Demo" << endl; }
};

class MyException
{
    private:
    string message;
    public:
    MyException(const string & msg):
        message(msg)
    {}
    const string &getMessage() const { return message; }
};

void func1() throw(MyException)
{
    //0.在没有主动对创建的动态分配对象进行删除的情况下，这部分内存就会出现泄漏。
    Demo *pdemo1 = new Demo;
    //1.一种解决办法是在确定要抛出错误之前，手动将这部分内存释放。
    
    if(2 > 1)
    {
        delete pdemo1;
    }
    
    if(2 > 1)
    {
        throw MyException("Exception thrown by func1()");
    }
}

void func2() throw(Demo *)
{    
    Demo *pdemo = new Demo;
    throw pdemo;
}

struct MyClass
{
    Demo *pdemo1;
    MyClass() { pdemo1 = new Demo; }
    ~MyClass() { delete pdemo1; }
};

void func3() throw(MyException)
{
    MyClass mc;
    throw MyException("Exception thrown by func3()");
}

int main()
{
    {
        try
        {
            func1();
        }
        catch(MyException &e)
        {
            cout << "Catch MyException" << endl;
        }
    }
    cout << endl;
    {
        try
        {
            //2.第二种做法是将需要被删除的对象当做异常对象抛出，在catch中接受，并执行删除。
            func2();
        }
        catch(Demo *e)
        {
            delete e;
            cout << "Catch Demo" << endl;
            //2.或者也可以继续向上抛掷异常对象，到上一级异常处理中进行删除（这里不行，因为现在当前就是最高层的异常处理了）。
            /*
            throw;
            */
        }        
    }
    cout << endl;
    {
        try
        {
            //3.第三种做法是将可能的动态分配对象封装到一个普通的栈上的对象去，这样在try语句抛出错误时，动态分配的对象会在封装类被析构时执行删除操作。
            func3();
        }
        catch(MyException)
        {
            cout << "Catch MyException" << endl;
        }
    }
    cout << endl;
    {
        try
        {
            //4.第四种做法是利用智能指针，这种做法与第三种做法相似，都是利用封装对象能够在析构时自动完成删除的特性。
            Demo *p = new Demo;
            auto_ptr<Demo> a_p(p);            
            throw MyException("Exception thrown by try");
        }
        catch(MyException)
        {
            cout << "Catch MyException" << endl;
        }
    }
}