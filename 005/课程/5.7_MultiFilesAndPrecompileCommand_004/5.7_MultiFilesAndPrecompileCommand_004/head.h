#include <iostream>

using namespace std;

//��������ͨ��������ͨ���������������ࡢ�����������ֻ࣬Ҫ��ͷ������������Ȼ��������������Ƕ�׵��õ����ظ�����ģ����ն��ᱨ��

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