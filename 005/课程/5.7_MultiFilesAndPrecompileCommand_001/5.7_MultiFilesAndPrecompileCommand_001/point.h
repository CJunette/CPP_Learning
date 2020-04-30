//Headfile
//point.h
#pragma once
#include <iostream>
using namespace std;

//�������ᵽ���������Ҫ����ռ�Ķ���д��ͷ�ļ��еĻ������ܻᵼ�¶��Դ�ļ�����ͷ�ļ�ʱ���ռ��ڲ�ͬ���뵥Ԫ�б������Ρ�
//��������ʱ��֪���������˼����Ӧ�û��ڽ�Ԥ���봦���ʱ���ᵽ��
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

//����˵�������������Ķ�����ó�����ͷ�ļ��У�ͬʱҪ��֤���ڲ�ͬ���뵥Ԫ�Ŀɼ��ԡ�ԭ���ǣ�inline�����Ŀ����Ϊ�˱��⺯�����ö�ֱ�ӽ���������Ƕ�����������С�
//���������ͷ�ļ�������������������������Դ�ļ�����Ȼ���ᱨ����������������н���ʹ�����inline���������ͻ�ȥԴ�ļ��е��ö�����벢ִ�У�Ҳ����˵����Ͳ��ɱ������Ҫ���е��á�����һ����inline��������ͨ����Ҳ��û�������ˡ�
//�����������ƺ��ڻ������Ͽ���������
inline void countChange()
{
	cout << "count number changed" << endl;
}