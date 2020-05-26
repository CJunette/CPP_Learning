#include "linearEqu.h"
#include <iostream>

LinearEqu::LinearEqu(int nForMatrix):
	Matrix(nForMatrix)
{
	cons = new double[nForMatrix];
	solution = new double[nForMatrix];
	order = new int[nForMatrix];
	for(int i = 0; i < nForMatrix; i++)
	{
		order[i] = i;
	}
	//��0��ʼ�����г�Ա��
	for(int i = 0; i < nForMatrix; i++)
	{
		solution[i] = 0;
	}
}

LinearEqu::LinearEqu(LinearEqu const &le):
	Matrix(le)
{
	cons = new double[le.getSize()];
	solution = new double[le.getSize()];
	order = new int[le.getSize()];

	for(int i = 0; i < le.getSize(); i++)
	{
		cons[i] = le.getCons(i);
	}
	for(int i = 0; i < le.getSize(); i++)
	{
		solution[i] = le.getSolution(i);
	}
	for(int i = 0; i < le.getSize(); i++)
	{
		order[i] = le.getOrder(i);
	}
}

LinearEqu::~LinearEqu()
{
	delete[] cons;
	delete[] solution;
	delete[] order;
}

double LinearEqu:: getCons(int i) const
{
	return cons[i];
}

double LinearEqu::getSolution(int i) const
{
	return solution[i];
}

int LinearEqu::getOrder(int i) const
{
	return order[i];
}

void LinearEqu::printLinearEqu() const
{
	int sz = getSize();
	for(int i = 0; i < sz; i++)
	{
		for(int j = 0; j < sz; j++)
		{
			std::cout << getElement(i, j) << "  ";
		}
		std::cout << "   " << cons[i] << std::endl;
	}
}

void LinearEqu::swapOrder(int i1, int i2)
{	
	int temp;	
	temp = order[i2];	
	order[i2] = order[i1];
	order[i1] = temp;
}

void LinearEqu::setLinearEqu(double const *forMatrix, double const *forLE)
{
	setMatrix(forMatrix);
	int sz = getSize();
	for(int i = 0; i < sz; i++)
	{
		cons[i] = forLE[i];
	}
}

void LinearEqu::swapRowForCons(int i1, int i2)
{
	double temp;
	temp = cons[i1];
	cons[i1] = cons[i2];
	cons[i2] = temp;
}

void LinearEqu::printOrder() const
{
	int sz = getSize();
	for(int i = 0; i < sz; i++)
	{
		std::cout << order[i] << " ";
	}
	std::cout << std::endl;
}

void LinearEqu::sortSolution()
{
	int sz = getSize();
	for(int i = 0; i < sz; i++)
	{
		if(order[i] != i)
		{
			for(int j = 0; j < sz; j++)
			{
				if(order[j] == i)
				{
					int temp1;
					temp1 = order[i];
					order[i] = order[j];
					order[j] = temp1;
					double temp2;
					temp2 = solution[i];
					solution[i] = solution[j];
					solution[j] = temp2;
				}
			}
		}
	}
}

bool LinearEqu::solve()
{
	int sz = getSize();
	//ע�⣡����k = sz - 2��ѭ�������һ�
	for(int k = 0; k < sz - 1; k++)
	{
		//ִ�����н�����
		int r = k, c = k;
		//����ʽ��Ԫ���е�������ֵΪ0ʱ��˵�������ʽֻ��0Ԫ�ء�
		if(findMax(r, c) == 0)
		{
			return false;
		}

		if(r != k)
		{
			swapRow(k, r);
			swapRowForCons(k, r);
		}		
		if(c != k)
		{
			swapColumn(k, c);
			swapOrder(k, c);
		}
		
		std::cout << "after swap" << std::endl;
		printLinearEqu();
		std::cout << std::endl;
		//������н�����

		//ִ�й�һ�����㡣
		for(int j = k + 1; j < sz; j++)
		{
			double value = getElement(k, j) / getElement(k, k);
			setElement(k, j, value);
		}
		cons[k] /= getElement(k, k);
		std::cout << "after normalization" << std::endl;
		printLinearEqu();
		std::cout << std::endl;
		//��ɹ�һ�����㡣

		//ִ����ȥ���㡣
		for(int i = k + 1; i < sz; i++)
		{
			for(int j = k + 1; j < sz; j++)
			{
				double value = getElement(i, j) - getElement(i, k) * getElement(k, j);
				setElement(i, j, value);
			}
			cons[i] -= getElement(i, k) * cons[k];
		}
		std::cout << "after elimination" << std::endl;
		printLinearEqu();
		std::cout << std::endl;
		//�����ȥ���㡣				
	}

	//�����ʱmatrix[size-1][size-1]��ֵΪ0����˵��������û��Ψһ�⡣��x[size-1]ǰ�Ĳ���Ϊ0��˵��x[size-1]����Ϊ�κ�ʵ������
	//���ڸ��������ԣ���Ϊ��ʾ���������Ե���0����С��һ����С������
	if(fabs(getElement(sz - 1, sz - 1)) < 1e-15)
	{
		return false;
	}

	double s1 = cons[sz - 1];
	double s2 = getElement(sz - 1, sz - 1);
	double s3 = s1 / s2;
	solution[sz - 1] = s3;

	//ע�⣬������Ϊsize-1��ֵ�Ѿ�������ˣ�����Ҫ��sz-2��ʼ��
	//���ң���������Ǵ�0��ʼ�ģ�����ѭ��������i >= 0��
	for(int i = sz - 2; i >= 0; i--)
	{
		double sum = 0;
		for(int j = 0; j < sz; j++)
		{
			//����֮���Կ�����ô������Ϊ����0��solution��ʼ���ˡ�
			sum += getElement(i, j) * solution[j];
		}
		solution[i] = cons[i] - sum;
	}	
	sortSolution();
	return true;
}

void LinearEqu::printSolution() const
{
	std::cout << "The solution is " << std::endl;
	int sz = getSize();
	for(int i = 0; i < sz; i++)
	{
		std::cout << "x" << order[i] << " = " << solution[i] << std::endl;
	}
}

