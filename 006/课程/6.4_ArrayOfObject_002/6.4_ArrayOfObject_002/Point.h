#pragma once

class Point
{
	public:
	Point();
	Point(int x, int y);
	~Point();
	void move(int newX, int newY);
	int getX() const { return x; };
	int getY() const { return y; };
	
	private:
	int x, y;
};