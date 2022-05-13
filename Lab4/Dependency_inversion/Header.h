#ifndef HEADER
#define HEADER
#include<iostream>
using namespace std;

class File
{
public:
	virtual string get_type() = 0;
	virtual int get_size() = 0;
};

class Sound_file : public File
{
public:
	string get_type()
	{
		return "sound file";
	}
	int get_size()
	{
		return 8;
	}
};

class Video_file : public File
{
public:
	string get_type()
	{
		return "video file";
	}
	int get_size()
	{
		return 125;
	}
};

class Photo_file : public File
{
public:
	string get_type()
	{
		return "photo file";
	}
	int get_size()
	{
		return 25;
	}
};

class Storage
{
public:
	virtual string find_file_system() = 0;
	virtual float speed_time(int f_size) = 0;
};

class Hard_disk : public Storage
{
public:
	string find_file_system()
	{
		return "NTFS";
	}
	float speed_time(int f_size) 
	{
		return f_size / (float) speed;
	}
	int speed = 10;
};

class Flash_disk : public Storage
{
public:
	string find_file_system()
	{
		return "FAT32";
	}
	float speed_time(int f_size)
	{
		return f_size / (float) speed;
	}
	int speed = 4;

};

class Save_file
{
public:
	void saving(File* f, Storage* s)
	{
		string f_type = f->get_type();
		int f_size = f->get_size();
		string file_system_type = s->find_file_system();
		float speed_sec = s->speed_time(f_size);
		cout << "Time to save " << f_type << " with size " << f_size << "MB on file system - " << file_system_type << " is " << speed_sec << " sec" << endl;
	}
};

#endif // !HEADER
