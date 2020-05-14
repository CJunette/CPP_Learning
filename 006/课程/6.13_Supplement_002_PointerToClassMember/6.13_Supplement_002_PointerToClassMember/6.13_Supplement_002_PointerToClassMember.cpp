// 6.13_Supplement_002_PointerToClassMember.cpp : This file contains the 'main' function. Program execution begins and ends there.
//书上p215提到，可以创建直接指向类的成员的指针。课上没有提到这部分内容。
//乍一看好像没有什么实际用处，但其实可以将这些指向类的成员的指针作为函数的形参，便于编写需要利用类成员的函数回调。

#include <iostream>
using namespace std;

class Point
{
    public:
    static int count;
    int z = -1;
    const int a = 0;
    int getX() { return x; }
    int getY() { return y; }
    static int getCount() { return count; }
    int getA() const { return a; }
    private:
    int x = 1, y = 2;
};
int Point::count = 0;

//3.此时，用指向函数成员的指针就可以实现，在函数具体调用时在确定到底调用getX()还是getY()的设计目的。
//3.这给以类函数为函数回调对象的想法提供了可能。
void func(Point p, int (Point::*get)(), int Point::*pz)
{
    cout << (p.*get)() << endl;
    cout << p.*pz << endl;
}

int main()
{
    //1.指向类成员的指针似乎不能用来指向静态成员。数据成员和函数成员都不行。
    //1.指向函数成员的指针同样会受到访问限制。无法访问private的成员。
    int Point:: *pz = &Point::z;

    //1.类的静态成员直接用一般形式的指针进行访问。
    int *pcount = &Point::count;
    int (*pgetcount)() = Point::getCount;
    
    //2.用一般指针指向一般对象时，是可以通过指针访问常成员的。因为此时指针指向的对象并不是常量，因此不需要常量指针。
    //2.但此时，必须用常量指针才能指向常成员。因为此时指针指向的对象时int类型的常量，所以必须用常量指针。
    const int Point:: *pa = &Point::a;
    //2.函数成员也是同理。只有常函数的指针才能指向常函数成员。
    int (Point::*pgeta)() const = &Point::getA;

    Point pnt;
    //3.定义指向类的函数成员的指针时，要把“类名::”写到函数指针名的括号中。
    //3.在定义类的函数成员的的指针时，不能省略“&”。
    int (Point:: *pgetx)() = &Point::getX;
    //3.在函数中作为形参的实例。
    func(pnt, &Point::getX, pz);
        
    //4.对象和类成员指针的结合方式是通过“*”指针操作符。
    pnt.*pz;
    //4.在访问函数成员时，需要将“对象名.*函数指针名”都放进括号中作为一个整体。
    (pnt.*pgetx)();
    //4.同样，除了使用对象对成员进行访问以外，还可以直接使用指向对象的指针来对成员进行访问。
    Point *ppnt = &pnt;
    ppnt->*pz;
    (ppnt->*pgetx)();       
}

