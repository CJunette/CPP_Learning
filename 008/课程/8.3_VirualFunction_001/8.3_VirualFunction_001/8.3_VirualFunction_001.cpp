// 8.3_VirualFunction_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class Base1
{
    public:
    //由于虚函数要求在程序执行时再确定重名的成员函数所属的数据类型，因此虚函数的定义必须在类外进行。
    //因为如果在类内定义，则属于内联函数，编译器在处理内联函数时会直接在编译阶段就将函数代码嵌入主函数代码中。这与虚函数的使用思路是不符的。
    void virtual display() const;
};
void Base1::display() const
{
    cout << "display in Base1" << endl;
}

class Base2: public Base1
{
    public:
    //此时，由于Base1中已经将display()定义为虚函数了，因此继承下来的display()默认就是虚函数，写不写“virtual”关键字都可以。下面Derived类中也是一样的道理。
    void virtual display() const;
};
void Base2::display() const
{
    cout << "display in Base2" << endl;
}

class Derived: public Base2
{
    public:
    void virtual display() const;
};
void Derived::display() const
{
    cout << "display in Derived" << endl;
}

void func1(Base1 *ptr)
{
    ptr->display();
}
void func2(Base1 const &ptr)
{
    ptr.display();
}


int main()
{
    Base1 b1;
    Base2 b2;
    Derived d;

    //这里发现一个小问题，当对象所属的类或类的基类中存在virtual函数时，就不能用下面这种右值的形式来充当基类指针的实参了。
    //进一步地我发现，下面这行代码虽然在编译器中会有红线，但运行程序后是能通过编译的。这是为什么？
    //另外，如果把类及基类中的虚函数删去，红线会消失；如果类中有数据成员会出现红线，删掉数据成员红线也会消失（函数成员则不会有影响）。这又是为什么？难道虚函数也是一种数据成员？
    /*
    func1(Base1());
    */
    //但似乎仍然可以用右值的形式来充当引用类型的实参。
    //之后发现，其实之前出错的原因是对右值取址引发了错误，与函数的参数类型无关！
    /*
    func2(Base1());
    */    
    
    //可以看到，在使用虚函数后，成功实现了以基类指针为形参，传入不同类型的指针，执行不同类型函数的目的。
    func1(&b1);
    func1(&b2);
    func1(&d);
    func2(b1);
    func2(b2);
    func2(d);
}
