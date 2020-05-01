#ifndef _CLIENT_H
#define _CLIENT_H

#include <iostream>
class Client
{
	public:
	Client();
	Client(Client &clt);
	~Client();

	static void changeServerName(std::string s);
	static int getClientNumber();
	static std::string getServerName();

	private:
	static std::string ServerName;
	static int ClientNum;
};

#endif //_CLIENT_H