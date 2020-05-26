#pragma once
#include "matrix.h"

class LinearEqu: public Matrix
{
	public:
	LinearEqu(int nForMatrix);
	LinearEqu(LinearEqu const &le);
	~LinearEqu();

	//用两个矩阵对LinearEqu对象进行参数设置。一个用于初始化参数矩阵matrix，一个用于初始化常数项矩阵cons。
	void setLinearEqu(double const *forMatrix, double const *forLE);
	//用于解方程组。
	bool solve();

	double getCons(int) const;
	double getSolution(int) const;
	int getOrder(int) const;	
	void printLinearEqu() const;
	void printSolution() const;
	void printOrder() const;

	private:
	//用于存放等式右边的常数项。
	double *cons;
	//用于存放最终结果，用0作为初始值。
	double *solution;
	//用于存放方程组未知数的解。
	int *order;

	protected:
	//用于在对系数矩阵做列调整时，同时更改未知数的排列顺序。
	void swapOrder(int i1, int i2);
	//用于在对系数矩阵做行调整时，同时对常数项矩阵进行行调整。
	void swapRowForCons(int i1, int i2);
	//用于在计算出未知数后对所有未知数进行排序。
	void sortSolution();
};