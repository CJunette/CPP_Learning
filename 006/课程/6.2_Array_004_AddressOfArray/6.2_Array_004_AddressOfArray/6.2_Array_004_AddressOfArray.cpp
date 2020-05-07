// 6.2_Array_004_AddressOfArray.cpp : This file contains the 'main' function. Program execution begins and ends there.
//从书上p193的内容出发想到的一些问题。
//这里出现的溢出问题是不会在编译器中报错的，因此要非常重视！

#include <iostream>
using namespace std;

//3.对于这样一个函数，当形参要求数组有3个元素，而实参只给两个元素的话，程序就会按着数组的数据类型和最后一个元素的地址去向后访问数组以外的内存上存储的值。
//6.根据书上p194所说，通常不指定数组的第一维大小，即使指定也会被忽略。因此这里其实可以直接写“sum(int x[])”。
int sum(int x[3])
{
	int sum = 0;
	for (int i = 0;i < 3; i++)
	{
		sum += x[i];
	}
	return sum;
}

int main()
{
	//1.连续声明的静态数组，它们在内存上的地址分配也是连续的。
	//1.查看的方式就是调试时在locals找到对应变量，然后“右键-go to disassembly”。
	static int a[1] = { 1 };
	static int b[2] = { 2 , 3 };
	//4.如果下面这行代码被启用，那么b[2]后面紧接着的就是i，在sum()中访问b[2]之外的元素时，也就会访问到i。
	/*
	static int i = 56;
	*/
	//5.这里就是我说道的问题。sum()函数中可能出现的溢出访问如果访问的值还是整型的话，可能还会输出某个值；但如果紧接着b[2]的静态变量是其他类型的话，就会出现无法运算的问题。
	//5.不过从另一个角度说，能有明确的报错至少是好过没有报错但是结果有问题。
	/*
	static string a = "yes";
	*/
	static int c[3] = { 4 , 5 , 6 };
	static int d[4] = { 7, 8, 9, 10 };
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
	cout << d << endl;
	//4.这是为了方便看到i的地址。
	/*
	cout << &i << endl;
	*/

	//2.连续声明的非静态数组，它们在内存上虽然也是连续摆放的，但是中间有一些空间没有被完全填满。
	int e[1] = { 1 };
	int f[2] = { 2 , 3 };	
	int g[3] = { 4 , 5 , 6 };
	int h[4] = { 7, 8, 9, 10 };
	//2.因此在取这些数组的地址的时候，虽然地址的变化符合数组大小变化的规律，但是地址并不紧密相邻。
	cout << d << endl;
	cout << e << endl;
	cout << f << endl;
	cout << h << endl;

	cout << endl;

	//3.因此，对于static数组而言，就是去访问紧邻着的下一个静态对象的值，如果下一个对象是i，那就访问i，如果是数组c，那就访问数组c的第一个元素。
	cout << "static: " << sum(b) << endl;
	//3.而对于非static数组而言，就是访问数组以外的垃圾值。
	//3.如果减掉我们在函数中加上去的f的那两个值，这里的那个位于数组区域以外的值其实是十六进制的FFFFFFFFCCCCCCCC。我不清楚这个值有啥特定含义，但我感觉似乎也应该它也不是一个完全没有意义的值。
	cout << "non-static: " << sum(f) << endl;

	//7.之所以会有上面的这种情况，是因为C++不会因为内存溢出而报错。
	int j[1] = { 1 };
	cout << j[1] << endl;
}

