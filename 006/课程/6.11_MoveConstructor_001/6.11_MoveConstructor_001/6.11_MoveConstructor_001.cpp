// 6.11_MoveConstructor_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class IntNum
{
    public:
    IntNum(int x = 0) :
        xptr(new int(x))
    {
        cout << "Constructor..." << endl;
    }
    IntNum(IntNum &i) :
        xptr(new int(*i.xptr))
    {
        cout << "Copy constructor..." << endl;
    }
    //3.移动构造函数的参数是右值，也就是临时对象。
    //3.它执行的操作时，将旧对象指针指向的目标给新对象的指针，然后将旧对象的指针变为空指针。这样做的目的是避免两个指针指向同一内存，进而造成析构时的错误。
    //3.这样做的好处在于，不需要再额外复制一个新的动态内存分配对象，直接利用之前已经创建好的即可。
    //3.更进一步的，移动构造函数可以直接利用旧对象的堆内存，将这部分内存分配给新对象。
    IntNum(IntNum &&i) :
        xptr(i.xptr)
    {
        i.xptr = nullptr;
        cout << "Moving constructor..." << endl;
    }
    ~IntNum()
    {
        delete xptr;
        cout << "Destructor..." << endl;
    }
    int getInt() { return *xptr; }

    private:
    int *xptr;
};

IntNum getNum()
{   
    //2.这里有两个参考网址：www.zhihu.com/question/40213381和en.cppreference.com/w/cpp/language/move_constructor。
    //2.这里有一点我需要纠正。以前我一直以为这里a作为一个被声明的变量，应该是右值。
    //2.但是当函数中出现复制构造函数和移动构造函数时，返回操作选择移动构造函数。加上上面两个参考网址的内容，a作为一个返回值是右值的函数中创建的对象，似乎也是一个右值（消亡值既属于泛左值也属于右值）。
    //2.课上说的触发移动构造的条件是，如果一个资源即将消亡，且其中的资源需要被再利用。
    IntNum a;    
    return a;
}

void showNum(IntNum i)
{
    cout << i.getInt() << endl;;
}

class A
{
    public:
    A()
    {
        cout << "Constructor..." << endl;
    }
    A(const A &a)
    {
        cout << "Copy constructor..." << endl;
    }
    ~A()
    {
        cout << "Destructor..." << endl;
    }
    int getX() { return x; };

    private:
    int x = 1;
};

A getA()
{
    //1.首先要注意一下，只有下面这种形式才会不调用复制构造函数，只调用一次构造函数。
    return A();
    //1.向上面getNum()那样的写法，本质上还是先创建用构造器创建了对象a，然后在返回时使用用复制构造器。
    /*
    A a;
    return a;
    */
}

int main()
{    
    cout << getNum().getInt() << endl;
    cout << endl;

    //4.虽然函数中声明的对象是右值让我有点意外，但在函数中将对象作为形参的操作中，左值和右值的区分还是很明确的。
    showNum(getNum());
    cout << endl;
    IntNum i;
    showNum(i);
}
