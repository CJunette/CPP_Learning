// 6.6_Pointer_017_ObjectPointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//对之前学过的前向引用声明的内容进行的补充。

#include <iostream>

class Fred;

class Barney
{
    public:
    Barney();
    //1.之前我们说过，即使有前向引用声明也不能在一个类中包含一个前向引用声明过的类的对象。
    //1.但如果真的出现需要这种设计的情况时，要怎么解决。（这种情况实际中很少见）
    /*
    Fred fred;
    */
    //2.由于我们之前说过，虽然不能包含前向引用声明过的类的对象，但是类中可以包含前向引用声明过的指向类的对象的指针。
    //2.因此这里的思路就是，在Barney类中创建一个指向Fred类对象的指针，然后在构造函数中用动态内存分配的方式创建一个Fred类的对象，并让这个指针指向那个对象。    
    Fred *fred;

    //4.既然这里使用了动态内存分配，那么必须在析构函数处对进行delete，避免内存泄漏的发生。
    ~Barney()
    {
        delete fred;
    }
};

class Fred
{
    public:
    Barney barney;
};

Barney::Barney()
{
    //3.从代码上看，这里似乎与之前说的指针不能指向局部作用域中的非静态变量不符。但注意，这里是动态内存分配，在未delete前，动态内存分配的对象都是有效的。
    //3.如果这里不使用动态内存分配来创建对象，而是按以前的做法创建一个一般的对象的话，就会出现外层作用域的指针指向内层局部作用域的非静态对象地址。
    fred = new Fred();
}

int main()
{
    
}
