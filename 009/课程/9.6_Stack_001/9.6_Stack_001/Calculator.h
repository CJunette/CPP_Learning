#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include "Stack.h"

class Calculator
{
	private:
	//0.֮��������ֻ��һ��ջ������Ϊ���Calculatorֻ֧�ֵ������㣬ÿ��ֻ����һ�������������������ⴴ��һ��ջ�������������
	//0.�����ڲ������ܶ඼�Ƕ�Ԫ�ģ���˻�����Ҫһ��������ջ��
	Stack<double> s;
	void enter(double num);
	bool getTwoOperands(double &opnd1, double &opnd2);
	void compute(char op);
	public:
	void run();
	//0.clear()���ڽ����ǰ�εļ�����������ʾ�������н�����Ϊ�˹��к��������Ҿ�����ʵ�Ӵ��������������������ó�˽�е�Ҳ���ԡ�
	void clear();
};

//1.ע�����������������һ����Ա������
//1.������������istringstream���͵Ķ�����ʵ�ֽ��ַ���ת��Ϊdouble�����Ŀ�ġ���Ҫ<sstream>ͷ�ļ���
double stringToDouble(const std::string &str)
{	
	//1.��str�д����������͵��ַ���ʱ�����ֱ����ڿ�ͷλ�ã���ͨ����stream >>result;���Ϳ��Խ��ַ�����ʽ������ת��Ϊdouble��������result�С�
	std::istringstream stream(str);
	double result;
	stream >> result;
	return result;
}

void Calculator::enter(double num)
{
	s.push(num);
}

bool Calculator::getTwoOperands(double &opnd1, double &opnd2)
{
	if(s.isEmpty())
	{
		std::cerr << "Missing operand!" << std::endl;
		return false;
	}
	opnd1 = s.pop();
	if(s.isEmpty())
	{
		std::cerr << "Missing operand!" << std::endl;
		return false;
	}
	opnd2 = s.pop();
	return true;
}

void Calculator::compute(char op)
{
	double operand1, operand2;
	bool result = getTwoOperands(operand1, operand2);
	//2.ע�⣬���������������������ȡ��ֵ�ˣ����ܽ�����һ�����㡣��Ҫ�������if��䡣
	if(result)
	{
		switch(op)
		{
			//2.Ҫע�⣬��Ϊ�Ǻ���ȳ�����������Ĳ���˳��͵���ʱ��ʶ����˳��Ҫ��һ�¡�������Ҳ������getTwoOperands()���ڵ�����ʱ��͵�����opnd2���ٵ�����opnd1����
			//2.�ȵ����Ĳ�����operant1�Ǻ����Ĳ�������Ҫ���ں��棻�󵯳��Ĳ�����operant2���ȷ���Ĳ�������Ҫ����ǰ�档
			case '+':
				s.push(operand2 + operand1);
				break;
			case '-':
				s.push(operand2 - operand1);
				break;
			case '*':
				s.push(operand2 * operand1);
				break;
			//2.������/��ʱ����Ҫ�жϳ����Ƿ�Ϊ0��
			case '/':
				if(operand2 == 0)
				{
					std::cerr << "Divide by 0!" << std::endl;
					s.clear();
				}
				else
				{
					s.push(operand2 / operand1);
				}
				break;
			case '^':
				s.push(pow(operand2, operand1));
				break;
			default:
				std::cerr << "Unknown operator" << std::endl;
				break;
		}
		std::cout << "=" << s.peek() << " ";
	}
	else
	{
		//2.���������㣬�����ջ��
		s.clear();
	}
}

//3.run()�Ļ���˼·�ǣ��������������ʱ������ѹ��Stack����s����������ǲ�����ʱ��ִ�м��������
void Calculator::run()
{
	std::string str;
	//3.����ġ�,����ָ����ִ�С�,�����Ĳ�����Ȼ���ԡ�,���Ҳ��ֵ��Ϊ����ֵ���ء�
	while(std::cin >> str, str != "q")
	{
		switch(str[0])
		{
			case 'c':
				s.clear();
				break;
			//3.������-��ʱ����Ҫ�ж��Ǹ��Ż��Ǽ��š�
			case '-':
				//3.���size����1����˵���Ǹ��š���ʱ����Ҫ��strѹ��ջ��
				if(str.size() > 1)
				{
					enter(stringToDouble(str));
				}
				//3.������ǲ�������ִ�м��������
				else
				{
					compute(str[0]);
				}
				break;
			case '+':
			case '*':
			case '/':
			case '^':
				compute(str[0]);
				break;

			//3.Ĭ�������������ǲ��������ǲ������������
			//3.����Ĭ���û���������ʱ��������������ַ�����
			//3.�����ʹ��ʱ����ʧ��û�мӿո�д�ˡ�4+������3/�������ı��ʽ�������ķ��Żᱻ���ԡ�
			//3.����˳�ʱû���á�q�������á�ctrl + c������str���ᱣ���ϴ�ѭ����ֵ��Ȼ����ִ��һ��ѭ����������ɿ��ܵĴ��󣩡�
			default:
				enter(stringToDouble(str));
				break;
		}
	}
}

void Calculator::clear()
{
	s.clear();
}