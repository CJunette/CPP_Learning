#pragma once
#include <iostream>
using namespace std;

class Point
{
	public:
	Point(int xx = 0, int yy = 0);
	Point(Point &pnt);
	~Point();
	int getX() const;
	int getY() const;
	static void showCount();

	private:
	int x, y;
	static int count;
};

//书上说到，内联函数的定义最好出现在头文件中，同时要保证其在不同编译单元的可见性。原因是，inline的设计目的是为了避免函数调用而直接将函数代码嵌入其他代码中。
//如果我们在头文件中声明，但将定义移至其他源文件。虽然不会报错，但如果在主函数中进行使用这个inline函数，它就会去源文件中调用定义代码并执行，也就是说，这就不可避免的需要进行调用。这样一来，inline函数与普通函数也就没有区别了。
//不过这个结果似乎在汇编代码上看不出区别。
inline void countChange()
{
	cout << "count number changed" << endl;
}