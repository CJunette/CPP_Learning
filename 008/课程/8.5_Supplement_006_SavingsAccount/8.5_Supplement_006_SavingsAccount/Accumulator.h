#pragma once
#include "Date.h"

class Accumulator
{
	public:
	//����Accumulator�Ĺ��캯������΢�޸���һ�£����ڶ�������valueȥ���ˡ�
	//��Ϊ��ʹ���Ǹ������������ʱ��Ҳ��������0�ģ�������ֱ��ȥ����
	Accumulator(Date date);
	double getSum(Date date) const;
	void change(Date date, double value);
	void reset(Date date, double value);

	private:
	Date lastDate;
	//���ﲻ��valueҲ�ǿ��Եġ�ֻ�������Ļ������е�change()������balance�����ı�ǰִ�С�
	//���⣬��settle()ʱ��������ִ��change()��ִ��getSum()��
	//��������ڵ��������ͻ��һЩ����ϢʱֻҪִ��getSum()���ɡ�
	double value;
	double sum;
};