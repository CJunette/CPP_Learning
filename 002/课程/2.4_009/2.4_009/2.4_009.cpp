// 2.4_009.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

enum GameResult {Win, Lose, Tie, Cancle};

int main()
{
    GameResult result;
    enum GameResult omit = Cancle;

	for ( int i = Win; i <= Cancle; i++ )
	{
		result = GameResult(i);
		if ( result == omit )
		{
			cout << "The game is cancelled.\n";
		}
		else
		{
			switch ( result )
			{
				case Win:
					cout << "We've won!\n";
					break;
				case Lose:
					cout << "They've lost!\n";
					break;
				case Tie:
					cout << "Tie game!\n";
					break;				
				default:
					break;
			}
		}
	}
}
