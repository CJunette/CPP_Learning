// 11_Homework_11-11.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <fstream>
#include "Account.h"
#include "Accumulator.h"
#include "Date.h"
#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
//要注意，如果要让vector被串行，则必须包含下面这个头文件。
#include <boost/serialization/vector.hpp>
#include <boost/serialization/map.hpp>
#include <boost/serialization/base_object.hpp>
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
	//friend class boost::serialization::access;
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
					cout << "Error: Unknown type!" << endl;
					return false;
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
					cout << "Error: Invalid day!" << endl;
					return false;
				}
				else if(day < date.getDay())
				{
					cout << "Error: you can't go back to the pase!" << endl;
					return false;
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
					cout << "Error: That day has yet to come!" << endl;
					return false;
				}
				else if(date2 < date1)
				{
					cout << "Error: End date should be later than begin date!" << endl;
					return false;
				}
				Account::query(date1, date2);
				return false;
				break;

			case 'e':
				end = true;
				return false;

			default:
				cout << "Error: Unknow command!" << endl;
				return false;
				break;
		}
		return true;
	}

	template<class Archive>
	void serialize(Archive &ar, unsigned int version);

	private:
	Date date;
	vector<Account *> accounts;
	bool end;
};

template<class Archive>
void Controller::serialize(Archive &ar, unsigned int version)
{	
	ar &date &accounts;
}


int main()
{
	Date date(2008, 11, 1);
	string cmdLine;
	Controller controller(date);
	const char *FILE_NAME = "accounts.txt";	
	ifstream fileIn(FILE_NAME, ios_base::binary);

	//将指针移到文件尾，用于判断文件是否为空。
	fileIn.seekg(0, ios::end);
	streampos fp = fileIn.tellg();

	if(fileIn && (int)fp)
	{
		fileIn.seekg(0, ios::beg);
		boost::archive::text_iarchive ia(fileIn);
		ia >> controller;
		fileIn.close();
	}
	
	cout << "(a)add account (d)deposit (w)withdraw (s)show (c)change day (n)next month e(exit)" << endl;
	while(!controller.isEnd())
	{
		cout << controller.getDate() << "\tTotal: " << Account::getTotal() << "\tcommand>";
		getline(cin, cmdLine);
		controller.runCommand(cmdLine);
	}

	ofstream fileOut(FILE_NAME, ios_base::binary);
	boost::archive::text_oarchive oa(fileOut);
	oa << controller;
	fileOut.close();
}