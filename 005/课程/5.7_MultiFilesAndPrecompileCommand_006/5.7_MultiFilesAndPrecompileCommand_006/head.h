#include <iostream>

//头文件中的类不会发生重复定义的问题。
class Point
{
	public:
	Point(int xx = 0, int yy = 0) :
		x(xx), y(yy)
	{
		count++;
	}
	Point(Point &pnt) :
		x(pnt.x), y(pnt.y)
	{
		count++;
	}
	~Point()
	{
		count--;
	}
	int getX() const { return x; }
	int getY() const { return y; }
	static void showCount()
	{
		std::cout << "Count: " << count << std::endl;
	}

	private:
	int x, y;
	static int count;
};

class Line
{
	public:
	Point p;
};


//如果是inline函数同样也不会发生重复定义的问题。
inline void helloWorld()
{
	std::cout << "hello world" << std::endl;
}

//头文件中的函数和变量还是会发生重复定义的问题。
/*
int a;

int calDif(Point pnt)
{
	return pnt.getX() - pnt.getY();
}
*/