// 12_Experiment_001.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

class CException
{
    public:
    CException() {}
	//我觉得这里把析构函数写成虚函数似乎没有什么意义。
    virtual ~CException() {}
	void Reason() const { cout << "CException" << endl; }
};

void fn1()
{
    throw CException();
}

int main()
{
	try
	{
		fn1();
	}
	catch(const CException &ce)
	{
		ce.Reason();
	}
}