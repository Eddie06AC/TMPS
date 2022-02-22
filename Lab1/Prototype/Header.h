#ifndef HEADER_H_
#define HEADER_H_
#include<iostream>

using namespace std;

class Dekanat 
{
private:	
	string group;
	string faculty;
	int year;
	float mark;
public:
	Dekanat(string group, string faculty, int year, float mark);
	virtual Dekanat* clone() const = 0;
	virtual float avg_mark(Dekanat** array) const = 0;
	float get_mark() const;
	void set_mark(float mark);
	void set_group(string group);
	string get_group();
};

class Student :public Dekanat
{
	string first_last_name;
	string subject;
public:
	Student(string group, string faculty, int year, float mark, string first_last_name, string subject);
	virtual Dekanat* clone() const override;
	virtual float avg_mark(Dekanat** array) const override;
	void set_first_last_name(string first_last_name);
	string get_first_last_name();
	void add(Dekanat** array);
};

class Predmet :public Dekanat
{
	string name;
public:
	Predmet(string group, string faculty, int year, float mark, string name);
	virtual Dekanat* clone() const override;
	virtual float avg_mark(Dekanat** array) const override;
	void add(Dekanat** array);
};

#endif HEADER_H_
