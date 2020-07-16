// 12.3_DestructInException_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//例12-2，带析构语义的类的C++异常处理。

#include <iostream>
#include <string>

using namespace std;

class MyException
{
    public:
    MyException(const string &message):
        message(message)
    {
        cout << "Constructor of MyException" << endl;
    }
    MyException(const MyException& excp):
        message(excp.message)
    {
        cout << "Copy Constructor of MyException" << endl;
    }
    ~MyException()
    {
        cout << "Destructor of MyException" << endl;
    }
    const string &getMessage() const { return message; }

    private:
    string message;
};

class Demo
{
    public:
    Demo() { cout << "Constructor of Demo" << endl; }
    ~Demo() { cout << "Destructor of Demo" << endl; }
};

//0.构造函数func()，目的只在于向外抛出异常。
void func() throw(MyException)
{
    //0.Demo对象d在函数结束时才会被析构，然后当前函数在结束前就被throw强制中断了。
    Demo d;
    cout << "Throw MyException in func()" << endl;
    throw MyException("Exception thrown by func()");
}

int main()
{
    cout << "In main function" << endl;
    try
    {
        func();
    }
    //1.初始化异常参数，由于是引用，所以直接指向try中抛出的异常对象。
    //1.通常情况下，如果只需要通知处理程序有个特定类型的异常已经产生，其实并不需要声明异常参数（e）；但如果需要访问异常对象，就需要声明参数。
    catch(MyException &e)
    {
        //2.完成对try语句中生成的、尚未被析构的Demo对象d的析构。析构发生在创建异常对象e之后，执行catch代码段中的代码之前。
        //2.但要注意，这其中并不包括被throw的MyException对象，它会等到catch块结束后才会被析构。
        //3.调用catch块中的代码。
        cout << "Caught an exception: " << e.getMessage() << endl;
        //2.如果上面的catch中的异常声明不是引用，而是普通的MyException的值，则try块中throw的MyException对象和catch块中靠复制构造函数生成的MyException对象都会在catch语句执行完之后才会被析构。
    }
    //4.继续主函数的执行。
    cout << "Resume the excution of main()" << endl;
}