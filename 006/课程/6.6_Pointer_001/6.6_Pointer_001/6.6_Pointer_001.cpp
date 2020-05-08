// 6.6_Pointer_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
    static int i;
    //指针本身就是一种数据类型，然而在定义指针时还是需要定义其所指向对象的数据类型。
    //这其中的原因是，因为指针只保存了对象的地址。而在未来通过指针取值或赋值时，除了起始地址外，还需要知道应该连续取或存入多少个字节，这部分信息是由指向对象的数据类型决定的。
    static int *ptr_1 = &i;
    //&在做运算符时是取址操作，被称作地址运算符。
    cout << &i << endl;
    cout << ptr_1 << endl;
    cout << &ptr_1 << endl;
    cout << sizeof(ptr_1) << endl;
    cout << endl;

    //*在做运算符时是寻址操作， 被称作指针运算符。
    *ptr_1 = 3;

    //换言之，如果指针类型与所要指向的数据类型不符，就会导致报错。
    /*
    double *p = &i;
    */
    cout << endl;

    //如果要定义一个指向指针的指针，则需要像下面这么写。
    //如果写成“int *ptr_2 = &ptr_1”，则会因为指向对象是指针，而定义类型为int而报错；如果写成“int **ptr_2 = ptr_1”，则指针会指向ptr_1所指向的地址，而非指向ptr。
    static int **ptr_2 = &ptr_1;
    cout << *ptr_2 << endl;
    cout << **ptr_2 << endl;
}
