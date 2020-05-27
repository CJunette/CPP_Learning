#include "matrix.h"
#include <iostream>
#include <cmath>

Matrix::Matrix(int n):
	size(n)
{
	matrix = new double *[n];
	for(int i = 0; i < n; i++)
	{
		matrix[i] = new double[n];
	}
}

Matrix::Matrix(Matrix const &m):
	size(m.size)
{
	matrix = new double *[m.size];
	for(int i = 0; i < m.size; i++)
	{
		matrix[i] = new double[m.size];
	}
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
}

Matrix::~Matrix()
{
	for(int i = 0; i < size; i++)
	{
		delete[] matrix[i];
	}
	delete[] matrix;
}

void Matrix::setMatrix(const double *source)
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			double temp = source[i * size + j];
			matrix[i][j] = temp;
		}
	}
}

void Matrix::printMatrix() const
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			std::cout << matrix[i][j] << "  ";
		}
		std::cout << std::endl;
	}
}

double Matrix::getElement(int i, int j) const
{
	return matrix[i][j];
}

void Matrix::setElement(int i, int j, double value)
{
	matrix[i][j] = value;
}

int Matrix::getSize() const
{
	return size;
}

double Matrix::findMax(int &a, int &b)
{
	double max = 0;
	//注意！这里要让i和j以a、b为起始值。
	for(int i = a; i < size; i++)
	{
		for(int j = b; j < size; j++)
		{
			//注意，这里用的是fabs()，这个是针对浮点数求绝对值的函数。
			//abs()则是针对整数求绝对值的函数。
			if(fabs(matrix[i][j]) > max)
			{
				a = i;
				b = j;
				max = matrix[i][j];
			}
		}
	}
	return max;
}

void Matrix::swapRow(int i1, int i2)
{
	double *temp = new double[size];
	for(int j = 0; j < size; j++)
	{
		temp[j] = matrix[i1][j];
	}
	for(int j = 0; j < size; j++)
	{
		matrix[i1][j] = matrix[i2][j];
	}
	for(int j = 0; j < size; j++)
	{
		matrix[i2][j] = temp[j];
	}
	delete[] temp;
}

void Matrix::swapColumn(int j1, int j2)
{
	double *temp = new double[size];
	for(int i = 0; i < size; i++)
	{
		temp[i] = matrix[i][j1];
	}
	for(int i = 0; i < size; i++)
	{
		matrix[i][j1] = matrix[i][j2];
	}
	for(int i = 0; i < size; i++)
	{
		matrix[i][j2] = temp[i];
	}
	delete[] temp;
}