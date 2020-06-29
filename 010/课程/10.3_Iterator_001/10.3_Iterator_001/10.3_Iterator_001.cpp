// 10.3_Iterator_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iterator>
#include <algorithm>
using namespace std;

double square(double x)
{
    return x * x;
}

int main()
{
    //1.为什么在没有输入终止符之前，每次输入如果以回车结尾，程序就会直接将输入的计算结果输出出来？
    //1.不应该是在输入终止符之后统一输出才对吗？
    //1.根据之前10.2_STL_001中给出的transform的实现来看，似乎是因为每次循环都有“*result = square(*first)”这一语句，所以导致每次循环都会对输出流迭代器进行一次赋值；有可能迭代器在每次被赋值时都会进行一次输出。
    //2.下面的内容来自书上p403。
    //2.关于template<class T>istream_iterator<T>这个类模板，它实际上有4个模板参数，但后三个有默认参数值。该模板对类型参数T有两个要求：T有默认构造函数；T能执行“>>”，实现从输入流输入的操作。
    //2.istream_iterator的实例需要靠“istream_iterator(istram& in)”这一构造函数来构造。该构造函数有默认形式，默认构造函数会构造一个指向输入流结束位置的对象。在windows下，输入流结束需要输入“ctrl+z”，然后再按回车；Linux下需要按“ctrl+d”。
    //3.下面内容来自书上p404。
    //3.输出流迭代器类模板template<class T>ostream_iterator<T>与输入流的类似。但它的构造函数可以有第二个参数，用于表示输出的分隔符，在这里就是使用了“\t”作为输出流的分隔符。
    //3.类型T同样要求满足两个条件：有默认构造函数；可以用“<<”，实现输出流输出的操作。另外，用“*”访问输出流迭代器对象时，表达式只能用作赋值运算符的左值。
    transform(istream_iterator<double>(cin), istream_iterator<double>(), ostream_iterator<double>(cout, "\t"), square);
    cout << endl;    
}