#ifndef HEADER
#define HEADER
#include<iostream>

class Socket 
{
private: 
	int u;
	int w;
public:
	Socket(int u, int w);
	int get_u();
	int get_w();
};

class USA_Device
{
public:
	virtual void USA_charging(Socket* socket) = 0;
};

class USA_Smartphone : public USA_Device 
{
private:
	int u;
	int w;
public:
	USA_Smartphone();
	virtual void USA_charging(Socket* socket);
};

class EU_Device 
{
public:
	virtual void EU_charging(Socket* socket) = 0;
};

class EU_Tablet :public EU_Device
{
private:
	int u;
	int w;
public:
	EU_Tablet();
	virtual void EU_charging(Socket* socket);
};

class Adapter_EU_TO_USA : public USA_Device
{
private: 
	EU_Device* dev;
public:
	Adapter_EU_TO_USA(EU_Device* dev);
	void USA_charging(Socket* socket);
};

class Adapter_USA_TO_EU : public EU_Device
{
private:
	USA_Device* dev;
public:
	Adapter_USA_TO_EU(USA_Device* dev);
	void EU_charging(Socket* socket);
};
#endif // !HEADER
