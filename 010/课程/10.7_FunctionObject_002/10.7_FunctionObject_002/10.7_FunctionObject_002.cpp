// 10.7_FunctionObject_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//用重载了“()”运算符的类充当函数对象。
//书上p436对函数对象的定义是，“行为类似函数的对象”。

#include <iostream>
#include <numeric>
using namespace std;

template<class T>
class MultClass
{
    public:
    //2.由于操作符重载是不能成为类的静态成员函数的，因此正常的调用必须通过对象实现。
    T operator () (T x, T y)
    {
        return x * y;
    }
};

int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int N = sizeof(a) / sizeof(int);
    MultClass<int> m;

    //这里有两点要注意。
    //1.当用类中的“()”重载充当函数对象时，必须用“类名()”（MultClass<int>()）的形式才行，不能用类名或“对象名()”(MultClass<int> m; m();)的形式。因为只用类名会判定那个参数为一个类；而用“对象名()”会被视作是对成员函数的引用。    
    //1.另外，这里也不能写成“MultClass<int>::operator()”（因为不能直接用成员函数名做参数  ）；
    //1.也不能写成“&MultClass<int>::operator()”或“&MultClass<int>()”（因为这两者的数据类型是指向类的成员函数的指针，与一般的函数指针的操作有所不同（算法是用一般指针的访问方式进行编写的）。
    //1.正确写法的“MultClass<int>()”的数据类型实际上是MultClass<int>，而非函数指针类型），也就是说，其实这里是用默认构造函数创建了个临时对象，传入了算法中。这个对象由编译器自动提供。使用类的形式提供的函数对象能比普通函数提供更多的额外信息。
    cout << "The result by multipling all elements in a is " << accumulate(a, a + N, 1, MultClass<int>()) << "." << endl;
    /*
    cout << "The result by multipling all elements in a is " << accumulate(a, a + N, 1, m()) << "." << endl;
    */
    //2.同样的，当调用函数时，必须用“对象名()”的形式，不能用“类名()”。因为“类名()”会被视作是希望通过构造函数创建当前类的临时对象。
    int b = m(a[0], a[1]);
    /*
    int b = MultClass<int>(a[0], a[1]);
    */

    //3.总结一下就是，当将重载了“()”的类作为函数对象时，实际作为函数对象的是由“类名()”调用默认构造函数生成的一个临时对象。然后在算法中，在调用那个对象的“()”操作符运算。
    //3.并不是我之前想象的，对类重载了“()”运算，就导致“类名()”形成了一种新的数据类型。
}