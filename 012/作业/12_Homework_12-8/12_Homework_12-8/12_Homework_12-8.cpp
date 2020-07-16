// 12_Homework_12-8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
using namespace std;

class SomeClass
{
    public:
    SomeClass(const string &s = "default"):
        str(s)
    {
        cout << "SomeClass Constructor" << endl;
    }
    SomeClass(const SomeClass &sc):
        str(sc.str)
    {
        cout << "SomeClass Copy Constructor" << endl;
    }
    ~SomeClass()
    {
        cout << "SomeClass Destructor" << endl;
    }
    SomeClass &operator =(const SomeClass &sc)
    {
        cout << "SomeClass Operator =" << endl;
        str = sc.str;
        return *this;
    }        

    private:
    string str;
};

int main()
{
    //程序一共创建了两个SomeClass对象。
    auto_ptr<SomeClass> ptr1(new SomeClass("ptr1"));
    auto_ptr<SomeClass> ptr2(new SomeClass("ptr2"));

    //这里的赋值操作符是针对SomeClass的，也就是说只是将类内的成员进行了修改，因此不会调用构造函数或析构函数。
    *ptr1 = *ptr2;

    //对于auto_ptr对象，这样的复制构造形式的创建并不会调用SomeClass的构造函数或复制构造函数。
    //因为实际进行的只是ptr3中的指针指向ptr2原来指向的对象，然后ptr2中的指针指向空。
    //智能指针的复制构造操作会使用于复制构造的指针解除与其当前指针的关联。
    //这行代码执行后的结果就是，ptr2中指针变为空，ptr3中的指针变为原ptr2中的指针。
    auto_ptr<SomeClass> ptr3(ptr2);

    //这里的赋值操作是针对auto_ptr的。当ptr1被其他智能指针赋值时，会删除与ptr1关联的指针，此时会调用SomeClass类的析构函数。同时，用于赋值的智能指针也会解除与自身关联的指针的联系。
    //这行代码执行后的结果就是，ptr3中的指针变为空，ptr1中的指针变为原ptr3中的指针。
    ptr1 = ptr3;    
}