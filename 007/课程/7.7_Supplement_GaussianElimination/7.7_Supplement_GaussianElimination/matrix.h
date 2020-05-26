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
	//ʵ�����������ֱ�Ӱ�matrix���protect���͵ģ������Ϳ���ֱ�����������н����޸ġ�������������private����Ҳ�С�����������Ի������ݲ���Ҫ���޸ġ��ĺô�����
	double **matrix;

	protected:
	//���ڻ�ȡ���趨������ĳλ�õ�Ԫ�ص�ֵ��
	double getElement(int, int) const;
	void setElement(int, int, double);

	void swapRow(int i1, int i2);
	void swapColumn(int j1, int j2);
	//�����ҳ�k+1�к�k+1����ɵ���ʽ�е����Ԫ�ء�
	double findMax(int &i, int &j);
};
