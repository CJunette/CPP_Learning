#pragma once

template<class T, T init>
struct A
{
	void f();

	//4.在对静态成员的显式实例化时，我犯了一个错误。
	//4.我希望在显式实例化时能给静态成员一个初始值。
	//4.因此，我在静态成员前用“template<T init>”试图创造一个能用来给静态成员赋值的模板。希望在显式实例化时用这个模板来进行初始化赋值。
	//4.之所以称其为错误，就是因为模板是只针对类和函数的，并没有对象模板一说。
	//4。而正确的做法，应该是修改后的这样，在类模板中添加参数，然后在对静态成员的具体定义（而非显式实例化声明）时，完成初始化赋值。
	static T stat;

	template<class S>
	void h();
};

template<class T>
void g(T t);

template<class T>
struct B
{
	void i();
};