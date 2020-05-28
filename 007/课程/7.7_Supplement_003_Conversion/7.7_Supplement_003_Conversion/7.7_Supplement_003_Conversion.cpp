// 7.7_Supplement_003_Conversion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//讨论书上p298-303的关于基类与派生类相互转换的问题。

#include <iostream>
using namespace std;

class Base0
{
    public:
    int b0 = 0;
    void print() const { cout << this << endl; }
};

class Base1: public Base0
{
    public:
    int b1 = 1;
    void print() const { cout << this << endl; }
};

class Base2: public Base0
{
    public:
    int b2 = 2;
    void print() const { cout << this << endl; }
};

class Derived1: public Base1, public Base2
{
    public:
    int d1 = 5;
    void print() const { cout << this << endl; }
};

class Base3: virtual public Base0
{
    public:
    int b3 = 3;
    void print() const { cout << this << endl; }
};

class Base4: virtual public Base0
{
    public:
    int b4 = 4;
    void print() const { cout << this << endl; }
};

class Derived2: public Base3, public Base4
{
    public:
    int d2 = 6;
    void print() const { cout << this << endl; }
};

int main()
{
    //0.首先讨论派生类转为基类的情况。为了方便说明，用指针而非对象或引用。
    
    //1.单继承的情况。当派生类指正被转为基类指针时，由于此时指针都是指向对象首位置的，因此不需要发生变化。内存上，基类的成员在派生类的成员之前。
    {
        Base1 *pb1 = new Base1();
        Base0 *pb0 = pb1;
        pb1->print();
        pb0->print();
        delete pb1;
        cout << endl;
    }

    //2.不用虚基类时的菱形继承情况。此时共同基类Base0有两份拷贝。内存上，间接基类的位置在直接位置之前，直接基类的位置在派生类之前（直接基类的排序根据声明顺序来排）。
    {
        Derived1 *pd1 = new Derived1();
        //2.当指针指向Base1时，不需要移动位置。
        Base1 *pb1 = pd1;
        //2.但当指针指向Base2时，需要进行一定的位移。
        Base2 *pb2 = pd1;
        //2.由于共同基类Base0有两份拷贝，因此进行指针类型转换时必须声明转换经过那个直接基类。从地址可以看出Base0所在的位置在Base1和Base2之前。
        Base0 *pb0 = (Base1 *)(pd1);
        pd1->print();
        pb1->print();
        pb2->print();
        pb0->print();
        //2.当通过Base2访问Base0时，地址发生了变化。
        pb0 = (Base2 *)(pd1);
        pb0->print();
        delete pd1;
        cout << endl;
    }

    //3.使用虚基类时的菱形继承情况。此时虚基类的直接派生类中会自动生成两个隐含的指针（详细看之前关于虚继承的部分）。内存上，直接基类的位置在派生类之前，虚基类的位置在最后。
    {
        //3.可以看到，同样作为Base0的派生类，因为Base3和Base4用的是虚继承的方式，所以多了一个隐含的指针，因此类的大小发生了变化。
        cout << "sizeof Base1: " << sizeof(Base1) << endl;
        cout << "sizeof Base1: " << sizeof(Base3) << endl;
        Derived2 *pd2 = new Derived2();
        Base3 *pb3 = pd2;
        Base4 *pb4 = pd2;
        //3.此时，由于Base0只存在一份数据成员了，因此不需要通过额外的直接基类就能实现转换。
        Base0 *pb0 = pd2;
        pd2->print();
        pb3->print();
        pb4->print();
        pb0->print();
        //3.如果是通过虚基类的派生类Base3来进行指针的类型转换，则此时是通过访问Base3中的隐含指针来获取虚基类的地址的。
        pb0 = (Base3 *)pd2;
        delete pd2;
        cout << endl;
    }

    //4.关于反向转换，即从基类转向派生类。
    //4.对于对象而言，除非派生类中有用基类对象为参数的构造函数，否则是不能实现转换的。
    //4.这里提到的从基类向派生类的转换是指指针和引用的转换。
    {
        //5.注意，将基类指针转换为派生类指针要求基类指针本身就是指向一个派生类对象的，不然会导致转换前后对象类型不同而引起访问错误。
        Base1 *pb11 = new Derived1();
        //6.从派生类到基类的类型转换是可以隐式发生的，但从基类到派生类的转换必须显示声明。
        Derived1 *pd11 = static_cast<Derived1 *>(pb11);
        cout << pd11->d1 << endl;
        //5.下面就是一个错误的示范，如果转换前后类型不相同，可能会导致访问到类外数据。
        Base1 *pb1w = new Base1();
        Derived1 *pd1w = static_cast<Derived1 *>(pb1w);
        cout << pd1w->d1 << endl;

        //7.另外，即使是基类指针指向了派生类对象的中间位置，在将基类指针转换回派生类指针时，指针会自动回到对象的开头位置。
        //9.这就让我更不理解为什么虚基类的指针不能转成派生类的指针了。
        Derived1 d1;
        d1.print();
        Base2 *pb2 = &d1;
        Derived1 *pd12 = static_cast<Derived1 *>(pb2);

        //8.书上提到“指针和引用的转换，只涉及创建新的指针和引用，不涉及创建新的对象”。但下面这个做法是可行的。
        //8.下面做法的实质是，用pb1所指向的对象为参数，执行Derived1的复制构造函数。
        Derived1 d1 = *static_cast<Derived1 *>(pb11);

        //9.从基类向派生类的转换时不能发生在虚基类上的。下面的代码会显示报错。
        //9.书上p302也给出了一些解释。我认为可能的原因是，从派生类向基类转化可以发生的原因是派生类本身记录了派生类对象的初始位置到虚基类位置的指针位移，
        //9.派生类通过直接基类向虚基类转化可以发生的原因可能是通过访问直接基类中的隐含指针，指针能够从直接基类位置转移到虚基类位置；
        //9.而上述两个步骤对于已经转移到虚基类位置的指针而言都是不可逆的。（虽然我觉得在知道派生类及各级基类大小的情况下，想要逆向移动指针也不是不可能的。所以我也不知道为什么这点实现不了？）
        /*
        Base0 *pb0 = new Derived2();
        Derived2 *pd2 = static_cast<Derived2 *>(pb0);
        */
        delete pd11;
        delete pb1w;
        cout << endl;
    }

    {
        //10.当转换需要经过void指针时，即使转换前后的指针类型是相同的，也有可能出现错误。
        Derived1 d1;
        d1.print();
        //10.这里Base2的指针pb2指向的是对象d1的中间位置。
        Base2 *pb2 = &d1;
        pb2->print();
        //10.转换为void类型的指针pv后，pv同样指向的是对象d1的中间位置。
        void *pv = static_cast<void *>(pb2);
        cout << pv << endl;
        //10.再次将pv转换会Derived类型的指针时，本来应该将指针移到对象的开头位置的，但因为是从void类型的指针出发进行转换，因此指针仍然在对象的中间位置。
        Derived1 *pd1 = static_cast<Derived1 *>(pv);
        pd1->print();
        //10.这也就导致了对对象内部成员的访问出现了巨大的问题。
        cout << pd1->d1 << endl;
    }
}

