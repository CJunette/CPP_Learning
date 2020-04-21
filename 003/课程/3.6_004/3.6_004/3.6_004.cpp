#include <iostream>

using namespace std;

int main()
{
	int a = 10;

	//指针可以将声明与定义分开。
	int *pa;
	pa = &a;
	//但应用必须在声明时就进行初始化。
	//从反编译的结果看，指针与声明的代码是一样的。
	int &ra = a;

	//对于指针、引用变量，分别有不同的获取其所在地址的方式。	
	cout << "The address of int a: " << &a << endl;
	//从输出地址看，指针和引用的地址相差距离很远，应该一个在堆一个在栈。
	cout << "The address of pointer: " << &pa << endl;
	cout << "The address of reference: " << (int *)ra << endl;

	//对于指针、引用变量，分别有不同的获取其所储存地址的方式。	
	cout << "The address stored in pointer: " << pa << endl;
	cout << "The address stored in reference: " << &ra << endl;


	//指针可以重新指向新的目标，可是引用却不可以。
	int b = 20;
	pa = &b;
	cout << "The value of pa: " << *pa << endl;
	cout << "The address of pointer: " << &pa << endl;
	cout << "The address of stored in pointer: " << pa << endl;

	//新创建的指针可以指向一个引用变量(实际是指向引用变量所指向的变量)；新创建的引用变量只能指向一个指针对应的值，不能指向一个指针。
	int *pc = &ra;
	int &rc = *pa;
	cout << *pc << endl;
}