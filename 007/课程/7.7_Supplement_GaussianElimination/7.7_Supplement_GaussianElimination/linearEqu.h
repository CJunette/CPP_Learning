#pragma once
#include "matrix.h"

class LinearEqu: public Matrix
{
	public:
	LinearEqu(int nForMatrix);
	LinearEqu(LinearEqu const &le);
	~LinearEqu();

	//�����������LinearEqu������в������á�һ�����ڳ�ʼ����������matrix��һ�����ڳ�ʼ�����������cons��
	void setLinearEqu(double const *forMatrix, double const *forLE);
	//���ڽⷽ���顣
	bool solve();

	double getCons(int) const;
	double getSolution(int) const;
	int getOrder(int) const;	
	void printLinearEqu() const;
	void printSolution() const;
	void printOrder() const;

	private:
	//���ڴ�ŵ�ʽ�ұߵĳ����
	double *cons;
	//���ڴ�����ս������0��Ϊ��ʼֵ��
	double *solution;
	//���ڴ�ŷ�����δ֪���Ľ⡣
	int *order;

	protected:
	//�����ڶ�ϵ���������е���ʱ��ͬʱ����δ֪��������˳��
	void swapOrder(int i1, int i2);
	//�����ڶ�ϵ���������е���ʱ��ͬʱ�Գ������������е�����
	void swapRowForCons(int i1, int i2);
	//�����ڼ����δ֪���������δ֪����������
	void sortSolution();
};