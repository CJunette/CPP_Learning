// 3.3_006.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int RollDice();

enum Condition {Continue, Win, Lose};

int main()
{
	cout << "Please input an integer number as seed: ";
	int seed;
	cin >> seed;
	//通过增加时间变量来确保如果输入相同的数不会每次都得到相同的结果。
	time_t now = time(0);
	//调用srand()即可以产生一个种子给rand()函数，使下次调用rand()函数时rand()函数会以该种子产生随机数。
	srand(seed * (int)now);

	bool isfirstround = true;
	int sum;
	Condition con;
	int firstpoint;

	do
	{
		sum = RollDice();
		if ( isfirstround )
		{
			switch ( sum )
			{
				case 7: case 11:
					con = Win;
					break;
				case 2: case 3: case 12:
					con = Lose;
					break;
				default:
					firstpoint = sum;
					con = Continue;
					break;
			}
			isfirstround = false;
		}
		else
		{
			if ( sum == firstpoint )
			{
				con = Win;
			}
			else if ( sum == 7 )
			{
				con = Lose;
			}
			else
			{
				con = Continue;
			}
		}
		cout << endl;
	} while ( !con );
	
	switch ( con )
	{
		case Continue:
			break;
		case Win:
			cout << "You win!";
			break;
		case Lose:
			cout << "You lose!";
			break;
		default:
			break;
	}
}

int RollDice()
{
	int first, second;
	first = rand() % 6 + 1;
	cout << "The first die is " << first << " .\n";
	second = rand() % 6 + 1;
	cout << "The second die is " << second << " .\n";
	cout << "The sum is " << first + second << " .\n";
	return first + second;
}
