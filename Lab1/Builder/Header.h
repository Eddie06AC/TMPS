#ifndef HEADER_H_
#define HEADER_H_

#include<iostream>

using namespace std;

class Smartphone
{	
public:
	string class_device;
	int camera;
	int count_camera;
	string cpu;
	int memory;
	int storage;
	int price;
	void specifications();
};

class Builder 
{
public:
	virtual string get_class_device() = 0;
	virtual int get_camera() = 0;
	virtual int get_count_camera() = 0 ;
	virtual string get_cpu() = 0;
	virtual int get_memory() = 0;
	virtual int get_storage() = 0;
	virtual int get_price() = 0;
};

class Director 
{
private:
	Builder* builder;
public:
	void setBuilder(Builder* builder);
	Smartphone* getSmartphone();
	
};

class Builder_Flagship_smartphone : public Builder 
{
public:
	virtual string get_class_device();
	virtual int get_camera();
	virtual int get_count_camera();
	virtual string get_cpu();
	virtual int get_memory();
	virtual int get_storage();
	virtual int get_price();


};

class  Builder_Sub_flagship_smartphone : public Builder
{
	virtual string get_class_device();
	virtual int get_camera();
	virtual int get_count_camera();
	virtual string get_cpu();
	virtual int get_memory();
	virtual int get_storage();
	virtual int get_price();
};

class  Builder_Budget_smartphone : public Builder
{
	virtual string get_class_device();
	virtual int get_camera();
	virtual int get_count_camera();
	virtual string get_cpu();
	virtual int get_memory();
	virtual int get_storage();
	virtual int get_price();
};

#endif // !HEADER_H_
