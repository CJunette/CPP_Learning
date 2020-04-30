#include <iostream>

using namespace std;

//不论是普通函数、普通变量、带参数的类、不带参数的类，只要在头函数中声明，然后在主函数中因嵌套调用导致重复定义的，最终都会报错。

inline void HelloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

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


class Method
{
	public:
	void helloWorld();
};


int i;