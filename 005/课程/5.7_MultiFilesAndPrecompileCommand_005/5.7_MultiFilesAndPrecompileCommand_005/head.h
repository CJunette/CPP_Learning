#include <iostream>

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


Point::Point(int xx, int yy) :
	x(xx), y(yy)
{
	count++;
}

Point::Point(Point &pnt) :
	x(pnt.x), y(pnt.y)
{
	count++;
}

Point::~Point()
{
	count--;
}

int Point::getX() const
{
	return x;
}

int Point::getY() const
{
	return y;
}

void Point::showCount()
{
	std::cout << "Count: " << count << std::endl;
}

int Point::count = 0;