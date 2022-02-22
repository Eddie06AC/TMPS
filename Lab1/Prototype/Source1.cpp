#include"Header.h"

Dekanat::Dekanat(string group, string faculty, int year, float mark) 
{
	this->group = group;
	this->faculty = faculty;
	this->year=year;
	this->mark = mark;
}

void Dekanat::set_mark(float mark) { this->mark = mark; }

float Dekanat::get_mark() const { return this->mark; } 

void Dekanat::set_group(string group) { this->group = group; }

string Dekanat::get_group() { return this->group; } 

Dekanat* Student::clone() const
{
	 return new Student(*this);
}

Student::Student(string group, string faculty,
	int year, float mark, string first_last_name, string subject)
	:Dekanat(group, faculty, year, mark)
{
	this->first_last_name = first_last_name;
	this->subject = subject;
}

float Student::avg_mark(Dekanat **array) const
{
	float res = 0;
	int length = 0;
	for (int i = 0;array[i]; i++)
	{
		res += array[i]->get_mark();
		length++;
	}
	return res /= length;
}

void Student::set_first_last_name(string first_last_name) { this->first_last_name = first_last_name; }

string Student::get_first_last_name() { return this->first_last_name; }

void Student::add(Dekanat** array) 
{
	int n = 10;
	for (int i = 0; i < n; i++)
	{
		if (array[i] == nullptr)
		{
			array[i] = this;
			break;
		}
	}
}

Predmet::Predmet(string group, string faculty, int year, float mark, string name) 
				:Dekanat(group,faculty,year,mark)
{
	this->name = name;
}

Dekanat* Predmet::clone() const
{
	return new Predmet(*this);
}

float Predmet::avg_mark(Dekanat** array) const
{
	float res = 0;
	int length = 0;
	for (int i = 0; array[i]; i++)
	{
		res += array[i]->get_mark();
		length++;
	}
	return res /= length;
}

void Predmet::add(Dekanat** array) 
{
	int n = 10;
	for (int i = 0; i < n; i++)
	{
		if (array[i] == nullptr)
		{
			array[i] = this;
			break;
		}
	}
}