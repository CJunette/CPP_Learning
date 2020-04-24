// 4.6_NestedClass_003_ForwardDeclaration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class B;

class A
{
    //前向使用声明有很大的局限性。目前暂时不知道有什么方法能弥补这些局限性。
    //最好不要在程序设计的时候写这种循环嵌套的结构。
    public:
    //如果我想在这个类里实现func1的定义，编译器会报错，错误是没有见过B这种类别。因此想要在前向引用声明之后用之后定义的类做函数参数的话，必须保证这个函数的定义在那个类的定义之后。
    //对应老师课上说的就是，前向引用声明要求不能在内联函数中使用类的对象。
    void func1(B b); 
         
    public:
    //前向引用声明不能涉及类的细节，如创建B类的对象。原因很简答，因为要创建对象至少要知道这个对象的大小，而这个类都没有被声明过，因此不可能知道类的大小。
    //但是，由于指针的大小是可以确定的，因此可以创建指向B类的指针。
    B *point;    
    int value = 0;
};

class B
{
    public:
    void func2(A a);
    
    int value = 0;
};

//在这里，之所以可以在函数中访问B的参数，是因为这个函数声明被放在B的类型声明后面。如果把这个函数声明放到B的声明前，一样会报错。
void A::func1(B b)
{
    cout << b.value << endl;
}

void B::func2(A a)
{
    cout << a.value << endl;
}

int main()
{
    A a;
    B b;
    a.func1(b);
    b.func2(a);
}
