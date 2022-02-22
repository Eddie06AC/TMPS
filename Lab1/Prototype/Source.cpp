/*Программа рассчитана на подсчет среднего значения оценки по предмету среди студентов одной группы.
* Можно создавать студентов(объекты), можно их клонировать(и менять 2 поля, к примеру оценка и имя_фамилия.
После чего они добавляются в массив(группу студентов), которая передается в метод для подсчета среднего
значения. Также есть класс "Предметы", которые также создаются и колнируются и можно посчиать средний балл
предмета по группам)
*/

#include"Header.h"
#include<iostream>

using namespace std;

int main() 
{
	Dekanat* mas_stud[10];
	for ( int i = 0; i < 10; i++)
	{
		mas_stud[i] = 0;
	}
	Dekanat* mas_predmet[10];
	for (int i = 0; i < 10; i++)
	{
		mas_predmet[i] = 0;
	}
	Student* a= new Student("TI-196","FCIM",3, 9.5f,"Eduard Turcan","TMPS");
	Student* b =(Student*) a->clone();
	if (a == b)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	cout << "First instance " << a << endl;
	cout << "Second instance(clone) " << b <<endl;
	b->set_mark(7.9f);
	b->set_first_last_name("Ivanov Ivan");
	Student* c = new Student("TI-196", "FCIM", 3, 8.2f, "Petrov Petr", "TMPS");
	a->add(mas_stud);
	b->add(mas_stud);
	c->add(mas_stud);
	float result_students = a->avg_mark(mas_stud);
	cout << "Average result between students " << a->get_first_last_name() <<", "
		 <<b->get_first_last_name() <<", "<<c->get_first_last_name() <<" = ";
	cout << result_students << endl;
	/// ///////////////////////////////////////////////////////////////////////////////////////
	Predmet* x = new Predmet("TI-196", "FCIM", 3, 8.8f, "TMPS");
	Predmet* y = (Predmet*) x->clone();
	y->set_mark(6.7f);
	y->set_group("TI_195");
	Predmet* z = new Predmet("TI-197", "FCIM", 3, 7.9f, "TMPS");
	x->add(mas_predmet);
	y->add(mas_predmet);
	z->add(mas_predmet);
	float result_group = x->avg_mark(mas_predmet);
	cout <<"Average result of groups "<<x->get_group()<<" "<< y->get_group()
		 <<" "<< z->get_group()<<" = ";
	cout << result_group << endl;

	return 0;
}