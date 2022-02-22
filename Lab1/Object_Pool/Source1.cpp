#include"Header.h"
#include<iostream>
#include<list> 
#include <Windows.h>

using namespace std;

�ash_register::�ash_register(): name(0) , max_people(1), available(1){}

�ash_register::�ash_register(string name, int max_people) : available(1) { this->name = name; this->max_people = max_people; }

void �ash_register::reset()
{
    available = 1;
}
int �ash_register::getflag() { return available; }

void �ash_register::setflag(int available)
{
    this->available = available;
}

int �ash_register::getmax_people() { return max_people; }
void �ash_register::setmax_people (int max_people)
{
    this->max_people = max_people;
}

string �ash_register::getname() { return name; }

void �ash_register::setname(string name)
{
    this->name = name;
}

void ObjectPool::handler_queue(�ash_register* other,int number,int flagg[])
{
    int a = other->getmax_people();
    if (a >= number) 
    {
        cout << "The queue of " << a << " people is processed by " << other->getname() << " cash register." << endl;
        flagg[0] = 0;
        Sleep(number * 1000);
        this->return�ash_register(other);
    }
    else 
    {
        cout << "The queue of "<< a <<" people is processed by " << other->getname() << " cash register." << endl;
        flagg[0] = 1;
        flagg[1] = abs(a - number); 
        cout << "Attention!!!!!!\nThe queue is full, need to open another cash register to serve the remaining "<< flagg[1]<<" people" << endl;
    }
}

ObjectPool* ObjectPool::instance = 0;

ObjectPool* ObjectPool::getInstance()
{
    if (instance == 0)
    {
        instance = new ObjectPool;
    }
    return instance;
}

�ash_register* ObjectPool::get�ash_register(�ash_register* other)
{
    if (created_cash_registers.empty())
    {
        std::cout << "Creating new." << std::endl;
        other->setflag(0);
       // return new �ash_register;
        return other;
    }
    else
    {
        std::cout << "Reusing existing." << std::endl;
        �ash_register* created_cash_register = created_cash_registers.front();
        created_cash_registers.pop_front();
        other->setflag(0);
        return created_cash_register;
    }
}

void ObjectPool::return�ash_register(�ash_register* object)
{
    object->reset();
    created_cash_registers.push_back(object);
}

