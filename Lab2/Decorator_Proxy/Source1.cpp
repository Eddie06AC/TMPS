#include"Header.h"
#include<iostream>
#include<list> 
#include <Windows.h>

using namespace std;

Ñash_register_Simple::Ñash_register_Simple() : name("name"), max_people(1), available(1), served(0), card(0), cash(0), profit(0) {}
Ñash_register_Simple::Ñash_register_Simple(string name, int max_people) : available(1), served(0), card(0), cash(0), profit(0) { this->name = name; this->max_people = max_people; }

void Ñash_register_Simple::reset() { available = 1; }
int Ñash_register_Simple::getflag() { return available; }

void Ñash_register_Simple::setflag(int available) { this->available = available; }

int Ñash_register_Simple::getmax_people() { return max_people; }
void Ñash_register_Simple::setmax_people(int max_people) { this->max_people = max_people; }

string Ñash_register_Simple::getname() { return name; }

void Ñash_register_Simple::setname(string name) { this->name = name; }

void Ñash_register_Simple::Get_stats()
{
    cout << "Stasts of cash register - " << this->getname() << "\nServed: " << this->served;
    cout << " number of people\nWith card served: " << this->card << " people\n";
    cout << "With cash served: " << this->cash << " people\n";
    cout << "Profit - " << this->profit << " lei" << endl;
}

int Ñash_register_Simple::get_served() { return this->served; }
void Ñash_register_Simple::set_served(int served) { this->served = served; }
int Ñash_register_Simple::get_card() { return this->card; }
void Ñash_register_Simple::set_card(int card) { this->card = card; }
int Ñash_register_Simple::get_cash() { return this->cash; }
void Ñash_register_Simple::set_cash(int cash) { this->cash = cash; }
int Ñash_register_Simple::get_profit() { return this->profit; }
void Ñash_register_Simple::set_profit(int profit, Client* mas, int money) { this->profit = profit; }


//////////////////////////////////////////////////////////////////////////////////////////////////

void Ñash_register_Bonus_card::reset() { decorated_cash_register->reset(); }
int Ñash_register_Bonus_card::getflag() {return decorated_cash_register->getflag(); }

void Ñash_register_Bonus_card::setflag(int available) { decorated_cash_register->setflag(available); }

int Ñash_register_Bonus_card::getmax_people() { return decorated_cash_register->getmax_people(); }
void Ñash_register_Bonus_card::setmax_people(int max_people) { decorated_cash_register->setmax_people(max_people); }

string Ñash_register_Bonus_card::getname() { return decorated_cash_register->getname(); }

void Ñash_register_Bonus_card::setname(string name) { decorated_cash_register->setname(name); }

void Ñash_register_Bonus_card::Get_stats()
{
    cout << "DECORATOR"<<endl;
    cout << "Stasts of cash register - " << this->getname() << "\nServed: " << decorated_cash_register->get_served();
    cout << " number of people\nWith card served: " << decorated_cash_register->get_card() << " people\n";
    cout << "With cash served: " << decorated_cash_register->get_cash() << " people\n";
    cout << "Profit - " << decorated_cash_register->get_profit() << " lei" << endl;
}

int Ñash_register_Bonus_card::get_served() { return decorated_cash_register->get_served(); }
void Ñash_register_Bonus_card::set_served(int served) { decorated_cash_register->set_served(served); }
int Ñash_register_Bonus_card::get_card() { return decorated_cash_register->get_card(); }
void Ñash_register_Bonus_card::set_card(int card) { decorated_cash_register->set_card(card); }
int Ñash_register_Bonus_card::get_cash() { return  decorated_cash_register->get_cash(); }
void Ñash_register_Bonus_card::set_cash(int cash) { decorated_cash_register->set_cash(cash); }
int Ñash_register_Bonus_card::get_profit() { return decorated_cash_register->get_profit(); }
void Ñash_register_Bonus_card::set_profit(int profit, Client* mas, int money)
{
    int p = mas->get_bonus_card();
    if (p == 1)
    {
        int lol = rand() % 2;
        if (lol == 1)
        {
            cout << "   Bonus card! Discount Bonus + 10%." << endl;
            money *= 0.9;
          
        }
    }  
    profit += money;
    cout << "Last Price - " << money << endl;
    decorated_cash_register->set_profit(profit, mas, money); 
}

//////////////////////////////////////////////////////////////////////////////////////////////////



void ObjectPool::handler(Ñash_register* other, Client** mas, int length, int flagg[])
{
    const char* tmp;
    int k = 0, l = 0;
    int a = other->getmax_people();
    int count = 0;
    int count_client = 0;
    for (int i = 0; i < length; i++)
    {
        if (mas[i] != nullptr)
        {
            count_client++;
        }
        else break;
    }
    while (count < a)
    {
        cout << flagg[2] << endl;
        for (flagg[2]; flagg[2] < count_client; flagg[2]++)
        {
            int served = other->get_served();
            int cash = other->get_cash();
            int card = other->get_card();
            int profit = other->get_profit();
            served += 1;
            mas[flagg[2]]->pay_client();
            tmp = mas[flagg[2]]->get_payment_method();
            if (strcmp("cash", tmp) == 0)
            {
                cash += 1;
            }
            else
                card += 1;
           //profit += mas[flagg[2]]->get_sum_items();
            int money = mas[flagg[2]]->get_sum_items();
            other->set_served(served);
            other->set_cash(cash);
            other->set_card(card);
            other->set_profit(profit, mas[flagg[2]], money); 
            //    ÈÑÏĞÀÂÈÒÜ, profit = âñå äåíüãè, à íàäî äåíüãè ñ ÷åëîâåêà
            count++;
            if (count >= a)
            {
                k = 1;
                l = flagg[2] + 1;
                break;
            }

        }
        if (k == 1)
            break;
        else if (flagg[2] == count_client)
        {
            k = 1;
        }
    }
    if (a > count)
    {
        flagg[0] = 0;
        //Sleep(number * 1000);
        this->returnÑash_register(other);
    }
    else if (k == 1 || a >= count)
    {
        if (l == count_client)
        {
            flagg[0] = 0;
            this->returnÑash_register(other);
        }
        else
        {
            cout << "The queue of " << count << " people is processed by " << other->getname() << " cash register." << endl;
            flagg[0] = 1;
            if (flagg[1] == 0)
            {
                flagg[1] = abs(a - count_client);
            }
            else
            {
                flagg[1] = abs(a - flagg[1]);
            }
            flagg[2] = l;
            cout << "Attention!!!!!!\nThe queue is full, need to open another cash register to serve the remaining " << flagg[1] << " people" << endl;
        }
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
        std::cout << "........................Creating new........................" << std::endl;
        other->setflag(0);
        // return new Ñash_register;
        return other;
    }
    else
    {
        std::cout << "........................Reusing existing........................" << std::endl;
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

void Cash::pay(int& sum_items)
{
    cout << "   Paid - " << sum_items << " Thank you for purchase." << endl;
}

const char* Cash::get_text_payment() { return "cash"; }

void Credit_card::discount(int& sum_items)
{
    cout << "   Paid by credit card with discount 5% - " << sum_items << endl;
    sum_items *= 0.95;
}

void Credit_card::pay(int& sum_items)
{
    this->discount(sum_items);
    cash->pay(sum_items);
}

const char* Credit_card::get_text_payment() { return "card"; }

Client::Client(int sum_items, Payment* payment_method, int bonus_card)
{
    this->sum_items = sum_items;
    this->payment_method = payment_method;
    this->bonus_card = bonus_card;
}

void Client::add(Client** array)
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

int Client::get_sum_items() { return this->sum_items; }

void Client::set_sum_items(int sum_items) { this->sum_items = sum_items; }

int Client::get_bonus_card() { return this->bonus_card; }