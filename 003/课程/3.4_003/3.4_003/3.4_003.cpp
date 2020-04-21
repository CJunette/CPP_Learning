// 3.4_003.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int Select(int totalNum, int selectNum);

int main()
{
	int total, select;
	do
	{
		cout << "Please input total number: ";
		cin >> total;
		cout << "Please input select number: ";
		cin >> select;

		if ( total < select )
		{
			cout << "The total number must be greater than select number.\n";
		}
	} while ( total < select );
	cout << "There are " << Select(total, select) << " combination(s)" << endl;
}


//下面的备注中，C(m, n)，指排列组合的计算式。其中m指选择数，n指总数。
int Select(int totalNum, int selectNum)
{
	//即C(1, n)，从n个数中选1个数，一定有n中情况。
	if ( selectNum == 1 )
	{
		return totalNum;
	}
	//即C(2, 1)，选择数大于总数，一定没有可选的项目。
	else if ( selectNum > totalNum )
	{
		return 0;
	}
	//即C(n, n)，这样的组合一定只有1中。
	else if ( selectNum == totalNum )
	{
		return 1;
	}
	else
	{
		//这是组合式的递归形式。
		return Select(totalNum - 1, selectNum) + Select(totalNum - 1, selectNum - 1);
	}

}