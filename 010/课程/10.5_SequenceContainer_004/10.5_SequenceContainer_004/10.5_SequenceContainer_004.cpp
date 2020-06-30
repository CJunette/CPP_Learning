// 10.5_SequenceContainer_004.cpp : This file contains the 'main' function. Program execution begins and ends there.
//书上p416关于向向量中插入元素导致迭代器、指针、引用失效的例子

#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<int> s;
	s.reserve(3);
	s.push_back(1);
	s.push_back(2);
	vector<int>::iterator iter0 = s.begin();
	vector<int>::iterator iter1 = s.begin() + 1;
	int *p0 = &s[0];	
	int *p1 = &s[1];
	int &r0 = s[0];
	int &r1 = s[1];
	cout << "p0: " << p0 << endl;
	cout << "p1: " << p1 << endl;
	cout << endl;

	cout << "after inserting an element:" << endl;
	s.insert(iter1, 3);
	//由于iter0是在插入位置之前的，因此这个迭代器并不会失效。
	cout << "*iter0: " << *iter0 << endl << "*p0: " << *p0 << endl;
	//而iter1是在插入位置之后的，因此迭代器会失效。下面这行代码会卡住，无法运行。
	//cout << *iter1 << " " << *p1 << endl;
	//可以发现，插入位置后面的指针在为改变容量时，插入前后并没有发生变化，只是其中的值发生了改变。调用指针并不会导致程序出错（以C++标准而言是不正确的，但当前编译环境下是正确的）。
	cout << "p0: " << p0 << endl;
	cout << "p1: " << p1 << endl;
	//同样的，调用引用也不会导致程序出错。
	cout << "r0: " << r0 << endl;
	cout << "r1: " << r1 << endl;
	cout << endl;

	cout << "after increasing the capacity:" << endl;
	s.insert(s.end(), 4);
	//当容量发生改变后，可以看到原先的引用和指针所指向的地址中的内容已经被清除。
	cout << "*p0: " << *p0 << endl;
	cout << "*p1: " << *p1 << endl;
	cout << "r0: " << r0 << endl;
	cout << "r1: " << r1 << endl;
	int *newp0 = &s[0];
	int *newp1 = &s[1];
	//整个vector被转移到了新的地址。
	cout << "newp0: " << newp0 << endl;
	cout << "newp1: " << newp1 << endl;
}