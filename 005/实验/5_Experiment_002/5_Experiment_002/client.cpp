#pragma once

#include "client.h"
#include <iostream>

Client::Client()
{
	ClientNum++;
}

Client::Client(Client &clt)
{
	ClientNum++;
}

Client::~Client()
{
	ClientNum--;
}

void Client::changeServerName(std::string s)
{
	ServerName = s;
}

int Client::getClientNumber()
{
	return ClientNum;
}

std::string Client::getServerName()
{
	return ServerName;
}