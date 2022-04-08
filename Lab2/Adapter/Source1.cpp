#include"Header.h"
#include<iostream>

using namespace std;

Socket::Socket(int u, int w) { this->u = u; this->w = w; }

int Socket::get_u() { return this->u; }
int Socket::get_w() { return this->w; }

USA_Smartphone::USA_Smartphone() :u(120), w(50) {}

void USA_Smartphone::USA_charging(Socket* socket)
{
	if (abs(this->u - socket->get_u()) < 10 && abs(this->u - socket->get_u()) < 2)
	{
		cout << "USA device is Charging..." << endl;
	}
	else
		cout << "Error! Check your adapter." << endl;
}

EU_Tablet::EU_Tablet() : u(220), w(60) {}

void EU_Tablet::EU_charging(Socket* socket)
{
	if (abs(this->u - socket->get_u()) < 10 && abs(this->u - socket->get_u()) < 2)
	{
		cout << "Europe device is Charging..." << endl;
	}
	else
		cout << "Error! Check your adapter." << endl;
}

Adapter_EU_TO_USA::Adapter_EU_TO_USA(EU_Device* dev) 
{
	this->dev = dev;
}

void Adapter_EU_TO_USA::USA_charging(Socket* socket) 
{
	Socket tmp((int)socket->get_u()*1.83, (int)socket->get_w() * 1.2);
	this->dev->EU_charging(&tmp);
}

Adapter_USA_TO_EU::Adapter_USA_TO_EU(USA_Device* dev) 
{
	this->dev = dev;
}

void Adapter_USA_TO_EU::EU_charging(Socket* socket)
{
	Socket tmp((int)socket->get_u() * 0.55, (int)socket->get_w() * 0.83);
	this->dev->USA_charging(&tmp);
}