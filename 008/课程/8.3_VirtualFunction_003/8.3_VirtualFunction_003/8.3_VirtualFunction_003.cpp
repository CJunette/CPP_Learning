// 8.3_VirtualFunction_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//这里主要讨论派生类中的虚函数对基类中虚函数的覆盖及虚函数的重载。

#include <iostream>
using namespace std;

class Base0
{
	public:
	virtual void display() { cout << "Base0 display" << endl; }
	virtual void display(int a) { cout << "Base0 display" << endl; }
};

class Derived0: public Base0
{
	public:
	virtual void display() { cout << "Derived0 display" << endl; }
};

class Base1
{
	public:
	void virtual display() const { cout << "display1 in Base1" << endl; }
	//1.当下面这个有参数的display()函数不添加virtual关键字时，它不会被视为虚函数。在下面函数func1()中，输入Base2的指针仍然会调用Base1的函数。
	//1.也就是说虚函数的重载不是默认的会变成虚函数。
	void display(int a) const { cout << "display2 in Base1" << endl; }
};

class Base2: public Base1
{
	public:
	//2.这里写了“virtual”关键字，但由于与基类中的虚函数参数列表不同，因此并不是覆盖了原先的虚函数；而是创建了基类中一般成员函数的重载并使其变为虚函数，从而隐藏了基类中同名函数的其他重载（包括虚函数）。
	//2.但从虚表指针的表现看，由于其他重载被隐藏，又创建了新的虚函数，所以虚表中还是只有一个虚函数。(下面会对这句话进行纠正)
	void virtual display(int a) const { cout << "display2 in Base2" << endl; };
};

//3.这里Derived1类所做的操作其实与Base2的操作类似，就是通过重写一个虚函数（这里是重写一个已经存在的虚函数，Base2中是写存在虚函数的同名不同参数列表的虚函数），隐藏基类中与虚函数同名的其他重载。
class Derived1: public Base2
{
	public:
	void display() const { cout << "display1 in Derived" << endl; };
};

void func1(Base1 *ptr)
{
	ptr->display(1);
}

void func2(Base1 *ptr)
{
	ptr->display(1);
}

void func3(Base2 *ptr)
{
	ptr->display(1);
}

void func4(Base1 *ptr)
{
	ptr->display();
}

int main()
{
	//0.通过debug观察b0可以发现，当类中存在两个名称和返回类型都相同但参数表不同的虚函数时，参数表中这两个虚函数会有两个不同的地址。
	Base0 b0;
	//0.通过debug观察d0可以发现，虽然基类中存在两个同名不同参数表的虚函数。此时，如果派生类中重写了一个虚函数，则另一个虚函数会被隐藏；但其地址仍然可以在虚表中被看见。
	Derived0 d0;	
	//0.通过disassembly可以发现，虚表指针对应的虚表中存放的实际还是一个跳转地址，并不是函数所在的实际地址。但这个跳转地址会直接跳转到函数代码所在地址。

	//1.从这里的输出结果可以看出，此时Base1中的带参数的display()并不是虚函数。
	Base1 b1;
	Base2 b2;
	Derived1 d;
	func1(&b1);
	func1(&b2);
	func1(&d);
	cout << endl;
	
	//2.在这里，虽然Base1中无参数的虚函数display()被Base2中有参数的虚函数display(int)覆盖了。
	//2.但如果用Base1类型的指针去访问有参数有参数的display(int)，却还是访问到了在Base1中还不是虚函数的display(int)。
	//2.也就是说，在编译阶段，编译器会根据指针的类型，确定调用的成员函数在指针类型对应的类中是否为虚函数。如果是，则在之后允许使用动态绑定；如果不是，则按对象调用的方式调用成员函数。
	//2.通过disassembly可以发现，当调用的不是虚函数时，对应的语句是“call 类名::函数名”；当调用的是虚函数时，对应的语句是“call eax”。也就是说虚函数的动态绑定是依靠寄存器动态实现的。
	//2.这里其实还有个小问题，观察debug时候的b1和b2对应的_vptr会发现，虽然两者的_vptr指向不同，但_vptr指向的对象所指向的地址是相同的，都是Base1中的不带参数的display()。
	//2.这点非常奇怪，因为虽然Base1和Base2的虚表指针所指向的地址不同是符合原理的，但两者的虚函数应该是不同的，因此虚函数所在的地址也应该是不同的。
	//2.而在调用时，Base2通过虚表指针进行调用仍然是调用Base2中带参数的虚函数display(int)，不会发生错误。
	func2(&b2);
	cout << "以地址方式呈现虚表指针中所存放的地址：" << (int *)*(int *)(&b2) << endl;
	cout << "虚表中第一个函数的地址：" << (int *)*(int *)*(int *)(&b2) << endl;
	cout << "虚表中第二个函数的地址：" << (int *)*((int *)*(int *)(&b2) + 1) << endl;
	//2.进一步观察用指针调用虚函数display()和虚函数display(int)可以发现，两者在disassembly中的代码有略微的不同.
	//2.调用display()时是将“dword ptr [edx]”赋给“eax”，而调用display(int)时是将“dword ptr [edx]”赋给“eax”。
	//2.因此推断（顺便纠正改一下前面），可能这里虚表中还是存在两个虚函数的地址（这样设计的目的可能是为了保证在未来派生类中需要重写任意虚函数时都能在访问虚表时以与基类相同的偏移量访问到虚函数在虚表中的位置）。
	//2.但出于不知名原因，显示时只显示了不带参数的虚函数display()。而对于Base2而言，当需要调用虚函数时，通过一定的偏移量来访问虚表中的第二个函数地址，即可实现虚函数的调用。
	func4(&d);
	//2.通过上述地址输出和在disassembly中跳转时得到的Base2中的display(int)的地址可以发现，确实b2的虚表指针所指向的虚表内存放着两个函数地址，而且第二个函数就是Base2的虚函数display(int)。
	func3(&b2);
	cout << endl;	
	
	//3.虽然说在派生类继承基类的虚函数时，会隐藏基类与虚函数同名的所有其他函数，但当通过基类指针去调用时，仍然可以访问那些重载函数。
	//3.Derived类中重写了不带参数的虚函数display()，隐藏了带参数的虚函数display(int)。Derived类对象现在虚表所指向的是不带参数的display()。
	//3.但通过Base2类型的指针，仍然能够以对象调用的方式访问到在Derived中被隐藏的带参数的display(int)。
	func3(&d);
	//3.上一行代码的做法实际上就等同于下面这行代码。
	Base2 *pb2 = &d;
	//3.之所以这里要再用作用域限定符，是为了再次重申一下，这里的调用display(1)采用的是对象调用的方式，而非虚表指针调用的方式（d的虚表指针指向的是无参数的display()）。
	pb2->Base2::display(1);
	cout << endl;
	//3.这行代码也是同理。Base2中重写了Base1中带参数display(int)，隐藏了Base1中不带参数的display()。但通过Base1类型的指针仍能实现以对象方式调用的访问。
	func4(&b2);
	Base1 *pb1 = &b2;	
	pb1->Base1::display();
	//3.上面的一系列做法其实听违背2中所提到的“编译器根据指针类型确定被调用的成员函数是否为虚函数”的说法的。
	//3.因为如果在编译阶段确认了是否要按虚函数的方式进行处理的话，func3()和func4()其实都是应该按虚函数的方式，通过虚表指针来调用虚函数。但实际上它们调用的都不是虚表指针所指向的函数。
	//3.也就是说，即便在确定了采用虚表指针调用虚函数的方式后，在运行时程序仍然会判断要调用的函数与虚表指针所指向的虚表中的函数是否一致。当不一致时，仍然以对象的身份进行调用那个函数。

	//3.当直接用派生类对象访问被隐藏的函数时，则会报错。
	/*
	d.display(1);
	b2.display();
	*/
}
