// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<bitset>
#include <iomanip>
using namespace std;

struct MyTime
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int hour;
	unsigned int minute;
	unsigned int second;
};

int main()
{
	//2-24-(2)
	/*
	int a = 1, b = 2, c = 3;
	int d = a ^ b & -c;
	int e = b & -c;
	cout << bitset<8>(d) << endl;
	cout << bitset<8>(a ^ e) << endl;
	*/

	//2-26
	/*
start:
	char answer;
	cout << "Is it raining?\n";
	cin >> answer;
	switch ( answer )
	{
		case 'Y':
			cout << "Yes, it is raining.\n";
			break;
		case 'N':
			cout << "No, it is not raining.\n";
			break;
		default:
			goto start;
	}
	*/

	//2-28
	/*
	char input;
	while ( true )
	{
		cout << "Menu: A(dd) D(elete) S(ort) Q(uit), Select One: ";
		cin >> input;
		if ( input == 'Q' )
		{
			break;
		}
		else
		{
			switch ( input )
			{
				case 'A':
					cout << "Data has been added.\n";
					break;
				case 'D':
					cout << "Data has been deleted.\n";
					break;
				case 'S':
					cout << "Data has been sorted.\n";
					break;
				default:
					cout << "Input error.\n";					
					continue;
					break;
			}
		}
	}
	*/

	//2-29
	/*
	for ( int i = 1; i <= 100; i++ )
	{
		int count = 0;
		for ( int j = 1; j <= i; j++ )
		{
			if ( i % j == 0)
			{
				count++;
			}
		}

		if ( count == 2 )
		{
			cout << i << ' ';
		}
	}
	*/

	//2-34
	/*
	enum Color {Red, Yellow, Blue, White, Black};	
	int i = 0, j = 0, k = 0;
	int count = 0;

	while ( i <= Black )
	{
		while ( j <= Black )
		{
			if ( j == i )
			{
				j++;
				continue;
			}
			while ( k <= Black )
			{
				if ( k == i )
				{
					k++;
					continue;
				}
				else if ( k == j)
				{
					k++;
					continue;
				}

				//由于无法直接将枚举类型的成员以字符串的形式输出，所以用了这个复杂的输出代码。
				Color output;
				for ( int l = 0; l < 3; l++ )
				{
					switch ( l )
					{
						case 0: 
							output = (Color)i;
							break;
						case 1:
							output = (Color)j;
							break;
						case 2:
							output = (Color)k;
							break;
						default:
							break;
					}

					switch ( output )
					{
						case Red:
							cout << " Red\t";
							break;
						case Yellow:
							cout << " Yellow\t";
							break;
						case Blue:
							cout << " Blue\t";
							break;
						case White:
							cout << " White\t";
							break;
						case Black:
							cout << " Black\t";
							break;
						default:
							break;
					}
				}
				count++;
				k++;
				cout << endl;
			}
			j++;
			k = 0;
		}
		i++;
		j = 0;
	}
	cout << endl;
	cout << "The total number is " << count << endl;
	*/
	
	//2-35
	/*
	for ( int i = 1; i <= 9; i++ )
	{
		for ( int j = 1; j <= 9; j++ )
		{
			cout << i << " * " << j << " = " << i * j << "\t";
		}
		cout << endl;
	}
	*/

	/*
	//字母A在Ascii表中对应的数字是65，二进制为01000001。
	cout << 'A' << endl;
	cout << 'AA' << endl;
	//而'AA'实际上就是把2个二进制的65按位拼合了，得到0100000101000001；而这个数在Ascii表中没有对应，因此就被直接输出了，即十进制的16705。
	cout << bitset<16>(65) << endl;
	cout << bitset<16>(16705) << endl;
	//于是我就想到，如果是这样的话，那有没有可能输出会导致溢出的字符；结果是，单引号内只支持最多4个字符，多了就会报错。而Ascii表其实只利用了7位，因此不会导致溢出。
	cout << '~~~~' << endl;
	*/

	//2-31
	MyTime mytime;

	cout << "Please input the year:\t";
	cin >> mytime.year;

month:
	cout << "Please input the month:\t";
	cin >> mytime.month;
	if ( mytime.month > 12 || mytime.month == 0 )
	{
		cout << "Wrong month input!\n";
		goto month;
	}

day:
	cout << "Please input the day:\t";
	cin >> mytime.day;
	if ( mytime.day > 31 || mytime.day == 0 )
	{
		cout << "Wrong day input!\n";
		goto day;
	}
	else
	{
		switch ( mytime.month )
		{
			case 4: case 6: case 9: case 11:
				if ( mytime.day > 30 )
				{
					cout << "Wrong day input!\n";
					goto day;
				}
			case 2:
				if ( mytime.year % 100 != 0 && mytime.year % 4 == 0 )
				{
					if ( mytime.day > 29 )
					{
						cout << "Wrong day input!\n";
						goto day;
					}
				}
				else if ( mytime.year % 100 == 0 && mytime.year % 400 == 0 )
				{
					if ( mytime.day > 29 )
					{
						cout << "Wrong day input!\n";
						goto day;
					}
				}
				else
				{
					if ( mytime.day > 28 )
					{
						cout << "Wrong day input!\n";
						goto day;
					}
				}
				
			//case 1: case 3: case 5: case 7: case 8: case 10: case 12:
			default:
				if ( mytime.day > 31 )
				{
					cout << "Wrong day input!\n";
					goto day;
				}
				break;
		}
	}

hour:
	cout << "Please input the hour:\t";
	cin >> mytime.hour;
	if ( mytime.hour >= 24 )
	{
		cout << "Wrong hour input!\n";
		goto hour;
	}

minute:
	cout << "Please input the minute:\t";
	cin >> mytime.minute;
	if ( mytime.minute >= 60 )
	{
		cout << "Wrong minute input!\n";
		goto minute;
	}

second:
	cout << "Please input the second:\t";
	cin >> mytime.second;
	if ( mytime.second >= 60 )
	{
		cout << "Wrong second input!\n";
		goto second;
	}

	cout << "The time is "  << mytime.year << '/'
							<< mytime.month << '/'
							<< mytime.day << ' '
							<< setw(2) << setfill('0')
							<< mytime.hour << ':'
							<< setw(2) << setfill('0')
							<< mytime.minute << ':'
							<< setw(2) << setfill('0')
							<< mytime.second << endl;
}
