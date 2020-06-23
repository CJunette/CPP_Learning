#include "Header.h"
#include <iostream>
using namespace std;

//1.通常情况下，受多文件编译的限制，把定义写到头文件外的做法是会导致类模板的成员函数无法实例化的。
template<class T, T init>
void A<T, init>::f()
{
	cout << "A::f()" << endl;
}
//1.但如果用下面的语句进行int类型的显式实例化的话，是可以成功实现实例化的（但要注意，模板类的成员函数的定义必须在同一个文件内，且在显式实例化之前）。
//1.这样做也有很大的缺陷，即如果程序中出现了类型参数不同的类模板对象的话，又会出现无法实例化成员函数的问题。
template void A<int, 1>::f();

template<class T, T init>
template<class S>
//2.注意，下面不能写成“void A<T, init>::h<S>()”，会提示报错。因为这里是在对模板进行定义，而不是某个特定的实例进行定义。
//2.函数模板的“<模板参数>”在调用时可以省略也可以写明，但在定义时是不出现的。
//2.其实类也是这样。当声明结构体模板A时，我们并不会写“struct A<T>”。因为此时我们需要的是一个模板，而不是一个确定了模板参数的实例。
void A<T, init>::h()
{
	cout << typeid(T).name() << endl;
	cout << typeid(S).name() << endl;
}
//2.对于模板类内部的模板成员函数，可以用这样的方式进行显式声明。
template void A<int, 1>::h<double>();

//3.也可以用同样的方法对函数模板进行显式实例化。
template<class T>
void g(T t)
{
	cout << "g()" << endl;
}
//3.对于函数模板而言，如果可以从函数参数推断出模板参数的话，可以不显示指定模板参数。
/*
template void g<int>(int);
*/
template void g(int);

//4.同样的，也可以对函数的静态成员进行初始化。
//4.这里我在头文件中也做了备注。
template<class T, T init>
//4.这里的赋值也可以写成“stat(init)”;但不能写成“stat()”，因为那样会将stat当做一个函数。
T A<T, init>::stat = init;
//4.声明语句不能用来进行赋值
template int A<int, 1>::stat;

//5.也可以直接对模板类进行显式实例化。如果这样做的话，其中成员函数和静态成员的定义也会被显式实例化。
template<class T>
void B<T>::i()
{
	cout << "B::i()" << endl;
}
//5.因此这里只需要显式实例化类，不用再对其中的函数成员再进行实例化。
//5.另外，在显式实例化类的时候，不加“class”也是可以的。
/*
template B<double>;
*/
template class B<double>;