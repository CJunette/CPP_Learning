#pragma once

#include <iostream>
#include <sstream>
#include <cmath>
#include "Stack.h"

class Calculator
{
	private:
	//0.之所以这里只有一个栈，是因为这个Calculator只支持单步运算，每次只会有一个操作符，因此无需额外创建一个栈来保存操作符。
	//0.但由于操作符很多都是二元的，因此还是需要一个操作数栈。
	Stack<double> s;
	void enter(double num);
	bool getTwoOperands(double &opnd1, double &opnd2);
	void compute(char op);
	public:
	void run();
	//0.clear()用于将清空前次的计算结果。这里示范代码中将其设为了公有函数，但我觉得其实从代码其他部分来看，设置成私有的也可以。
	void clear();
};

//1.注意这里这个函数不是一个成员函数。
//1.这里是利用了istringstream类型的对象来实现将字符串转换为double对象的目的。需要<sstream>头文件。
double stringToDouble(const std::string &str)
{	
	//1.当str中存在数字类型的字符串时（数字必须在开头位置），通过“stream >>result;”就可以将字符串形式的数字转换为double，并存入result中。
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
	//2.注意，这里必须是两个操作数都取到值了，才能进行下一步运算。不要忘记这个if语句。
	if(result)
	{
		switch(op)
		{
			//2.要注意，因为是后进先出，所以这里的操作顺序和弹出时标识符的顺序要反一下。（或者也可以在getTwoOperands()里在弹出的时候就弹出给opnd2，再弹出给opnd1。）
			//2.先弹出的操作符operant1是后放入的操作符，要放在后面；后弹出的操作符operant2是先放入的操作符，要放在前面。
			case '+':
				s.push(operand2 + operand1);
				break;
			case '-':
				s.push(operand2 - operand1);
				break;
			case '*':
				s.push(operand2 * operand1);
				break;
			//2.遇到“/”时，需要判断除数是否为0。
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
		//2.操作数不足，则清空栈。
		s.clear();
	}
}

//3.run()的基本思路是，当输入的是数字时，将其压入Stack对象s；当输入的是操作符时，执行计算操作。
void Calculator::run()
{
	std::string str;
	//3.这里的“,”是指，先执行“,”左侧的操作，然后以“,”右侧的值作为返回值返回。
	while(std::cin >> str, str != "q")
	{
		switch(str[0])
		{
			case 'c':
				s.clear();
				break;
			//3.遇到“-”时，需要判断是负号还是减号。
			case '-':
				//3.如果size大于1，则说明是负号。此时就需要将str压入栈。
				if(str.size() > 1)
				{
					enter(stringToDouble(str));
				}
				//3.否则就是操作符，执行计算操作。
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

			//3.默认情况即传入的是操作数而非操作符的情况。
			//3.这里默认用户不会在这时传入数字以外的字符串。
			//3.如果在使用时操作失误没有加空格，写了“4+”、“3/”这样的表达式，则后面的符号会被忽略。
			//3.如果退出时没有用“q”而是用“ctrl + c”，则str还会保持上次循环的值，然后在执行一次循环（进而造成可能的错误）。
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