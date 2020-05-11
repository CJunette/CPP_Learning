// 5.8_Supplement_004_StaticMember.cpp : This file contains the 'main' function. Program execution begins and ends there.
//对书上p156页中“对类的静态私有数据进行初始化时，还可以引用该类的其他私有成员。如在一个类中存一个同类的静态私有对象时，可以引用该类的私有构造函数将其初始化。”的实例。
//私有化与否不是重点，因此这里为了方便观察，全都用public。

#include <iostream>
using namespace std;

int b = 1;

//一个类中有其他类的对象的尝试。
class T
{
	public:
	T(int a = 0)
	{
		i = a;
	}

	int i;
};

class S
{
	public:
	S(int b = 1)
	{
		j = b;
	}

	int j;

	static T t;
};
//2.引用构造函数初始化的做法是这样的。
//2.我不是非常确定这个是不是书上说的那种初始化方法，因为正常的用“:”初始化的方法会报错（[纠正]这里说到的是初始化静态对象，而不是初始化常对象，所以和“:”无关）。
T S::t(2);
//2.或者下面这个也可以。应该说下面这个才是书上说的那种方法。
/*
T S::t = T(2);
*/

//一个类中有自身类的对象的尝试。
class R
{
	public:
	R(int c = 2)
	{
		k = c;
	}
	int k;

	static R r;
};

//3.注意，这里虽然说可以用“类的其他成员”进行初始化，但是实际上是不能用那些静态数据成员的。也就是说，这里不能写成“R(k)”这样的写法。参数必须是个常量值（可以是具体数值，也可以是已经赋值了的常量）。
//3.因为非static的静态数据成员只有在创建对象发生实例化时才会被初始化，而静态数据成员则是要在程序一开始就完成初始化的。
R R::r = R(3);

//1.这种类里套同类的做法只适用于静态成员。下面这种类内部有个同类非静态成员的做法会直接报错。
/*
class Q
{
	public:
	Q(int d = 3)
	{
		l = d;
	}
	int l;
	private:
	Q q;
};
*/

int main()
{
	cout << S::t.i << endl;
	cout << R::r.k << endl;
	
	cout << R::r.r.r.r.r.k << endl;
	//4.这里是可以套娃的，但这些套娃地址都相同。
	cout << &R::r.k << endl;
	cout << &R::r.r.k << endl;
	cout << &R::r.r.r.k << endl;
}