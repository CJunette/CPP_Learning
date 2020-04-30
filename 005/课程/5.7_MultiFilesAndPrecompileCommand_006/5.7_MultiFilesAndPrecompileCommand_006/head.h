#include <iostream>

//ͷ�ļ��е��಻�ᷢ���ظ���������⡣
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


//ͷ�ļ��еķ������ᷢ���ظ���������⡣
/*
int calDif(Point pnt)
{
	return pnt.getX() - pnt.getY();
}
*/