#pragma once

class Matrix
{
	public:
	Matrix(int n);
	Matrix(Matrix const &m);
	~Matrix();

	void setMatrix(const double*);
	void printMatrix() const;
	int getSize() const;


	private:	
	int size;
	//实际上这里可以直接把matrix设成protect类型的，这样就可以直接在派生类中进行修改。（不过如果设成private类型也有“避免派生类对基类数据不必要的修改”的好处。）
	double **matrix;

	protected:
	//用于获取或设定矩阵中某位置的元素的值。
	double getElement(int, int) const;
	void setElement(int, int, double);

	void swapRow(int i1, int i2);
	void swapColumn(int j1, int j2);
	//用于找出k+1行和k+1列组成的子式中的最大元素。
	double findMax(int &i, int &j);
};
