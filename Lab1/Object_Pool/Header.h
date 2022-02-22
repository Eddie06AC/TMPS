#ifndef HEADER_H_
#define HEADER_H_
#include<iostream>
#include <list>

using namespace std;

class �ash_register
{
private:
    string name;
    int max_people;
    int available;

public:
    �ash_register();
    �ash_register(string name, int max_people);
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
    list<�ash_register*> created_cash_registers;
    static ObjectPool* instance;
    ObjectPool() {}
public:
    static ObjectPool* getInstance();
    �ash_register* get�ash_register(�ash_register* other);
    void return�ash_register(�ash_register* object);
    void handler_queue(�ash_register* other,int number, int flagg[]);
   
};


#endif // !HEADER_H_

