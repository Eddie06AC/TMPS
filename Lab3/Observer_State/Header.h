#ifndef HEADER_H_
#define HEADER_H_
#include<iostream>
#include <list>]
#include<ctime>

using namespace std;

class Payment
{
public:
    virtual void pay(int& sum_items) = 0;
    virtual const char* get_text_payment() = 0;
};

class Cash : public Payment
{
public:
    void pay(int& sum_items);
    const char* get_text_payment();
};

class Credit_card : public Payment
{
private:
    Cash* cash;
public:
    void discount(int& sum_items);
    void pay(int& sum_items);
    Credit_card(Cash* cash) : cash(new Cash(*cash)) {};
    ~Credit_card() { delete cash; };
    const char* get_text_payment();
};

class Client
{
private:
    int sum_items;
    Payment* payment_method;
    int bonus_card;
public:
    Client(int sum_items, Payment* payment_method, int bonus_card);
    void add(Client** array);
    int get_sum_items();
    void set_sum_items(int sum_items);
    void pay_client() { payment_method->pay(sum_items); };
    const char* get_payment_method() { return payment_method->get_text_payment(); };
    int get_bonus_card();
};

class State;

class Ñash_register
{
public:
    virtual  void reset() = 0;
    virtual  int getflag() = 0;
    virtual  void setflag(int available) = 0;
    virtual  int getmax_people() = 0;
    virtual   void setmax_people(int max_people) = 0;
    virtual   string getname() = 0;
    virtual   void setname(string name) = 0;
    virtual   void Get_stats() = 0;
    virtual   int get_served() = 0;
    virtual   void set_served(int served) = 0;
    virtual   int get_card() = 0;
    virtual  void set_card(int card) = 0;
    virtual  int get_cash() = 0;
    virtual  void set_cash(int cash) = 0;
    virtual  int get_profit() = 0;
    virtual  void set_profit(int profit, Client* mas, int money, float rate) = 0;
    virtual void set_state(State* state) = 0;
};

class ObjectPool;

class State
{
public:
    virtual void set_pool(ObjectPool* pool) = 0;
    virtual void do_Business(Ñash_register* other, Client** mas, int length, int flagg[], float rate) = 0;
    virtual ~State() {};
};

class Ñash_register_Simple : public Ñash_register
{
private:
    string name;
    int max_people;
    int available;
    int served;
    int card;
    int cash;
    int profit;
    State* state;

public:
    Ñash_register_Simple();
    Ñash_register_Simple(string name, int max_people);
    void reset();
    int getflag();
    void setflag(int available);
    int getmax_people();
    void setmax_people(int max_people);
    string getname();
    void setname(string name);
    void Get_stats();
    int get_served();
    void set_served(int served);
    int get_card();
    void set_card(int card);
    int get_cash();
    void set_cash(int cash);
    int get_profit();
    void set_profit(int profit, Client* mas, int money, float rate);
    void set_state(State* state) { this->state = state; };

};

class Ñash_register_Decorator :public Ñash_register
{
public:
    Ñash_register_Decorator(Ñash_register* decorated_cash_register)
    {
        this->decorated_cash_register = decorated_cash_register;
    }

protected:
    Ñash_register* decorated_cash_register;

};

class Ñash_register_Bonus_card : Ñash_register_Decorator
{
    // Áîíóñíàÿ êàðòà- åñëè åñòü ó ÷åëîâåêà!
    // rand( 1 or 2 ) - åñëè 1 òî ó ÷åëîâåêà åñòü áîíóñíûå ïðîäóêòû 
    // Åñëè åñòü áîíóñíàÿ êàðòà è rand âåðíóë 1 -> 10% ñêèäêà...
private:
    State* state;
public:
    Ñash_register_Bonus_card(Ñash_register* decorated_cash_register) :
        Ñash_register_Decorator(decorated_cash_register) {};
    void reset();
    int getflag();
    void setflag(int available);
    int getmax_people();
    void setmax_people(int max_people);
    string getname();
    void setname(string name);
    void Get_stats();
    int get_served();
    void set_served(int served);
    int get_card();
    void set_card(int card);
    int get_cash();
    void set_cash(int cash);
    int get_profit();
    void set_profit(int profit, Client* mas, int money, float rate);
    void set_state(State* state) { this->state = state; };
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
    //void handler_queue(Ñash_register* other, int number, int flagg[]);
    void handler(Ñash_register* other, Client** mas, int length, int flagg[], float rate);

};

class EventHandler
{
public:
    virtual float update(int rate) = 0;
};

class EventGenerator
{
private:
    EventHandler* Event;
public:
    void addEvent(EventHandler* other)
    {
        Event = other;
    }
    float generate(int rate)
    {
        return Event->update(rate);
    }
};

class UP_DOWN_price : public EventHandler
{
public:
    float update(int rate)
    {      /////////    ÎÁÀ ×ÈÑËÀ ÎÄÈÍÀÊÎÂÛÅ (åñëè âíèç öåíà ïðè t=0, òîãäà è ïîâûøåíèå öåíû òîæå áóäåò ïðè t=0)
        int t, t1;
        switch (rate)
        {
        case 0: t = rand() % 3;
            if (t == 0)
                return 0.075f;
            else if (t == 1)
                return 0.05f;
            else
                return 0.1f;

        case 1: t1 = rand() % 3;
            if (t1 == 0)
                return -0.05f;
            else if (t1 == 1)
                return -0.025f;
            else
                return -0.075f;
        }
    }
};


class Handle_clients : public State
{
public:
    ObjectPool* pool;
    Handle_clients() : pool(0) {};
    void set_pool(ObjectPool* pool)
    {
        this->pool = pool;
    }
    void do_Business(Ñash_register* other, Client** mas, int length, int flagg[], float rate)
    {
        this->pool->handler(other, mas, length, flagg, rate);
    }
    ~Handle_clients() { delete pool; }
};

class Recalculation : public State
{
public:
    ObjectPool* pool;
    Recalculation() : pool(0) {};
    void set_pool(ObjectPool* pool)
    {
        this->pool = pool;
    }
    void do_Business(Ñash_register* other, Client** mas, int length, int flagg[], float rate)
    {
        cout << "   Preliminary results of cash register - " << other->getname() << " requested by the server...." << endl;
        cout << "   All actions with cash register - " << other->getname() << " are stopped!" << endl;
        other->Get_stats();
    }
    ~Recalculation() { delete pool; }
};

#endif // !HEADER_H_

