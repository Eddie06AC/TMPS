#include"Header.h"
#include<iostream>
#include<list> 
#include <Windows.h>

using namespace std;

Ñash_register::Ñash_register(): name(0) , max_people(1), available(1){}

Ñash_register::Ñash_register(string name, int max_people) : available(1) { this->name = name; this->max_people = max_people; }

void Ñash_register::reset()
{
    available = 1;
}
int Ñash_register::getflag() { return available; }

void Ñash_register::setflag(int available)
{
    this->available = available;
}

int Ñash_register::getmax_people() { return max_people; }
void Ñash_register::setmax_people (int max_people)
{
    this->max_people = max_people;
}

string Ñash_register::getname() { return name; }

void Ñash_register::setname(string name)
{
    this->name = name;
}

void ObjectPool::handler_queue(Ñash_register* other,int number,int flagg[])
{
    int a = other->getmax_people();
    if (a >= number) 
    {
        cout << "The queue of " << a << " people is processed by " << other->getname() << " cash register." << endl;
        flagg[0] = 0;
        Sleep(number * 1000);
        this->returnÑash_register(other);
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

Ñash_register* ObjectPool::getÑash_register(Ñash_register* other)
{
    if (created_cash_registers.empty())
    {
        std::cout << "Creating new." << std::endl;
        other->setflag(0);
       // return new Ñash_register;
        return other;
    }
    else
    {
        std::cout << "Reusing existing." << std::endl;
        Ñash_register* created_cash_register = created_cash_registers.front();
        created_cash_registers.pop_front();
        other->setflag(0);
        return created_cash_register;
    }
}

void ObjectPool::returnÑash_register(Ñash_register* object)
{
    object->reset();
    created_cash_registers.push_back(object);
}

