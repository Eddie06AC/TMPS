#ifndef HEADER_H_
#define HEADER_H_
#include<iostream>
#include <list>

using namespace std;

class Ñash_register
{
private:
    string name;
    int max_people;
    int available;

public:
    Ñash_register();
    Ñash_register(string name, int max_people);
    void reset();
    int getflag();
    void setflag(int available);
    int getmax_people();
    void setmax_people(int max_people); 
    string getname();
    void setname(string name);
};

class ObjectPool
{
private:
    list<Ñash_register*> created_cash_registers;
    static ObjectPool* instance;
    ObjectPool() {}
public:
    static ObjectPool* getInstance();
    Ñash_register* getÑash_register(Ñash_register* other);
    void returnÑash_register(Ñash_register* object);
    void handler_queue(Ñash_register* other,int number, int flagg[]);
   
};


#endif // !HEADER_H_

