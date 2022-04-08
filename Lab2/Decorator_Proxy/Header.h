#ifndef HEADER_H_
#define HEADER_H_
#include<iostream>
#include <list>

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

class —ash_register
{
public:
    virtual  void reset() = 0;
    virtual  int getflag()=0;
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
    virtual  void set_profit(int profit, Client* mas, int money) = 0;
};

class —ash_register_Simple : public —ash_register
{
private:
    string name;
    int max_people;
    int available;
    int served;
    int card;
    int cash;
    int profit;

public:
    —ash_register_Simple();
    —ash_register_Simple(string name, int max_people);
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
    void set_profit(int profit, Client* mas, int money);

};

class —ash_register_Decorator :public —ash_register 
{ 
public:
    —ash_register_Decorator(—ash_register* decorated_cash_register) 
    {
        this->decorated_cash_register=decorated_cash_register;
    }

protected:
    —ash_register* decorated_cash_register;
   
};

class —ash_register_Bonus_card : —ash_register_Decorator
{
    // ¡ÓÌÛÒÌ‡ˇ Í‡Ú‡- ÂÒÎË ÂÒÚ¸ Û ˜ÂÎÓ‚ÂÍ‡!
    // rand( 1 or 2 ) - ÂÒÎË 1 ÚÓ Û ˜ÂÎÓ‚ÂÍ‡ ÂÒÚ¸ ·ÓÌÛÒÌ˚Â ÔÓ‰ÛÍÚ˚ 
    // ≈ÒÎË ÂÒÚ¸ ·ÓÌÛÒÌ‡ˇ Í‡Ú‡ Ë rand ‚ÂÌÛÎ 1 -> 10% ÒÍË‰Í‡...
public:
    —ash_register_Bonus_card(—ash_register* decorated_cash_register) : 
        —ash_register_Decorator(decorated_cash_register) {};
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
    void set_profit(int profit, Client* mas, int money);
};





class ObjectPool
{
private:
    list<—ash_register*> created_cash_registers;
    static ObjectPool* instance;
    ObjectPool() {}
public:
    static ObjectPool* getInstance();
    —ash_register* get—ash_register(—ash_register* other);
    void return—ash_register(—ash_register* object);
    //void handler_queue(—ash_register* other, int number, int flagg[]);
    void handler(—ash_register* other, Client** mas, int length, int flagg[]);

};




#endif // !HEADER_H_

