// 12.5_Supplement_002_SavingsAccount.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "Account.h"
#include "Accumulator.h"
#include "Date.h"
using namespace std;

struct deleter
{
	template<class T>
	void operator ()(T *p)
	{
		delete p;
	}
};

class Controller
{

	public:
	Controller(const Date &date):
		date(date), end(false)
	{}
	~Controller()
	{
		for_each(accounts.begin(), accounts.end(), deleter());
	}
	const Date &getDate() const { return date; }
	bool isEnd() const { return end; }

	bool runCommand(const string &cmdLine)
	{
		istringstream str(cmdLine);
		char cmd, type;
		int index, day;
		double amount, credit, rate, fee;
		string id, desc;
		Account *account;
		Date date1, date2;
		str >> cmd;
		switch(cmd)
		{
			case 'a':
				str >> type >> id;
				if(type == 's')
				{
					str >> rate;
					accounts.push_back(new SavingsAccount(date, id, rate));
				}
				else if(type == 'c')
				{
					str >> credit >> rate >> fee;
					accounts.push_back(new CreditAccount(date, id, credit, rate, fee));
				}
				else
				{
					throw runtime_error("Unknown type!");
				}
				break;

			case 'd':
				str >> index >> amount;
				getline(str, desc);
				accounts[index]->deposit(date, amount, desc);
				break;

			case 'w':
				str >> index >> amount;
				getline(str, desc);
				accounts[index]->withdraw(date, amount, desc);
				break;

			case 's':
				for(int i = 0; i < accounts.size(); i++)
				{
					cout << "[" << i << "]";
					accounts[i]->show(cout);
					cout << endl;
				}
				return false;
				break;

			case 'c':
				str >> day;
				if(day > date.getMonthDays() || day < 0)
				{
					throw runtime_error("Invalid day!");
				}
				else if(day < date.getDay())
				{
					throw runtime_error("You can't go back to the pase!");
				}
				else
				{
					date = Date(date.getYear(), date.getMonth(), day);
				}
				break;

			case 'n':
				if(date.getMonth() == 12)
				{
					date = Date(date.getYear() + 1, 1, 1);
				}
				else
				{
					date = Date(date.getYear(), date.getMonth() + 1, 1);
				}
				for(typename vector<Account *>::iterator iter = accounts.begin(); iter != accounts.end(); iter++)
				{
					(*iter)->settle(date);
				}
				break;

			case 'q':
				str >> date1 >> date2;
				if(date < date1)
				{
					throw runtime_error("That day has yet to come!");
				}
				else if(date2 < date1)
				{
					throw runtime_error("Error: End date should be later than begin date!");
				}
				Account::query(date1, date2);
				return false;
				break;

			case 'e':
				end = true;
				return false;

			default:
				throw runtime_error("Unknown command!");
				break;
		}
		return true;
	}

	private:
	Date date;
	vector<Account *> accounts;
	bool end;
};

int main()
{
	/*
	vector<Account *>accounts(0);
	Date date(2008, 11, 1);
	accounts.resize(1);
	accounts[0] = new SavingsAccount(date, "S3755217", 0.015);
	accounts.resize(2);
	accounts[1] = new SavingsAccount(date, "02342342", 0.015);
	accounts.resize(3);
	accounts[2] = new CreditAccount(date, "C5392394", 10000, 0.0005, 50);

	accounts[0]->deposit(Date(2008, 11, 5), 5000, "salary");
	accounts[2]->withdraw(Date(2008, 11, 15), 2000, "buy a cell");
	accounts[1]->deposit(Date(2008, 11, 25), 10000, "sell stock 0323");
	accounts[2]->settle(Date(2008, 12, 1));
	accounts[2]->deposit(Date(2008, 12, 1), 2016, "repay the credit");
	accounts[0]->deposit(Date(2008, 12, 5), 5500, "salary");

	for(int i = 0; i < accounts.size(); i++)
	{
		accounts[i]->settle(Date(2009, 1, 1));
		cout << endl;
	}

	for(int i = 0; i < accounts.size(); i++)
	{
		accounts[i]->show(cout);
		cout << endl;
	}
	Date(2009, 1, 1).show();
	cout << "\tTotal: " << Account::getTotal() << endl << endl;

	Account::query(Date(2008, 11, 1), Date(2008, 11, 30));
	Account::query(Date(2008, 12, 1), Date(2008, 12, 30));
	*/

	Date date(2008, 11, 1);
	Controller controller(date);
	string cmdLine;
	const char *FILE_NAME = "commands.txt";

	ifstream fileIn(FILE_NAME, ios_base::binary);
	if(fileIn)
	{
		while(getline(fileIn, cmdLine))
		{
			//这里我觉得其实没有必要对读入文件的命令进行异常判断，因为根据下面的代码，出现异常的命令是不会被写入文件的。
			try
			{
				controller.runCommand(cmdLine);
			}
			catch(const std::exception &e)
			{
				cout << "Bad line in " << FILE_NAME << ": " << cmdLine << endl;
				cout << "Error: " << e.what();
			}
		}
		fileIn.close();
	}
	ofstream fileOut(FILE_NAME, ios_base::binary | ios_base::app);
	cout << "(a)add account (d)deposit (w)withdraw (s)show (c)change day (n)next month e(exit)" << endl;
	while(!controller.isEnd())
	{
		cout << controller.getDate() << "\tTotal: " << Account::getTotal() << "\tcommand>";
		getline(cin, cmdLine);
		try
		{
			if(controller.runCommand(cmdLine))
			{
				fileOut << cmdLine << endl;
			}
		}
		catch(AccountException &e)
		{
			cout << "Error(#" << e.getAccount()->getID() << "): " << e.what() << endl;
		}
		catch(const exception &e)
		{
			cout << "Error: " << e.what() << endl;
		}
		
	}
	fileOut.close();
}