// 2.4_002.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	while ( true )
	{
		int day;
		cout << "Please input a number from 0 to 6.\n";
		cin >> day;

		switch ( day )
		{
			//如果不写“break;”，则会从当前case开始遍历之后所有的case。
			case 0: 
				cout << "Dimanche\n"; 
				//break;
			case 1: 
				cout << "Lundi\n"; 
				//break;
			case 2: 
				cout << "Mardi\n"; 
				//break;
			case 3: 
				cout << "Mercredi\n"; 
				//break;
			case 4: 
				cout << "Jeudi\n"; 
				//break;
			case 5: 
				cout << "Vendredi\n"; 
				//break;
			case 6: 
				cout << "Samedi\n"; 
				//break;
			default: 
				cout << "Wrong input\n"; 
				//break;
		}

	}    
}