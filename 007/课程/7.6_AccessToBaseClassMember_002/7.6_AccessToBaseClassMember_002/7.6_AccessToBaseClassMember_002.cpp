// 7.6_AccessToBaseClassMember_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//虚基类
//这里说到的共同基类和以前说的派生类的间接基类是一回事。

#include <iostream>
using namespace std;

class Base0
{
    public:
    Base0(int var = 0): var0(var) { cout << "Base0 Constructor" << endl; }
    int var0;
    void fun0() { cout << "From Base0" << endl; }
};

//1.在继承方式前加关键字“virtual”就可以实现虚继承，只对后面紧跟的那个基类起作用。此时称呼共同基类为虚基类。“virtual”只在声明时使用，在访问时不需要。
//1.虚继承是为了避免菱形继承中出现对共同基类的参数重复继承的问题。
class Base1: virtual public Base0
{
    public:
    Base1(int var = 1): Base0(var), var1(var) { cout << "Base1 Constructor" << endl; }
    int var1;
};

class Base2: virtual public Base0
{
    public:
    Base2(int var = 2): Base0(var), var2(var) { cout << "Base2 Constructor" << endl; }
    int var2;
};
//2.虚基类在共同基类和直接基类之间使用。在直接基类和派生类间不用再次使用。
//2.在虚继承的情况下，派生类中只会有一个共同基类成员。此时不能像以前的多继承情况那样实现对共同基类数据的直接访问（书上p300），必须通过指针间接的来访问。
//2.根据编译器不同，会有不同的解决方法。一种方法是在两个直接基类中各添加一个隐含的指针，让这两个指针指向共同基类所在的位置（通常在最后，虽然我也不知道这个最先执行构造函数的部分是怎么到最后去的？），然后在让这两个指针被派生类继承。(书上p300)
class Derived: public Base1, public Base2
{
    public:
    //3.在菱形继承中使用虚基类时，只有最远派生类的构造函数会调用共同基类的构造函数，直接基类的构造函数对共同基类的调用都会被忽略。
    //3.此时如果最远派生类没有在初始化列表为共同基类的构造函数传递参数，则会调用共同基类的默认构造函数。
    //3.如果共同基类不存在默认构造函数，则会报错。
    Derived(int var = 3): Base0(var), Base1(var), Base2(var), var3(var) { cout << "Derived Constructor" << endl; }
    int var3;
    void fun3() { cout << "From Derived" << endl; }
};

int main()
{
    static Derived drd(3);
    Derived *d = &drd;

    //2.建立了虚继承关系后，就不必要用直接基类的类名来访问虚基类中的成员了。
    drd.var0;
    drd.Base1::var0;
    
    Base1 *pb1 = d;
    Base2 *pb2 = d;
    //2.这里可以看到，隐含的指针并不是在继承的时候被添加到派生类中的，而是在进行虚继承的时候添加到直接基类中的。
    cout << "size of Base1: " << sizeof(Base1) << endl;
    cout << "size of Base2: " << sizeof(Base2) << endl;    

    Base0 *pb01 = pb1;
    Base0 *pb02 = pb2;

    cout << "address d: " << d << endl;
    cout << "address pb1: " << pb1 << endl;
    cout << "address pb2: " << pb2 << endl;
    cout << "address pb01: " << pb01 << endl;
    cout << "address pb02: " << pb02 << endl;
    cout << endl;

    d->var0 = 10;
    d->var1 = 100;
    d->var2 = 1000;
    d->var3 = 10000;
    int *x = (int *)d;

    //4.这里的vbptr就是上面说的直接基类Base1默认生成的指向派生类中共同基类成员位置的指针（实际上这个指针并不直接指向共同基类成员，而是指向了一张虚表。这个指针被称为虚基类表指针）。这里的vbptr和d在内存中的位置是相同的。
    cout << "address vbptr of Base1: " << (int *)d << endl;
    //4.因为这里不能通过*d的方式来获取vbptr所指向的地址，所以必须先以(int *)d的方式构造一个指向d的地址位置的指针，然后解析那个指针，从而取到vbptr中储存的地址的int格式。再通过(int *)将其转为地址格式，得到vbptr中储存的地址。
    cout << "address in vbptr of Base1: " << (int *)(*(int *)d) << endl;
    //4.用*析构，得出其中存放的值，对应虚表中的开始值，值为0。
    cout << "content vbptr[0] of Base1: " << *(int *)(*(int *)d) << endl;
    //4.知道最后用*解析前的做法都与上面相同。将指向虚表的指针进行+1的指针运算，实际位移距离为20个字节，到达虚表第二个元素的值所在的地址。用*取出其中值为20。代表共同基类的成员位置距Base1的开始位置20个单位。
    cout << "content vbptr[1] of Base1: " << *((int *)(*(int *)d) + 1) << endl;
    //4.由于var1紧跟着vbptr，因此可以通过(int *d)+1的方式得到其地址。
    cout << "var1 value: " << *((int *)d + 1) << endl;
    //4.用和上面相同的原理可以得到Base2的vbptr所指向的地址和地址中的具体值。
    cout << "address vbptr of Base2: " << (int *)d + 2 << endl;
    cout << "address in vbptr of Base2: " << (int *)*((int *)d + 2) << endl;
    cout << "content vbptr[0] of Base2: " << *(int *)*((int *)d + 2) << endl;
    //4.此时Base2的vbptr所指向的虚表的第二个元素的值为12，代表共同基类的成员位置距Base2的开始位置12个单位。
    cout << "content vbptr[1] of Base2: " << *((int *)*((int *)d + 2) + 1) << endl;
    //4.接下来内存中存储的就是var2、var3和var0，依次输出。
    cout << "var2 value: " << *((int *)d + 3) << endl;
    cout << "var3 value: " << *((int *)d + 4) << endl;
    cout << "var0 value: " << *((int *)d + 5) << endl;
}
