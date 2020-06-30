// 10.5_SequenceContainer_007.cpp : This file contains the 'main' function. Program execution begins and ends there.
//利用优先队列，模拟细胞分裂的过程。给出的前提是，细胞会在诞生后的500-2000秒内分裂为两个细胞。

#include <iostream>
#include <queue>
#include <ctime>
//不清楚示范代码中引入的这个头文件是干嘛的，好像删掉也没什么错误。
#include <cstdlib>
using namespace std;

//程序的设计思路是，创建Cell类构造时输入时间作为出生时间，根据出生时间算出其分裂时间；创建优先级队列cellQueue，用cellQueue作为细胞存储和“分裂”的场所。
//在Cell类内设计split()函数。在split()函数内根据母细胞的分裂时间创建两个新的子细胞，然后压入cellQueue。
//在Cell类内重载“<”操作符，用于优先级队列内的排序。重载时，认定分裂时间越早的细胞“越大”。
//由于优先级队列cellQueue会始终把最“大”的元素放在队列最顶端，因此最顶端的元素一定都是最“大”的细胞。
//设定一个循环，循环条件为队列cellQueue最顶端的细胞的分裂时间小于某自定义的时间。在每轮循环中，对队列最顶端的细胞执行split()函数，然后将该细胞从队列中弹出。
//循环结束即完成了特定时间内细胞分裂的模拟。

const int SPLIT_TIME_MIN = 500;
const int SPLIT_TIME_MAX = 2000;

class Cell;
priority_queue<Cell> cellQueue;

class Cell
{
	private:
	static int count;
	int id;
	int time;

	public:
	Cell(int birth):
		id(count++)
	{
		int r = rand() % (SPLIT_TIME_MAX - SPLIT_TIME_MIN) + SPLIT_TIME_MIN;
		time = birth + r;
	}
	//注意，这里似乎由于priority_queue中的元素都是const，所以所有的函数都必须写成const，否则会无法调用。
	int getID() const { return id; }
	int getSplitTime() const { return time; }
	//这里课上和书上给出的代码都没有将函数变为常函数，我进行了调整。
	void split() const
	{
		Cell child1(time), child2(time);
		cout << time << "s: Cell #" << id << " split into #" << child1.getID() << " and #" << child2.getID() << endl;
		cellQueue.push(child1);
		cellQueue.push(child2);
	}
	//这里需要重载“<”的原因是，priority_queue中会利用“<”对其中的元素进行“大小”排列。
	//这里我们希望分裂时间越晚的细胞越小，分裂时间越早的细胞越大。
	bool operator < (const Cell &s) const { return time > s.time; }
};
int Cell::count = 0;

int main()
{	
	//用srand()准备随机数种子。
	srand(static_cast<unsigned>(time(0)));
	cout << "Please input simulation time: ";
	int t;
	cin >> t;
	cellQueue.push(Cell(0));
	//由于Cell中重载“<”运算符时是让分裂时间越早的细胞越大，因此队列最顶部的一定是“最大”的细胞。
	while(cellQueue.top().getSplitTime() < t)
	{
		//对最大的细胞执行分裂，让其将分裂出来的细胞压入队列的末尾。
		cellQueue.top().split();
		//由于最大的细胞已经完成分裂，不必要继续在队列中，因此将其弹出。
		cellQueue.pop();
	}
}
