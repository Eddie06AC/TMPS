#include"Header.h"

#include<iostream>

using namespace std;


void Smartphone::specifications() 
{
	cout << "Specification of " << class_device <<" smartphone:\n" << "Camera - " << camera << " MP " << count_camera << " pieces" << endl;
	cout << "CPU - " << cpu << "\nMemory(storage) - " << memory << "\\" << storage << " GB\nPrice - " << price<< "$\n";
}

void Director::setBuilder(Builder* builder)
{
	this->builder = builder;
}

Smartphone* Director::getSmartphone()
{
	Smartphone* smartphone = new Smartphone();

	smartphone->class_device = builder->get_class_device();
	smartphone->camera = builder->get_camera();
	smartphone->count_camera = builder->get_count_camera();
	smartphone->cpu = builder->get_cpu();
	smartphone->memory = builder->get_memory();
	smartphone->storage = builder->get_storage();
	smartphone->price = builder->get_price();

	return smartphone;
}

string Builder_Flagship_smartphone::get_class_device()
{
	return "Flagman";
}

int Builder_Flagship_smartphone::get_camera() 
{
	return 108;
}

int Builder_Flagship_smartphone::get_count_camera()
{
	return 4;
}

string Builder_Flagship_smartphone::get_cpu()
{
	return "Qualcomm Snapdragon 8 Gen 1";
}

int Builder_Flagship_smartphone::get_memory()
{
	return 12;
}

int Builder_Flagship_smartphone::get_storage()
{
	return 512;
}

int Builder_Flagship_smartphone::get_price()
{
	return 1200;
}

string Builder_Sub_flagship_smartphone::get_class_device()
{
	return "Sub-Flagman";
}

int Builder_Sub_flagship_smartphone::get_camera()
{
	return 64;
}

int Builder_Sub_flagship_smartphone::get_count_camera()
{
	return 3;
}

string Builder_Sub_flagship_smartphone::get_cpu()
{
	return "Qualcomm Snapdragon 785G";
}

int Builder_Sub_flagship_smartphone::get_memory()
{
	return 8;
}

int Builder_Sub_flagship_smartphone::get_storage()
{
	return 256;
}

int Builder_Sub_flagship_smartphone::get_price()
{
	return 750;
}

string Builder_Budget_smartphone::get_class_device()
{
	return "Budjet";
}

int Builder_Budget_smartphone::get_camera()
{
	return 48;
}

int Builder_Budget_smartphone::get_count_camera()
{
	return 2;
}

string Builder_Budget_smartphone::get_cpu()
{
	return "MediaTek Dimensity 1200";
}

int Builder_Budget_smartphone::get_memory()
{
	return 4;
}

int Builder_Budget_smartphone::get_storage()
{
	return 64;
}

int Builder_Budget_smartphone::get_price()
{
	return 250;
}
