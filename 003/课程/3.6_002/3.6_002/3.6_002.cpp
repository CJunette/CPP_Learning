// 3.6_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

void Swap(int a, int b)
{
	int t;
	t = a;
	a = b;
	b = t;
}

void SwapWithAddress(int &a, int &b)
{
	int t = a;	
	a = b;
	b = t;
}

//根据“3.6_003”，这里看似复杂的操作实际只是对于函数所创建的值的副本进行交换的操作。并非我之前所想的对指针所值的地址进行交换。
//*a，*b本质上都只是值，而非指向地址的引用参数。
void SwapWithPointerAddressValue(void *a, void *b)
{
	cout << "Inside SwapWithPointerAddress funciton." << endl;
	cout << "Before swap." << endl;
	cout << "address ta = " << a << "\n" << "address tb = " << b << endl;
	void *t = a;
	a = b;
	b = t;
	cout << "After swap." << endl;
	cout << "address ta = " << a << "\n" << "address tb = " << b << endl;
	cout << "SwapWithPointerAddress function end.\n";
	cout << endl;
}

//如果我们想更改指针的指向地址，就要写“&a = &b”这样的语句，然而这个语句会直接被编译器报错。
void SwapWithPointerAddress(int &a, int &b)
{
	//制造一个指针，指向a指向的位置。
	int &t = a;
	//将b所指向地址中存储的值赋予a所指向地址中存储的值。
	a = b;
	//将t所指向地址中存储的值赋予b所指向地址中存储的值。而因为t所指向地址中存储的值就是a所指向地址中存储的值，
	//a所指向地址中存储的值之前已经被改为了b所指向地址中存储的值。因此这里其实就是b=b。
	b = t;
}

int main()
{
	cout << "(1)" << endl;
	int a = 5, b = 10;
	cout << "a = " << a << "\n" << "b = " << b << endl;
	cout << endl;
	Swap(a, b);
	cout << "a = " << a << "\n" << "b = " << b << endl;
	cout << endl;

	cout << "(2)" << endl;
	int& ta = a;
	int& tb = b;
	cout << "address a = " << &a << "\n" << "address b = " << &b << endl;
	//这里不管是用SwapWithAddress(ta, tb)，还是直接输入SwapWithAddress(a, b)，结果都会发生转换。
	SwapWithAddress(ta, tb);
	cout << "a = " << ta << "\n" << "b = " << tb << endl;	

	cout << "address ta = " << (void*)ta << "\n" << "address tb = " << (void*)tb << endl;
	cout << "address in ta = " << &ta << "\n" << "address in tb = " << &tb << endl;
	cout << endl;

	cout << "(3)" << endl;
	SwapWithPointerAddressValue((void*)ta, (void*)tb);
	//因为SwapWithPointerAddress函数实际是对值参数进行操作的，因此所有操作都只是对函数内部的副本进行操作。
	//所以外部的实参并不会受到影响。
	cout << "ta = " << ta << "\n" << "tb = " << tb << endl;
	cout << "address ta = " << (void *)ta << "\n" << "address tb = " << (void*)tb << endl;
	cout << "address in ta = " << &ta << "\n" << "address in tb = " << &tb << endl;
	cout << endl;

	cout << "(4)" << endl;
	int x = 1, y = 2;
	int &rx = x;
	int &ry = y;
	
	SwapWithPointerAddress(x, y);
	cout << rx << endl;
	cout << ry << endl;

}
