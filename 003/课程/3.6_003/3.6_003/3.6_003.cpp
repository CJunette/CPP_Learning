// 3.6_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <typeinfo>
using namespace std;

int main()
{
    int a = 10, b = 5;
    
    cout << &a << endl;
    cout << &b << endl;

    int &ra = a;
    int &rb = b;

    //&操作符会取指针最深处的地址，因此这里输出的就是a和b的地址。
    cout << &ra << endl;
    cout << &rb << endl;
    //通过输出ra与rb所在的内存地址，我们发现ra与rb的地址并不像其他的地址那样相邻的距离较近，
    //因此推测他们可能是在内存的另一位置。
    //！！！这里可能存在一个重大错误，(void *)有可能并不是获取引用变量地址的方法。它只是将引用变量强制类型转换成了指针而已。
    cout << (void *)ra << endl;
    cout << (void *)rb << endl;
    cout << endl;

    //*操作符的本质是取一个变量的地址，并将其以值的形式保存。
    int *ta, *tb;
    ta = &a;
    tb = &b;
    //访问指针的值。
    cout << *ta << endl;
    cout << *tb << endl;
    //这里使用&操作符并没有输出a和b的地址，而是输出了ta和tb的地址。可见ta和tb中储存的这个地址实际是一个值，而非一个引用地址。
    cout << &ta << endl;
    cout << &tb << endl;
    cout << endl;

    //因此在这里进行交换操作实际上就是将两个值进行了交换。并非是将指针指向的对象进行了交换。
    cout << ta << endl;
    cout << tb << endl;
    int *t = ta;
    ta = tb;
    tb = t;
    cout << ta << endl;
    cout << tb << endl;

}
