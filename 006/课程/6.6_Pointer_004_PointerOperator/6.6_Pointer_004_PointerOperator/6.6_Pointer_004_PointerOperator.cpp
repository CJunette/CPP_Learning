// 6.6_Pointer_004_PointerOperator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    int a[] = { 1, 2, 3, 4, 5 };
    int *p = &a[2];
    cout << "p address: " << p << endl;
    cout << "p: " << *p << endl;

    //指针的加减运算是让指针根据其数据类型每次固定地向前或向后移动若干个字节的距离。
    //这样设计的目的是为了让指针总是指向一个完整数据的起始位置。
    //通常这种指针的算术运算不用于指向单一数据的指针，因为运算结果一定会跳出这个单一数据在内存上的空间，指向垃圾数据。
    //一般指针的算术运算只会用于指向连续存储的同类型数据，如数组或静态变量。
    p++;
    //p++实际就相当于a[3]。
    cout << "p address after ++: " << p << endl;
    cout << "p after ++: " << *p << endl;

    //两次p--后，实际就相当于a[1];
    p--;
    p--;
    cout << "p address after --: " << p << endl;
    cout << "p after --: " << *p << endl;

    cout << endl;

    int *q = &a[2];
    cout << "q address: " << q << endl;
    cout << "q: " << *q << endl;

    //指针还可以进行关系运算，用于比较两个指针中存储的地址的关系。
    //但是这个关系运算在指向不同数据类型的指针之间及指针与一般整数变量之间是没有意义的。
    cout << "p > q? " << (p > q) << endl;
    cout << "p < q? " << (p < q) << endl;
    //指针可以和0之间进行等于或不等于的运算。（由于内存地址都是正值，所以不等于0就是大于0。）
    cout << "p == 0? " << (p == 0) << endl;
    cout << "p > 0? " << (p > 0) << endl;

    //但目前我暂时不知道将判断指针是否为零这个运算有什么意义。因为毕竟都是在定义的时候就确定将其定义为空指针了。
    //如果只是定义指针“int *r;”而不进行初始化的话，运行时程序会报错（使用未初始化的内存）。
    //可能在以后会有更多用处。
    int *r = 0;
    cout << "r == 0? " << (r == 0) << endl;
    cout << r << endl;
}
